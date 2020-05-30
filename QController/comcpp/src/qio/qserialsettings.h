#ifndef QSERIALSETTINGS_H
#define QSERIALSETTINGS_H

#include <QString>
#include <QSerialPort>

class QSerialSettings
{
public:
    QSerialSettings() { }

    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;

    bool operator==(const QSerialSettings& b) const;
    bool operator!=(const QSerialSettings& b) const;
};

Q_DECLARE_METATYPE(QSerialSettings)

#endif // QSERIALSETTINGS_H
