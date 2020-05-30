#include "sccontrollerbase.h"

#include "qtlog/log.h"

SCControllerBase::SCControllerBase(QObject* parent, QString i2cFileName)
    : QObject(parent)
    , mWatcherCheckMessages(this)
    , mWatcherReadBonded(this)
    , mConnected(false)
    , mI2CFileName(i2cFileName)
    , mCTag("SCControl ==> ")
{
    // Initialize I2C connection to connection module (модуль связи)
    mConnModule = new ConnModule(mI2CFileName.toStdString(),
                                 QtLog::Log::logCallbackForHardware);
}

void SCControllerBase::start()
{
    qInfo(infoAppEvents())<< mCTag << "starting...";

    // Connect to mDeviceData signals
    makeConnections();

    // Set UUID
    qInfo(infoAppEvents()) << mCTag << "setting UUID";
    setUuid(static_cast<uint32_t>(SCDefs::DeviceTypes::ESU));

    // Set Name
    qInfo(infoAppEvents()) << mCTag << "setting Name";
    setName(STRING_NAME);

    // Initialize exchange card in bluetooth module
    initExchangeCard();

    // Set up watchers
    qInfo(infoAppEvents()) << mCTag << "setting up watch timers";
    connect(&mWatcherCheckMessages, &QTimer::timeout, this,
            &SCControllerBase::checkNewMessages);
    connect(&mWatcherReadBonded, &QTimer::timeout, this,
            &SCControllerBase::readBondedDevicesCount);
    mWatcherCheckMessages.start(CHECKMESSAGES_WATCH_INTERVAL_MS);
    mWatcherReadBonded.start(READBONDED_WATCH_INTERVAL_MS);

    setConnected(true);
    qInfo(infoAppEvents())<< mCTag << "started.";
}

void SCControllerBase::finish()
{
    qInfo(infoAppEvents())<< mCTag << "stopping...";

    // Terminate watcher
    qInfo(infoAppEvents()) << mCTag << "stopping watch timers";
    if (mWatcherCheckMessages.isActive())
        mWatcherCheckMessages.stop();

    // Terminate watcher
    if (mWatcherReadBonded.isActive())
        mWatcherReadBonded.stop();

    qInfo(infoAppEvents())<< mCTag << "stopped.";
}

void SCControllerBase::checkNewMessages()
{
    static int wrnFilterCounter = 0;
    std::map<uint16_t,std::vector<uint8_t>> answer;
    uint8_t result = mConnModule->readLastChangedValue(answer);
    processResult(result);

    if (result != OK_I2C) {
        wrnFilterCounter = wrnFilterCounter == CHECKMESSAGES_WATCH_WARNING_FILTERLIMIT-1? 0 : (wrnFilterCounter+1);
        if (wrnFilterCounter == CHECKMESSAGES_WATCH_WARNING_FILTERLIMIT-1) {
            qWarning()<< mCTag << "failed to read last changed values";
        }
    } else {
        for(auto const &recValue : answer) {
            processNewRecordValue(recValue.first,
                                  Utils::uint32FromQByteArray(
                                      QByteArray(reinterpret_cast<const char*>(recValue.second.data()),4)));
        }
    }
}

void SCControllerBase::setUuid(uint32_t uuid)
{
    uint8_t result = mConnModule->setUUID(uuid);
    processResult(result);

    if (result != OK_I2C)
        qWarning()<< mCTag << "failed to set UUID";
}

void SCControllerBase::setName(QString name)
{
    uint8_t result = mConnModule->setName(name.toStdString());
    processResult(result);

    if (result != OK_I2C)
        qWarning()<< mCTag << "failed to set Name";
}

void SCControllerBase::makeConnections()
{
    // Override this function and create all connections needed
    // Bluetooth - send to remote controller
    // Common
    connect(this,&SCControllerBase::launchBonding,
            this,&SCControllerBase::launchBondingImpl);
}

void SCControllerBase::initExchangeCard()
{
    qInfo(infoAppEvents())<< mCTag << "initializing exchange card";

    // Start initialization
    uint8_t result = mConnModule->startInit();
    processResult(result);

    if (result != OK_I2C) {
        qWarning()<< mCTag << "failed to start exchange card initialization";
        return;
    }

    // Iterate over card
    std::vector<uint8_t> buff;
    buff.reserve(20);
    for (auto& rec : *ExchangeCardBase::records) {
        buff.clear();
        rec.setValue(getRecordValueById(rec.id()));
        rec.serialize(buff);
        result = mConnModule->initRecord(buff);
        processResult(result);
        if (result != OK_I2C)
            qWarning() << mCTag << "failed to init exchange card record #" << rec.id();
    }

    // End initialization
    result = mConnModule->endInit();
    processResult(result);

    if (result != OK_I2C) {
        qWarning()<< mCTag << "failed to start connection module (end init cmd)";
        return;
    }

}

void SCControllerBase::readBondedDevicesCount()
{
    static int wrnFilterCounter = 0;
    uint8_t bondingCount;
    uint8_t result = mConnModule->checkBonding(bondingCount);
    processResult(result);

    if (result != OK_I2C) {
        wrnFilterCounter = wrnFilterCounter == READBONDED_WATCH_WARNING_FILTERLIMIT-1? 0 : (wrnFilterCounter+1);
        if (wrnFilterCounter == READBONDED_WATCH_WARNING_FILTERLIMIT-1) {
            qWarning()<< mCTag << "failed to read number of bonded devices";
        }
    } else
        setBondedDeviceCnt(bondingCount);
}

void SCControllerBase::launchBondingImpl(bool deleteOldBonding)
{
    uint8_t result = mConnModule->startBonding(deleteOldBonding);
    processResult(result);

    if (result != OK_I2C) {
        qWarning()<< mCTag << "failed to start bonding process";
        return;
    }

    return;
}

void SCControllerBase::setBondedDeviceCnt(int bondedDeviceCnt)
{
    if (mBondedDeviceCnt == bondedDeviceCnt)
        return;

    mBondedDeviceCnt = bondedDeviceCnt;
    emit bondedDeviceCntChanged(mBondedDeviceCnt);
}

void SCControllerBase::setConnected(bool connected)
{
    if (mConnected == connected)
        return;

    mConnected = connected;
    emit connectedChanged(mConnected);
}

void SCControllerBase::processResult(uint8_t result)
{
    setConnected(result == OK_I2C);
}


