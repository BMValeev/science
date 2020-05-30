//
// Created by eleps on 01.04.19.
//

#ifndef HARDWARECLASSES_SERIAL_H
#define HARDWARECLASSES_SERIAL_H
#include <mutex>
#include <vector>
#include <thread>
#include <functional>
#include <termios.h>
#include "../Rest/loggable.h"
#define CHECK_STATUS       1
#define CHECK_ERROR       2
#define ENABLE_CAMERA   3
#define DISABLE_CAMERA  4
#define START_RECORD    5
#define STOP_RECORD     6
#define MAKE_SNAPSHOT   7
#define RESTART_CAMERA   8
#define TEST1           9

using namespace std;
typedef std::function<void(uint8_t, std::string)> LogCallback;
enum Log_status { Info_log = 1, Debug_log=2, Warning_log= 3, Critical_log=4 };

using namespace std;
class Serial: public Loggable {
private:
    bool begin( LogCallback cb = printToCout);
public:
    Serial(const char *pathname, speed_t speed=B9600,LogCallback cb=nullptr);
    ~Serial();
    bool SetSpeed(speed_t speed);
    bool CheckFilename(std::string path);
    bool ReceiveByte(std::vector<uint8_t> data);
    bool ReceiveArray(std::vector<uint8_t> *data);
    bool SendByte(std::vector<uint8_t> data);
    bool SendArray(std::vector<uint8_t> data);
protected:
    int fd;
    fd_set fs;
    struct timeval timeout;
    struct termios term;
    unsigned int MaxLen=100;
    std::mutex DataMut;
    speed_t cur_speed;
    static vector<std::string> paths;
};
#endif //HARDWARECLASSES_SERIAL_H
