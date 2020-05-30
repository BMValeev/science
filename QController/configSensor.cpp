//
// Created by eleps on 12.02.20.
//

#include "configSensor.h"
#include <QCoreApplication>
#include "utils.h"
#include <QDebug>
bool configSensor::validate(QJsonObject config){return true;}
QString configSensor::charFactoryPath(){
    return QCoreApplication::applicationDirPath() + QDir::separator() + "factory.ini";
}