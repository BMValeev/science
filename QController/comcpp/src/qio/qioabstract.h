#ifndef QSERIALBASE_H
#define QSERIALBASE_H

#include <QLocalSocket>
#include <QSerialPort>

#include "qtlog/qloggableobject.h"
#include "qserialsettings.h"
#include "qiotransactionbase.h"

class QIOAbstract : public QtLog::QLoggableObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(int writeTimeout READ writeTimeout WRITE setWriteTimeout NOTIFY writeTimeoutChanged)
    Q_PROPERTY(int readInterval READ readInterval WRITE setReadInterval NOTIFY readIntervalChanged)

public:
    QIOAbstract(QIODevice * const device = nullptr,
                QObject* parent = nullptr,
                const QString prefix = "");
    ~QIOAbstract();

signals:
    void response(const QVector<uint8_t> data);
    void sending(const QVector<uint8_t> data);
    void error(const QString &s);
    void timeout(const QString &s);
    // Property signals
    void runningChanged(bool running);
    void writeTimeoutChanged(int writeTimeout);
    void readIntervalChanged(int readInterval);

public slots:
    void start();
    void stop();
    // Setters
    void setWriteTimeout(int writeTimeout);
    void setReadInterval(int readInterval);

public:
    // Getters
    const QIODevice& device() const { return *mDevice; }
    bool running() const { return mRunning; }
    int writeTimeout() const { return mWriteTimeout; }
    uint8_t* rxBuff() { return mRxBuff; }
    int readInterval() const { return mReadInterval; }

protected slots:
    void mSend(const QVector<uint8_t> &txData);

protected:
    QMutex mMutex;

private slots:
    void mOnReadyRead();
    void mOnSerialPortError(QSerialPort::SerialPortError error);
    void mOnLocalSocketError(QLocalSocket::LocalSocketError error);
    // Setters
    void setRunning(bool running);

private:
    QIODevice * const mDevice;
    QTimer mReadWatcher;
    bool mRunning;
    int mWriteTimeout;
    uint8_t mRxBuff[4096];
    int mReadInterval;

    friend class QIORequestResponse;

    // Helpers
    QSerialPort * asSerial() { return qobject_cast<QSerialPort*>(mDevice); }
    QLocalSocket * asSocket() { return qobject_cast<QLocalSocket*>(mDevice); }
};

#endif // QSERIALBASE_H
