//
// Created by eleps on 10.01.20.
//

#ifndef MENUCAMERAFHD_CONFIG_H
#define MENUCAMERAFHD_CONFIG_H
#include <QSettings>
#include <QFileInfo>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class BaseConfig {
public:
    BaseConfig(){}
    ~BaseConfig(){}
    bool init();
    // Reset config file to factory settings (if it has been changed)
    bool reset();
    // Getters
    // Config version as integer
    int version();
    virtual QString charFactoryPath();
    // Characteristics folder path
    virtual QString charPath();
    // Characteristics folder factory path
    virtual QString configFactoryPath();
    // Characteristics folder path
    virtual QString configPath();
    // Main settings file path
    virtual QString settingsPath();
    // Profiles file path
    // Get mode description
    virtual bool validate(QJsonObject config)=0; // validate contents of the config document
    bool load();
    bool load(QString path);

private:
    QJsonObject mConfig;
    // Helpers
    bool initConfigFile(QString path, QString factoryPath);
    template<typename T>
    QVector<T>& getStaticVectorFromArray(QJsonArray array, bool& wasEmpty);
    template<typename T>
    QList<T>& getStaticListFromArray(QJsonArray array, bool& wasEmpty);

};


#endif //MENUCAMERAFHD_CONFIG_H
