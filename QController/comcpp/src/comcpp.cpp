#include "comcpp.h"

#include <QDebug>
#include <QObject>
#include <QQmlEngine>

#include "qtlog/log.h"
#include "smartcontrol/scdefs.h"
#include "smartcontrol/record.h"

void COMCPP::registerTypesToQt()
{
    qInfo() << " + register int8_t, int16_t, int32_t, uint32_t, uint16_t, uint32_t";
    qRegisterMetaType<int8_t>("int8_t");
    qRegisterMetaType<int16_t>("int16_t");
    qRegisterMetaType<int32_t>("int32_t");
    qRegisterMetaType<uint8_t>("uint8_t");
    qRegisterMetaType<uint16_t>("uint16_t");
    qRegisterMetaType<uint32_t>("uint32_t");

    qInfo() << " + register Record";
    qRegisterMetaType<Record>("Record");
    qInfo() << " + register Record stream operators";
    qRegisterMetaTypeStreamOperators<Record>("Record");

    // Register SCDefs
    qInfo() << " + register SCDefs";
    qmlRegisterUncreatableType<SCDefs>("scdefs",1,0, "SCDefs",
                                       QStringLiteral("SCDefs is used for Enums!"));

    QtLog::registerTypesToQt();
}
