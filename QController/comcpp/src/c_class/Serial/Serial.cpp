//
// Created by eleps on 01.04.19.
//

#include "Serial.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;
vector<std::string> Serial::paths;
Serial::Serial(const char *pathname, speed_t speed,LogCallback cb){
    try{
        begin();
        memset(&term, 0, sizeof(struct termios));
        std::string path(pathname);
        if(CheckFilename(path)){throw std::logic_error(std::string(__func__)+" Path exist"); }
        Serial::paths.push_back(path);
        fd = open(pathname, O_RDWR | O_NONBLOCK | O_NOCTTY | O_NDELAY);
        if (fd == -1) {throw std::logic_error(std::string(__func__)+" Path not opened"); }
        fcntl(fd, F_SETFL, 0);
        if(SetSpeed(speed)){throw std::logic_error(std::string(__func__)+" Speed not set"); }
        term.c_cflag |= (CREAD | CLOCAL);
        term.c_cflag &= ~CSIZE;
        term.c_cflag |= CS8;
        term.c_cflag &= ~CSTOPB;
        term.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
        term.c_iflag &= ~(INPCK);
        term.c_oflag &= ~OPOST;
        if (tcsetattr(fd, TCSANOW, &term) < 0) { throw std::logic_error(std::string(__func__)+" Flag not set"); }
        timeout.tv_sec  = 0;
        timeout.tv_usec = 500;
    }
    catch (exception& e) { cout << e.what() << endl; }
}
Serial::~Serial(){};
bool Serial::ReceiveByte(std::vector<uint8_t> data){
    std::lock_guard<std::mutex> lock(DataMut);
    uint8_t buf[1];
    int rdlen;
    memset(reinterpret_cast<void*> (buf), 0x00, sizeof(uint8_t));
    rdlen = read(fd,reinterpret_cast<void*> (buf), sizeof(uint8_t));
    if (rdlen==1){data.push_back(buf[0]); }
    return (rdlen==1)? true: false;
}
bool Serial::ReceiveArray(std::vector<uint8_t> *data){
    std::lock_guard<std::mutex> lock(DataMut);
    uint8_t buf[MaxLen];
    int rdlen;
    memset(reinterpret_cast<void*> (buf), 0x00, sizeof(uint8_t)*MaxLen);
    int res;
    FD_ZERO (&fs);
    FD_SET(fd, &fs);
    res = select ( fd+1 , &fs, NULL, NULL, &timeout );
    if ((res<= 0)){ return true;}
    if (FD_ISSET(fd, &fs)) {
        rdlen = read(fd, reinterpret_cast<void *> (buf), sizeof(uint8_t) * MaxLen);
        for (auto i = 0; i < rdlen; i++) {data->push_back(buf[i]); }
    }
    //printLog(DebugLog, static_cast<std::string>(__func__) + " answer, received bytes: "+ std::to_string(rdlen));
    return (rdlen>0)? false: true;
}
bool Serial::SendByte(std::vector<uint8_t> data){
    std::lock_guard<std::mutex> lock(DataMut);
    write(fd, data.data(), sizeof(uint8_t) * 1);
    return false;
}
bool Serial::SendArray(std::vector<unsigned char> data){
    std::lock_guard<std::mutex> lock(DataMut);
    write(fd, data.data(), sizeof(uint8_t) * data.size());
    return false;
}
bool Serial::SetSpeed(speed_t speed){
    std::lock_guard<std::mutex> lock(DataMut);
    if ((cfsetispeed(&term, speed) < 0) || (cfsetospeed(&term, speed) < 0)) {return true;}
    cur_speed=speed;
    return false;
}
bool Serial::CheckFilename(std::string path){
    for(unsigned int i=0; i<Serial::paths.size();i++){
        if(path.compare(Serial::paths.at(i))==0){
            cout<<"This UART is already used"<<endl;
            return true;
        }
    }
    return false;
}
bool Serial::begin(LogCallback cb) {
    setLogCallback(cb);
    printLog(DebugLog, static_cast<std::string>(__func__) + " Initialized");
    return false;
}