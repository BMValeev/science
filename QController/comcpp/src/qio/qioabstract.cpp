#include "qioabstract.h"

#include <QTime>

#include "../utils.h"

QIOAbstract::QIOAbstract(QIODevice * const device,
                         QObject *parent,
                         const QString prefix)
    : QLoggableObject(parent, prefix == ""? "QSerial --> " : prefix)
    , mDevice(device)
    , mReadWatcher(this)
    , mRunning(false)
    , mReadInterval(0)
{
    qRegisterMetaType<QVector<uint8_t>>("QVector<uint8_t>");

    mReadWatcher.setInterval(mReadInterval);
    connect(this, &QIOAbstract::readIntervalChanged, this, [=](int ms) { mReadWatcher.setInterval(ms); });
    connect(this, &QIOAbstract::runningChanged, this, [=](bool running) {
        if (running) mReadWatcher.start();
        else if (mReadWatcher.isActive()) mReadWatcher.stop();
    });
    connect(&mReadWatcher, &QTimer::timeout, this, &QIOAbstract::mOnReadyRead);

    connect(this, &QIOAbstract::error, this, [=](QString s) { wrn(s); });
    connect(this, &QIOAbstract::timeout, this, [=](QString s) { wrn(s); });

    if (!mDevice)
        qFatal("QSerialBase --> nullptr device!");

    // If it is Serial Port
    QSerialPort * const serial = asSerial();
    if (serial) {
        // QSerialPort is used as QIODevice
        connect(serial, &QSerialPort::errorOccurred, this, &QIOAbstract::mOnSerialPortError);
    }

    // If it is Local Socket
    QLocalSocket * const socket = asSocket();
    if (socket) {
        // QLocalSocket is used as QIODevice
        connect(socket, QOverload<QLocalSocket::LocalSocketError>::of(&QLocalSocket::error),
                this,   &QIOAbstract::mOnLocalSocketError);
    }
}

QIOAbstract::~QIOAbstract() { }

void QIOAbstract::start()
{
    // If it is already open
    if (mDevice->isOpen()) {
        setRunning(true);
        return;
    }

    const QMutexLocker locker(&mMutex);

    if (mDevice->open(QIODevice::ReadWrite)) {
        setRunning(true);
    } else {
        QSerialPort * const serial = asSerial();
        QLocalSocket * const socket = asSocket();

        if (serial) {
            emit error(tr("Can't open serial port \"%1\", error code %2, error string - %3")
                       .arg(serial->portName()).arg(serial->error()).arg(serial->errorString()));
        } else if (socket) {
            emit error(tr("Can't open local socket \"%1\", error code %2, error string - %3")
                       .arg(socket->serverName()).arg(socket->error()).arg(socket->errorString()));
        }
    }
}

void QIOAbstract::stop()
{
    if (mDevice->isOpen()) mDevice->close();
    setRunning(false);
}

void QIOAbstract::setRunning(bool running)
{
    if (mRunning == running)
        return;

    mRunning = running;
    emit runningChanged(mRunning);
}

void QIOAbstract::setWriteTimeout(int writeTimeout)
{
    if (mWriteTimeout == writeTimeout)
        return;

    mWriteTimeout = writeTimeout;
    emit writeTimeoutChanged(mWriteTimeout);
}

void QIOAbstract::setReadInterval(int readInterval)
{
    if (mReadInterval == readInterval)
        return;

    mReadInterval = readInterval;
    emit readIntervalChanged(mReadInterval);
}

void QIOAbstract::mSend(const QVector<uint8_t> &txData)
{
    if (!mDevice->isOpen()) {
        wrn("can't send commands - the port is closed");
        return;
    }

    const QMutexLocker locker(&mMutex);

    const QByteArray txBytes(reinterpret_cast<const char*>(txData.toStdVector().data()), static_cast<int>(txData.size()));

    emit sending(txData);

    // inf("mSend = " + txBytes.toHex(':'));

    mDevice->write(txBytes);
    if (!mDevice->waitForBytesWritten(mWriteTimeout)) {
        // Tx timeout
        emit timeout(tr("write timeout %1")
                     .arg(QTime::currentTime().toString()));
    }
}

void QIOAbstract::mOnReadyRead()
{
    if (!mDevice->isOpen())
        return;

    // Read data
    QByteArray respDataChar = mDevice->readAll();

    if (respDataChar.isEmpty())
        return;

    QVector<uint8_t> vec = Utils::qvectorFromQByteArray<uint8_t>(respDataChar);
    emit response(vec);
}

void QIOAbstract::mOnSerialPortError(QSerialPort::SerialPortError e)
{
    QSerialPort * const serial = asSerial();

    if (e == QSerialPort::NoError)
        return;

    if (e == QSerialPort::TimeoutError) {
        // The timeout error happens every time wait functions timeout
        if (serial) serial->clearError();
        return;
    }

    emit error(mDevice->errorString());
    if (serial) serial->clearError();
    stop();
}

void QIOAbstract::mOnLocalSocketError(QLocalSocket::LocalSocketError e)
{
    Q_UNUSED(e)
    emit error(mDevice->errorString());
    stop();
}
