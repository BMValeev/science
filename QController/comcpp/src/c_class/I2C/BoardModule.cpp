//
// Created by eleps on 07.02.19.
//

#include "BoardModule.h"

#include "../Rest/crc.h"
#include "I2C.h"

// BoardModule class
// Construction and destruction
BoardModule::BoardModule(std::string filename, LogCallback cb)
    : I2CPacket(filename, BOARD_MODULE_ADDRESS, cb)
{ }

uint8_t BoardModule::setBonding(bool state, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    payload.push_back(state);

    uint8_t r = send(SET_BONDING, payload, response, 1, attempts);

    if (r != OK_I2C || response.size() != 1 || response.front() != ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "failed");
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t BoardModule::getVersion(uint16_t& version, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;

    uint8_t r = send(GET_VERSION, payload, response, 2, attempts);

    if (r != OK_I2C || response.size() != 2) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "failed");
        return NOK_I2C;
    }

    version = static_cast<uint16_t>(response[0] + (response[1] << 8));
    return OK_I2C;
}

uint8_t BoardModule::getTools(uint8_t& toolA, uint8_t& toolB, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;

    uint8_t r = send(GET_TOOLS, payload, response, 2, attempts);

    if (r != OK_I2C || response.size() != 2) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "failed");
        return NOK_I2C;
    }

    toolA = response[0];
    toolB = response[1];
    return OK_I2C;
}

uint8_t BoardModule::getPower(bool& state, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;

    uint8_t r = send(GET_POWER, payload, response, 1, attempts);

    if (r != OK_I2C || response.size() != 1) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "failed");
        return NOK_I2C;
    }

    state = response[0];
    return OK_I2C;
}

uint8_t BoardModule::setEnergy(bool energy, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    payload.push_back(energy);

    uint8_t r = send(SET_ENERGY, payload, response, 1, attempts);

    if (r != OK_I2C || response.size() != 1 || response.front() != ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "failed");
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t BoardModule::setVolume(uint8_t volume, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    payload.push_back(volume);

    uint8_t r = send(SET_VOLUME, payload, response, 1, attempts);

    if (r != OK_I2C || response.size() != 1 || response.front() != ACK_I2C) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "failed");
        return NOK_I2C;
    }

    return OK_I2C;
}

#ifdef C_CLASS_DEBUG
void printToC(uint8_t status, std::string msg)
{
    std::cout << status << msg << std::endl;
}
int main(void)
{
    std::string filename="/dev/i2c-2";
    std::cout<<"1"<<std::endl;
    BoardModule mcu(filename,printToC);
    std::cout<<"2"<<std::endl;
    std::vector<uint8_t> data;
    mcu.getTools(data);
    std::cout<<"3\n";
    printf("%zu\n",data.size());
    return 1;
}
#endif
