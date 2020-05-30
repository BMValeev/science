//
// Created by eleps on 07.02.19.
//

#ifndef C_CLASS_BOARDMODULE_H
#define C_CLASS_BOARDMODULE_H

#include "../Rest/defs.h"
#include "i2cpacket.h"
#include <vector>

#define BOARD_MODULE_ADDRESS 0x80
#define BOARD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER 3

class BoardModule : private I2CPacket
{
public:
    BoardModule(std::string filename, LogCallback cb = printToCout) ;

    // Commands
    uint8_t getVersion(uint16_t &version, int attempts = BOARD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setBonding(bool indicationOn, int attempts = BOARD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t getTools(uint8_t &toolA, uint8_t &toolB, int attempts = BOARD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t getPower(bool &state, int attempts = BOARD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setEnergy(bool energy, int attempts = BOARD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setVolume(uint8_t volume, int attempts = BOARD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);

    enum Cmd
    {
        GET_VERSION = 0x01,
        GET_TOOLS = 0x02,
        GET_POWER = 0x03,
        SET_ENERGY = 0x04,
        SET_VOLUME = 0x05,
        SET_BONDING = 0x06
    };

};
#endif //C_CLASS_BOARDMODULE_H
