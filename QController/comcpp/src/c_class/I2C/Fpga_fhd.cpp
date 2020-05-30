//
// Created by eleps on 29.04.19.
//

#include "Fpga_fhd.h"
#include "I2C.h"

Fpga_fhd::Fpga_fhd(std::string filename, LogCallback cb)
        : I2CPacket(filename, FPGA_MODULE_ADDRESS, cb)
{
    I2C &i2c = I2C::getInstance();
    i2c.begin(filename, cb);
}
// Commands
uint8_t Fpga_fhd::whiteBalance(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts ){
    uint8_t r = send(WHITE_BALANCE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setRed(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts ){    
    uint8_t r = send(SET_RED, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setBlue(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts ){
    uint8_t r = send(SET_BLUE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setExposure(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_EXPOSITION, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setAETarget(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_AE_TARGET, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setAEGain(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_AE_GAIN, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setAERegion(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_AE_REGION, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}

uint8_t Fpga_fhd::setColor(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_COLOR, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setHue(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_HUE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setContrast(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_CONTRAST, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setSharpness(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_SHARPNESS, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setFreeze(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(FREEZE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setResolution(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_RESOLUTION, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setScanRate(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_SCANNING_MODE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setGamma(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_GAMMA, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setGammaRate(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_GAMMA_RATE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setBrightness(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_BRIGHTNESS, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::pixelCorrection(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(CORRECT_PIXELS, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::setScene(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SET_SCENE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}
uint8_t Fpga_fhd::saveScene(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(SAVE_SCENE, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}

uint8_t Fpga_fhd::horizontalFlip(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(HORIZONTAL_FLIP, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}

uint8_t Fpga_fhd::verticalFlip(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(VERTICAL_FLIP, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "  succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "  failed, NACK");
    return NOK_I2C;
}

uint8_t Fpga_fhd::checkStatus(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts  ){
    uint8_t r = send(CHECK_STATUS, data, response, 1, attempts); std::ignore = r;
    if (response.size()!=2) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "failed");
        return NOK_I2C;
    }
    if (response.front()==ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "succesfuly");
        return OK_I2C;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + " failed, NACK");
    return NOK_I2C;  
}
