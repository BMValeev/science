#ifndef COMCPP_H
#define COMCPP_H

#include <QString>
#include <QDebug>
#include <QQmlEngine>

namespace COMCPP {

    void registerTypesToQt();

    template<typename T>
    void typeRegister(QString name, QString uri="device") {
        qInfo() << " + register " << name;
        qmlRegisterType<T>(uri.toLocal8Bit().data(),1,0,name.toLocal8Bit().data());
    }

    template<typename T>
    void typeRegisterUncreatable(QString name, QString uri="device") {
        qInfo() << " + register " << name;
        qmlRegisterUncreatableType<T>(uri.toLocal8Bit().data(),1,0,name.toLocal8Bit().data(),
                                      name + " should not be created in QML");
    }
}

#endif // COMCPP_H
