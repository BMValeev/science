QT += quickcontrols2
QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/../../src

SOURCES += \
    comcpp.cpp \
    mqtextstream.cpp \
    qqmlreadonlypropertymap.cpp \
    lineeditor/spline.cpp \
    lineeditor/linefile.cpp \
    lineeditor/basecurve.cpp \
    lineeditor/splinecurve.cpp \
    smartcontrol/exchangecardbase.cpp \
    smartcontrol/cardsdatabase.cpp \
    smartcontrol/sccontrollerbase.cpp \
    utils.cpp \
    persistent.cpp \
    failureHandling/failure.cpp \
    enumerables/qenumerablefloat.cpp \
    enumerables/qenumerableint.cpp \
    enumerables/qenumerablestring.cpp \
    smartcontrol/scdefs.cpp \
    smartcontrol/record.cpp \
    qtlog/log.cpp \
    qtlog/logfilemodel.cpp \
    qtlog/logmodel.cpp \
    qtlog/logmodelbase.cpp \
    qtlog/logsortfiltermodel.cpp \
    c_class/I2C/I2C.cpp \
    c_class/I2C/i2cpacket.cpp \
    c_class/I2C/charge.cpp \
    c_class/I2C/chargeinterface.cpp \
    c_class/I2C/BoardModule.cpp \
    c_class/I2C/ConnModule.cpp \
    c_class/I2C/stc3115_Driver.cpp \
    c_class/SPI/SPI.cpp \
    c_class/SPI/spipacket.cpp \
    c_class/SPI/MCU.cpp \
    c_class/Rest/crc.cpp \
    c_class/Rest/loggable.cpp \
    c_class/Backlight/screenlight.cpp \
    c_class/Backlight/backlightinterface.cpp \
    c_class/Backlight/backlight_pwm.cpp \

HEADERS += \
    comcpp.h \
    mqtextstream.h \
    qqmlreadonlypropertymap.h \
    lineeditor/spline.h \
    lineeditor/linefile.h \
    lineeditor/basecurve.h \
    lineeditor/splinecurve.h \
    smartcontrol/exchangecardbase.h \
    smartcontrol/cardsdatabase.h \
    smartcontrol/sccontrollerbase.h \
    utils.h \
    persistent.h \
    failureHandling/failure.h \
    enumerables/qenumerablefloat.h \
    enumerables/qenumerableint.h \
    enumerables/qenumerablestring.h \
    smartcontrol/scdefs.h \
    smartcontrol/record.h \
    qtlog/log.h \
    qtlog/logfilemodel.h \
    qtlog/logmodel.h \
    qtlog/logmodelbase.h \
    qtlog/logsortfiltermodel.h \
    c_class/I2C/I2C.h \
    c_class/I2C/i2cpacket.h \
    c_class/I2C/charge.h \
    c_class/I2C/chargeinterface.h \
    c_class/I2C/BoardModule.h \
    c_class/I2C/ConnModule.h \
    c_class/I2C/stc3115_Battery.h \
    c_class/I2C/stc3115_Driver.h \
    c_class/SPI/SPI.h \
    c_class/SPI/spipacket.h \
    c_class/SPI/MCU.h \
    c_class/Rest/crc.h \
    c_class/Rest/defs.h \
    c_class/Rest/loggable.h \
    c_class/Backlight/screenlight.h \
    c_class/Backlight/backlightinterface.h \
    c_class/Backlight/backlight_pwm.h \

# Default rules for deployment.
TARGET = comcpp
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
