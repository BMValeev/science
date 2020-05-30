//
// Created by eleps on 29.04.19.
//

#ifndef HARDWARECLASSES_BOARD_FHD_H
#define HARDWARECLASSES_BOARD_FHD_H


#include "../Rest/defs.h"
#include "i2cpacket.h"
#include <vector>
#include <map>

#define BOARD_FHD_MODULE_ADDRESS 0x80
#define BOARD_FHD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER 3

class Board_fhd : public I2CPacket
{
public:
    Board_fhd(std::string filename, LogCallback cb = printToCout);

    // Commands
    uint8_t getStatus(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts = BOARD_FHD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setLED(std::vector<uint8_t> data, std::vector<uint8_t> &response, int attempts = BOARD_FHD_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);

    enum Cmd {
        GET_STATUS = 0x02,
        SET_LED = 0x01,
    };
    enum Buttons {
        BALANCE=0X0001,
        MENU=0X0002,
        UP=0X0004,
        RIGHT=0X0008,
        DOWN=0X0010,
        LEFT=0X0020,
        SNAPSHOT=0X0040,
        RECORD=0X0080,
        POWER=0X0100,
        CHOOSE=0X0200,
    };
    enum Led {
        LED_OFF = 0x00,
        LED_BLINK = 0x01,
        LED_ON = 0x02,
    };
};

#endif //HARDWARECLASSES_BOARD_FHD_H
