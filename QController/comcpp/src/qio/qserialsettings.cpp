#include "qserialsettings.h"

bool QSerialSettings::operator==(const QSerialSettings &b) const
{
    return (name == b.name) &&
           (baudRate == b.baudRate) &&
           (stringBaudRate == b.stringBaudRate) &&
           (dataBits == b.dataBits) &&
           (stringDataBits == b.stringDataBits) &&
           (parity == b.parity) &&
           (stringParity == b.stringParity) &&
           (stopBits == b.stopBits) &&
           (stringStopBits == b.stringStopBits) &&
           (flowControl == b.flowControl) &&
           (stringFlowControl == b.stringFlowControl);
}

bool QSerialSettings::operator!=(const QSerialSettings &b) const
{
    return !(operator==(b));
}
