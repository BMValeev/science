//
// Created by eleps on 12.02.20.
//

#ifndef MENUCAMERAFHD_CONFIGSENSOR_H
#define MENUCAMERAFHD_CONFIGSENSOR_H

#include "comcpp/src/baseConfig.h"

class configSensor: public BaseConfig {
public:
    configSensor(){}
    ~configSensor(){}
    bool validate(QJsonObject config) override;
    QString charFactoryPath() override;
private:

};


#endif //MENUCAMERAFHD_CONFIGSENSOR_H
