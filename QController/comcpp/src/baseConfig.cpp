//
// Created by eleps on 10.01.20.
//
#include "utils.h"
#include "baseConfig.h"
#include <QDebug>
#include <QCoreApplication>
bool BaseConfig::init(){
    if (!initConfigFile(configPath(), configFactoryPath()))
        return false;


    return load();
}
bool BaseConfig::reset(){
    if (!Utils::removeFileOrDir(configPath()) )
        return false;

    if (!Utils::removeFileOrDir(charPath()))
        return false;

    return load();
}
int BaseConfig::version(){
    return mConfig.value("version").toInt(-1);
}
QString BaseConfig::configFactoryPath(){
    return ":/res/config-factory.json";
}
QString BaseConfig::configPath(){
    return QCoreApplication::applicationDirPath() + QDir::separator() + "config.json";
}
QString BaseConfig::charFactoryPath(){
    return ":/res/characteristics";
}
QString BaseConfig::charPath(){
    return QCoreApplication::applicationDirPath() + QDir::separator() + "characteristics";
}
QString BaseConfig::settingsPath() {
    return QCoreApplication::applicationDirPath() + QDir::separator() + "state.ini";
}
bool BaseConfig::initConfigFile(QString path, QString factoryPath){
    QFileInfo fi(path);
    // Check if there is already a configuration file, otherwise copy factory settings from resources
    if (!(fi.exists() && fi.isFile())) {
        if (!QFile::copy(factoryPath, path)) {
            qCritical("Config --> failed to copy the configuration file");
            return false;
        }
    }

    // Check access rights
    if (!Utils::correctPermissions(path)) {
        qCritical( "Config --> failed to set permissions" );
        return false;
    }

    return true;
}

bool BaseConfig::load(){
    return load(configPath());
}
bool BaseConfig::load(QString path){
    QFile configFile(path);

    if (!configFile.open(QFile::ReadWrite | QIODevice::Text)) {
        qCritical() << "Config --> failed to open JSon configuration file";
        return false;
    }

    QByteArray configData = configFile.readAll();

    QJsonParseError e;
    QJsonDocument jd(QJsonDocument::fromJson(configData, &e));

    if (e.error != QJsonParseError::NoError) {
        qCritical() << "Config --> failed to parse JSon configuration file, error - "
                    << e.errorString() << ", offset=" << e.offset;
        return false;
    }

    if (!jd.isObject()) {
        qCritical() << "Config --> json top level should be object";
        return false;
    }

    mConfig = jd.object();

    if (!validate(mConfig)) {
        qCritical() << "Config --> wrong json config structure";
        return false;
    }

    return true;
}

template<typename T>
QVector<T>& BaseConfig::getStaticVectorFromArray(QJsonArray array, bool& wasEmpty){
    static QVector<T> v;
    static bool initialized = false;
    if (!initialized) {
        // Check if jErrors is not empty
        if (array.isEmpty()) {
            wasEmpty = true;
            v.append(T());
        } else {
            wasEmpty = false;
            v = Utils::jsonArrayToVectorOf<T>(array);
        }
    }

    return v;
}

template<typename T>
QList<T>& BaseConfig::getStaticListFromArray(QJsonArray array, bool& wasEmpty){
    static QList<T> list;
    static bool initialized = false;
    if (!initialized) {
        // Check if jErrors is not empty
        if (array.isEmpty()) {
            wasEmpty = true;
            list.append(T());
        } else {
            wasEmpty = false;
            list = Utils::jsonArrayToListOf<T>(array);
        }
    }

    return list;
}
