//
// Created by eleps on 29.04.19.
//

#ifndef HARDWARECLASSES_FPGA_FULLHD_H
#define HARDWARECLASSES_FPGA_FULLHD_H


#include "../Rest/defs.h"
#include "i2cpacket.h"
#include <vector>
#include <map>
#define FPGA_MODULE_ADDRESS 0x70
#define FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER 3

class Fpga_fhd : public I2CPacket
{
public:
    Fpga_fhd(std::string filename, LogCallback cb = printToCout);
    enum WhiteBalance{PUSH_LOCK=0x01, START_WB=0x02, STOP_WB=0x03};
    enum Exposition{EXPOSURE_AUTO=0x00,EXPOSURE_MANUAL=0x00,};
    enum AERegion{SPOT_AE=0x00,CENTER_AE=0x01,WIDE_AE=0x02};
    enum ImageSize{IMAGE_FHD=0X00,IMAGE_HD=0X01};
    enum ImageRate{IMAGE_PROGRESSIVE=0X00,IMAGE_INTERLEACED=0X01};
    enum GammaCorr{GAMMA_OFF=0X00, GAMMA_ON=0X01};
    enum Flip{ FLIP_OFF=0x00,FLIP_ON=0x01};
    // Commands
    uint8_t whiteBalance(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setRed(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setBlue(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setExposure(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setAETarget(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setAEGain(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setAERegion(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setColor(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setHue(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setContrast(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setSharpness(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setFreeze(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setResolution(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setScanRate(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setGamma(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setGammaRate(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setBrightness(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t pixelCorrection(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setScene(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t saveScene(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t horizontalFlip(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t verticalFlip(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t checkStatus(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts =  FPGA_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t returnValue(std::vector<uint8_t> &response);
    enum Cmd {
        WHITE_BALANCE = 0x01,
        SET_RED = 0x02,
        SET_BLUE = 0x03,
        SET_EXPOSITION = 0x04,
        SET_AE_TARGET = 0x05,
        SET_AE_GAIN = 0x06,
        SET_AE_REGION = 0x07,
        SET_COLOR = 0x08,
        SET_HUE = 0x09,
        SET_CONTRAST = 0x0A,
        SET_SHARPNESS = 0x0B,
        FREEZE = 0x0C,
        SET_RESOLUTION= 0x0D,
        SET_SCANNING_MODE = 0x0E,
        SET_GAMMA = 0x0F,
        SET_GAMMA_RATE = 0x10,
        SET_BRIGHTNESS = 0x11,
        CORRECT_PIXELS = 0x12,
        SET_SCENE = 0x13,
        SAVE_SCENE = 0x14,
        HORIZONTAL_FLIP = 0x15,
        VERTICAL_FLIP = 0x16,
        CHECK_STATUS = 0x17,
    };
};
#endif //HARDWARECLASSES_FPGA_FULLHD_H
