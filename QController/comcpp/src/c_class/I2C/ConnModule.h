//
// Created by eleps on 07.02.19.
//

#ifndef C_CLASS_CONNMODULE_H
#define C_CLASS_CONNMODULE_H

#include "../Rest/defs.h"
#include "i2cpacket.h"
#include <vector>
#include <map>

#define CONN_MODULE_ADDRESS 0xE0
#define CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER 3

class ConnModule : public I2CPacket
{
public:
    ConnModule(std::string deviceName, LogCallback cb = printToCout);

    // Commands
    uint8_t setUUID(uint32_t uuid, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t setName(std::string name, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t startInit(int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t initRecord(std::vector<uint8_t> data, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t endInit(int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t checkBonding(uint8_t &bondingCount, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t writeValue(uint16_t id, std::vector<uint8_t> value, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t startBonding(bool db, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t readValue(uint16_t id_rec, std::map<uint16_t, std::vector<uint8_t> > &val, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);
    uint8_t readLastChangedValue(std::map<uint16_t, std::vector<uint8_t> > &vals, int attempts = CONN_MODULE_PACKET_TRANSACTION_ATTEMPTS_NUMBER);

    enum Cmd
    {
        SET_UUID = 0x01,
        SET_NAME = 0x02,
        START_INIT = 0x03,
        RECORD_INIT = 0x04,
        END_INIT = 0x05,
        WRITE_VALUE = 0x06,
        READ_VALUE = 0x07,
        START_BONDING = 0x08,
        CHECK_BONDING = 0x09,
        READ_LAST = 0x0C
    };
};
#endif //C_CLASS_CONNMODULE_H
