//
// Created by eleps on 24.05.19.
//

#ifndef VIDEORECORDER_PHYSICALINTERFACE_H
#define VIDEORECORDER_PHYSICALINTERFACE_H

#include <mutex>
#include <vector>
#include <thread>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include "defs.h"
#include "loggable.h"
using namespace std;
template <class T>
class PhysInterface: public Loggable {
public:
    static T & getInstance(std::string device);
    bool begin( LogCallback cb = printToCout);
    bool isInitialized() const { return mInit; }
private:
protected:
    PhysInterface(std::string device);
    ~PhysInterface();
    bool setSelfName(std::string name);
    static std::map<std::string,T*> Devices;
    std::string selfName;
    bool mInit=false;
};
class Something :public PhysInterface<Something>{

};

#endif //VIDEORECORDER_PHYSICALINTERFACE_H
