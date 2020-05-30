#include "i2cpacket.h"

/* This file contains platform dependent functions of I2CPacket class. */

#include <cassert>
#ifdef C_CLASS_DEBUG
    #include <iostream>
#endif // C_CLASS_DEBUG

#include "../Rest/crc.h"
#include "I2C.h"


I2CPacket::~I2CPacket() { }

#if defined __linux__ && !defined DEMO

I2CPacket::I2CPacket(std::string deviceName, uint8_t addr, LogCallback cb)
    : Loggable(cb)
    , mDeviceName(deviceName)
    , mAddr(addr)
{    
    I2C &i2c = I2C::getInstance();
    i2c.begin(deviceName);
}

uint8_t I2CPacket::send(uint8_t cmd,
                        std::vector<uint8_t> &payload,
                        std::vector<uint8_t> &answer,
                        uint8_t ansLen,
                        int attempts) const
{
    while (attempts--)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " transactions left: " + std::to_string(attempts));

        // Send message
        if (transaction(cmd, payload, answer, ansLen) != OK_I2C)
            continue;

        if (answer.size() > ansLen)
            continue;

        // Acknowledged & executed
        printLog(DebugLog, static_cast<std::string>(__func__) + " - success");
        return OK_I2C;
    }
    return NOK_I2C;
}

uint8_t I2CPacket::transaction(uint8_t cmd,
                               std::vector<uint8_t> &txMsg,
                               std::vector<uint8_t> &rxMsg,
                               uint8_t ansLen) const
{
    assert(txMsg.size() < I2C_PACKET_MAX_TX_SIZE);

    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    // uint8_t txLen = static_cast<uint8_t>(txMsg.size() + 2); // CRC not included?

    // Allocate transmit buffer
    std::vector<uint8_t> txBuffer;
    txBuffer.push_back(mAddr); // add address to compute CRC
    // txBuffer.push_back(txLen);
    txBuffer.push_back(cmd);
    txBuffer.insert(txBuffer.end(), txMsg.begin(), txMsg.end());
    txBuffer.push_back(CRC::crc8(txBuffer.data(), txBuffer.size()));
    txBuffer.erase(txBuffer.begin()); // remove address

    // Send
    uint32_t r = I2C::getInstance().transaction(mAddr, txBuffer, ansLen + 2);

    // Check if transmission was sucessfull
    if (r != OK_I2C) {
        printLog(WarningLog, static_cast<std::string>(__func__) + ": packet not send");
        return NOK_I2C;
    }

    rxMsg = I2C::getInstance().recData();

    // Check the length of the message - shouldn't be larger than the length we requested
    if (rxMsg.size() > static_cast<std::size_t>(ansLen + 2))
    {
        printLog(WarningLog, static_cast<std::string>(__func__) + ": received response is larger than requested");
        return NOK_I2C;
    }

    // Cut msg if message is smaller
    rxMsg.resize(rxMsg.front()+1);

    // Compute CRC over all received message including CRC itself - should equal 0
    rxMsg.insert(rxMsg.begin(), mAddr); // insert address to compute CRC
    if (CRC::crc8(rxMsg.data(), rxMsg.size()))
    {
        printLog(InfoLog, static_cast<std::string>(__func__) + ": CRC error");
        rxMsg.erase(rxMsg.begin()); // remove address
        return NOK_I2C;
    }
    rxMsg.erase(rxMsg.begin(), rxMsg.begin() + 2); // remove address & length
    rxMsg.pop_back(); // remove CRC

    printLog(DebugLog, static_cast<std::string>(__func__) + " ended succesfully");
    return OK_I2C;
}


#else // __linux__ && !defined DEMO

#include "ConnModule.h" // for debugging
#include "BoardModule.h" // for debugging

I2CPacket::I2CPacket(std::string deviceName, uint8_t addr, LogCallback cb)
    : Loggable(cb)
    , mDeviceName(deviceName)
    , mAddr(addr)
{ }

uint8_t I2CPacket::send(uint8_t cmd,
                        std::vector<uint8_t>& payload,
                        std::vector<uint8_t>& answer,
                        uint8_t ansLen,
                        int attempts) const
{
    std::ignore = cmd;
    std::ignore = payload;
    std::ignore = attempts;
    // This is DEMO branch
    printLog(DebugLog, static_cast<std::string>(__func__) + " DEMO answer");
    answer.clear();
    answer.resize(ansLen, 0);
    switch (cmd) {
    case ConnModule::READ_VALUE:
        answer[0] = 0;
        answer[0] = 0;
        answer[0] = 0;
        answer[0] = 1;
        break;
    case ConnModule::READ_LAST:
        answer.resize(0);
        break;
    case ConnModule::CHECK_BONDING:
        answer[0] = 0;
        break;
    case BoardModule::GET_POWER:
        answer[0] = ACK_I2C;
        break;
    default:
        answer[0] = ACK_I2C;
    }
    return OK_I2C;
}

uint8_t I2CPacket::transaction(uint8_t cmd,
                               std::vector<uint8_t>& txMsg,
                               std::vector<uint8_t>& rxMsg,
                               uint8_t ansLen) const
{
    std::ignore = cmd;
    std::ignore = txMsg;
    std::ignore = rxMsg;
    std::ignore = ansLen;
    assert(txMsg.size() < I2C_PACKET_MAX_TX_SIZE);
    return OK_I2C;
}
#endif // __linux__ && !defined DEMO

/*
std::vector<uint8_t> I2CPacket::writeArray(uint8_t cmd, std::vector<uint8_t> data, uint32_t ansLen, int attempts)
{
       I2C& i2c = I2C::getInstance();
    uint8_t l_len = 2;
    std::vector<uint8_t> msg, answer, null, l_answer;
    l_len += static_cast<uint8_t>(data.size());
    msg.push_back(static_cast<uint8_t>(mAddr << 1));
    msg.push_back(l_len);
    msg.push_back(cmd);
    for(uint32_t i=0;i<data.size();i++) {
        msg.push_back(data[i]);
    }
    msg.push_back(CRC::crc8(msg.data(),msg.size()));
    msg.erase(msg.begin());
    while(attempts--) {
        if(i2c.transaction(mAddr, msg, ansLen)==OK_I2C){
            answer=i2c.recData();
            l_len=answer.front()+1;
            l_answer.clear();
            l_answer.push_back(static_cast<uint8_t>(mAddr << 1));
            while (l_len--) {
                l_answer.push_back(answer.front());
                answer.erase(answer.begin());
            }
            if (CRC::crc8(l_answer.data(), l_answer.size()-1) == l_answer.back()) {
                printLog(DebugLog, static_cast<std::string>(__func__) + "CRC Ok");
                l_answer.erase(l_answer.begin());
                l_answer.erase(l_answer.begin());
                l_answer.pop_back();
                return l_answer;
            }
            printLog(DebugLog, static_cast<std::string>(__func__) + "CRC NOK");
        }
    }
    // What is this?
    if (cmd == 0x0C) {
        null.push_back('c');
        return null;
    }
    return null;
}
*/
