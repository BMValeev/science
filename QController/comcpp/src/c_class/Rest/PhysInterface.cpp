//
// Created by eleps on 24.05.19.
//

#include "PhysInterface.h"
//std::map<std::string,T*> T::Devices{};
bool T::begin(LogCallback cb) {
    setLogCallback(cb);
    printLog(DebugLog, static_cast<std::string>(__func__) + " Initialized");
    return false;
}
T& T::getInstance(std::string device) {
    auto it=T::Devices.find(device);
    if(it==Devices.end()){
        Devices[device]=new T(device);
        return *T::Devices.find(device)->second;
    }
    return *T::Devices.find(device)->second;
}
T::T(std::string device)
        : Loggable () {
    printLog(DebugLog, static_cast<std::string>(__func__) + " Physical interface constructor called" );
    if (T::Devices.find(device)!=Devices.end()) throw std::logic_error("Instance already exists");
    Devices[device]=this;
    setSelfName(device);
    begin();
}
T::~T(){
    auto it=T::Devices.find(setSelfName);
    if(it!=Devices.end()){
        Devices.erase(it);
    }
}
bool T::setSelfName(std::string name){
    if(templateInit){return true;}
    setSelfName=name;
    return false;
}