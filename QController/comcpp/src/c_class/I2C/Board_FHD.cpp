//
// Created by eleps on 29.04.19.
//

#include "Board_FHD.h"
#include "I2C.h"
Board_fhd::Board_fhd(std::string filename, LogCallback cb)
        : I2CPacket(filename, BOARD_FHD_MODULE_ADDRESS, cb) {
    I2C &i2c = I2C::getInstance();
    i2c.begin(filename);
}
// Commands
uint8_t Board_fhd::getStatus(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts ){
    uint8_t r = send(GET_STATUS, data, response, 3, attempts); std::ignore = r;
    if (response.size()!=3) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==0x33) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        response.erase(response.begin());
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Board_fhd::setLED(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts ){
    uint8_t r = send(SET_LED, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==0x33) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        data.erase(data.begin());
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
