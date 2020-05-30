#ifndef BLUETOOTHCONTROLLERBASE_H
#define BLUETOOTHCONTROLLERBASE_H

#include <QObject>
#include <QTimer>

#include "exchangecardbase.h"
#include "../c_class/I2C/I2C.h"
#include "../c_class/I2C/ConnModule.h"
#include "../types.h"
#include "../utils.h"
#include "scdefs.h"

#define READBONDED_WATCH_INTERVAL_MS 1000
#define READBONDED_WATCH_WARNING_INTERVAL_MS 5000
#define READBONDED_WATCH_WARNING_FILTERLIMIT READBONDED_WATCH_WARNING_INTERVAL_MS/READBONDED_WATCH_INTERVAL_MS
#define CHECKMESSAGES_WATCH_INTERVAL_MS 500
#define CHECKMESSAGES_WATCH_WARNING_INTERVAL_MS 5000
#define CHECKMESSAGES_WATCH_WARNING_FILTERLIMIT CHECKMESSAGES_WATCH_WARNING_INTERVAL_MS/CHECKMESSAGES_WATCH_INTERVAL_MS

#define STRING_NAME "ESU (ЭХВЧ)"

class SCControllerBase : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)
    Q_PROPERTY(int bondedDeviceCnt READ bondedDeviceCnt WRITE setBondedDeviceCnt NOTIFY bondedDeviceCntChanged)

public:
    explicit SCControllerBase(QObject* parent = nullptr,
                                     QString i2cFileName = "/dev/i2c-2");
    // Property getters
    bool connected() const { return mConnected; }    
    int bondedDeviceCnt() const { return mBondedDeviceCnt; }

public slots:
    void start();
    void finish();
    void checkNewMessages();
    void readBondedDevicesCount();
    // Can be called from qml
    void launchBondingImpl(bool deleteOldBonding);    
    void setBondedDeviceCnt(int bondedDeviceCnt);

signals:
    void launchBonding(bool deleteOldBonding);
    void connectedChanged(bool connected);
    void bondedDeviceCntChanged(int bondedDeviceCnt);

private:
    ConnModule* mConnModule;
    QTimer mWatcherCheckMessages;
    QTimer mWatcherReadBonded;
    bool mConnected;
    QString mI2CFileName;
    int mBondedDeviceCnt;

protected:
    const QString mCTag;

    // Helpers
    virtual void makeConnections();
    void initExchangeCard();
    void setUuid(uint32_t uuid);
    void setName(QString name);
    virtual int32_t getRecordValueById(uint16_t id) = 0; 
    void setConnected(bool connected);
    void processResult(uint8_t result);

    template<typename T>
    void processNewRecordValue(uint16_t id, T value)
    {
        Q_UNUSED(id)
        Q_UNUSED(value)
    }

    template<typename T>
    void sendRecordValue(uint16_t id, T value)
    {
        Record* rec = ExchangeCardBase::get(id);

        if (!rec) return;

        rec->setValue(value);
        std::vector<uint8_t> buff;
        rec->serializeIdValue(buff);
        int res = mConnModule->writeValue(rec->id(),std::vector<uint8_t>(&buff[2],&buff[6]));
        if (res != OK_I2C)
            qWarning() << mCTag << "failed to write record with id=" << id;
    }

};

typedef QSharedPointer<SCControllerBase> BluetoothControllerBasePtr;

#endif // BLUETOOTHCONTROLLERBASE_H
