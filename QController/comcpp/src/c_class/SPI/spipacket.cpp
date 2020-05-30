#include "spipacket.h"

/* This file contains platform dependent functions of SPIPacket class. */

#include <cassert>

#include "../Rest/crc.h"
#include "SPI.h"

SPIPacket::~SPIPacket() { }

uint8_t SPIPacket::lenToByte(uint64_t len)
{
    return (len > 127)? static_cast<uint8_t>( (len/128 + (len%128? 1 : 0)) | 0x80)
                      : static_cast<uint8_t>(len);
}

uint16_t SPIPacket::byteToLen(uint8_t byte)
{
    return (byte & 0x80)? (byte & 0x7F)*128 : (byte & 0x7F);
}

uint8_t SPIPacket::getRxCnt(uint8_t) const
{
    return 0;
}

SPIPacket::RESULT SPIPacket::sendBool(uint8_t cmd, bool value, int attempts) const
{
    // printLog(Debug_log, static_cast<std::string>(__func__) + " started");
    std::vector<uint8_t> payload, answer;

    payload.push_back(value? 0x01 : 0x00);

    return send(cmd, payload, answer, attempts);
}

SPIPacket::RESULT SPIPacket::send1Uint16(uint8_t cmd, uint16_t value, int attempts) const
{
    // printLog(Debug_log, static_cast<std::string>(__func__) + " started");
    std::vector<uint8_t> payload, answer;

    payload.push_back(value  & 0xff);
    payload.push_back(value >> 8);

    return send(cmd, payload, answer, attempts);
}

SPIPacket::RESULT SPIPacket::send1Uint8(uint8_t cmd, uint8_t value, int attempts) const
{
    // printLog(Debug_log, static_cast<std::string>(__func__) + " started");
    std::vector<uint8_t> payload, answer;

    payload.push_back(value);

    return send(cmd, payload, answer, attempts);
}

SPIPacket::RESULT SPIPacket::send2Uint8(uint8_t cmd, uint8_t value1, uint8_t value2, int attempts) const
{
    // printLog(Debug_log, static_cast<std::string>(__func__) + " started");
    std::vector<uint8_t> payload, answer;

    payload.push_back(value1);
    payload.push_back(value2);

    return send(cmd, payload, answer, attempts);
}

SPIPacket::RESULT SPIPacket::send2Uint16(uint8_t cmd, uint16_t value1, uint16_t value2, int attempts) const
{
    // printLog(Debug_log, static_cast<std::string>(__func__) + " started");
    std::vector<uint8_t> payload, answer;

    payload.push_back(value1  & 0xff);
    payload.push_back(value1 >> 8);
    payload.push_back(value2  & 0xff);
    payload.push_back(value2 >> 8);

    return send(cmd, payload, answer, attempts);
}


#if defined __linux__ && !defined DEMO

SPIPacket::SPIPacket(std::string deviceName, LogCallback cb)
        : Loggable(cb)
        , mDeviceName(deviceName) {
    SPI::getInstance().begin(deviceName, cb);
}

SPIPacket::RESULT SPIPacket::send(uint8_t cmd,
                                  std::vector<uint8_t> &payload,
                                  std::vector<uint8_t> &answer,
                                  int attempts,
                                  uint16_t pause) const
{
    // Get answer length
    uint8_t rxLen = getRxCnt(cmd);

    while(attempts--)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " transactions left: " + std::to_string(attempts));

        // Send message
        if (transaction(cmd, payload, answer, rxLen, pause) != SPIPacket::RESULT::OK)
            continue;

        if (answer.size() != static_cast<std::size_t>(rxLen-1))
            continue;

        answer.erase(answer.begin()); // remove length byte
        uint8_t acknowledgeByte = answer.front();
        answer.erase(answer.begin()); // Remove acknowledge byte

        if (acknowledgeByte != (SPI::RSP::ACK | SPI::RSP::EXEC))
        {
            if (attempts == 0)
            {
                if ( (acknowledgeByte & SPI::RSP::ACK) != SPI::RSP::ACK )
                {
                    return RESULT::NACK; // not acknowledged
                }
                else
                {
                    return RESULT::NEXEC; // not executed
                }
            } else
                continue;
        }

        // Acknowledged & executed
        printLog(DebugLog, static_cast<std::string>(__func__) + " - success");
        return RESULT::OK;
    }
    return RESULT::TR_ERR;
}

SPIPacket::RESULT SPIPacket::transaction(uint8_t cmd,
                                         std::vector<uint8_t> &txMsg,
                                         std::vector<uint8_t> &rxMsg,
                                         uint8_t rxLen,
                                         uint16_t pause) const
{
    assert(txMsg.size() < SPI_PACKET_MAX_TX_SIZE);

    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    // If the msg is less than 128 bytes, just use it's length
    // If the msg is larger, set length to multiples of 128
    uint64_t txLen = txMsg.size() + 3;
    uint64_t txFullLen = txLen < 128? txLen : 128*(txLen/128 + (txLen%128? 1 : 0));

    // Allocate transmit buffer
    std::vector<uint8_t> tx_buffer(txFullLen,0); // already initialized to 0

    // Set length
    tx_buffer[0] = lenToByte(txFullLen);
    tx_buffer[1] = cmd;
    // Fill in the message
    std::copy(txMsg.begin(), txMsg.end(), tx_buffer.begin()+2);
    // Add CRC8
    tx_buffer[txFullLen - 1] = CRC::crc8(tx_buffer.data(), txFullLen - 1);

    // Send & check if transmission was sucessfull
    if (!SPI::getInstance().transaction(tx_buffer, rxLen, pause)) {
        printLog(WarningLog, static_cast<std::string>(__func__) + ": packet not send");
        return RESULT::NOK;
    }

    rxMsg = SPI::getInstance().recData();

    // Compute CRC over all received message including CRC itself - should equal 0
    if(CRC::crc8(rxMsg.data(),rxMsg.size()))
    {
        printLog(WarningLog, static_cast<std::string>(__func__) + ": CRC error");
        return RESULT::NOK;
    }

    rxMsg.pop_back();
    printLog(DebugLog, static_cast<std::string>(__func__) + " ended succesfully");
    return RESULT::OK;
}
#else

#include "MCU.h" // this is only for debug mode to form answer, probably remove later

SPIPacket::SPIPacket(std::string deviceName, LogCallback cb)
        : Loggable(cb)
        , mDeviceName(deviceName) { }

SPIPacket::RESULT SPIPacket::send(uint8_t cmd,
                            std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &answer,
                            int attempts,
                            uint16_t pause) const {
    std::ignore = payload;
    std::ignore = attempts;
    std::ignore = pause;
    // This is DEMO branch
    printLog(DebugLog, static_cast<std::string>(__func__) + " DEMO answer");
    answer.clear();
    if (cmd == MCU::REQUEST_STATUS) // answer to any command other than REQUEST_STATUS
    { // answer to REQUEST_STATUS
        answer.push_back(0x00);
        answer.push_back(0x00);
    }
    return SPIPacket::RESULT::OK;
}

SPIPacket::RESULT SPIPacket::transaction(uint8_t cmd,
                                   std::vector<uint8_t> &txMsg,
                                   std::vector<uint8_t> &rxMsg,
                                   uint8_t rxLen,
                                   uint16_t pause) const {
    std::ignore = cmd;
    std::ignore = txMsg;
    std::ignore = rxMsg;
    std::ignore = rxLen;
    std::ignore = pause;
    assert(txMsg.size() < SPI_PACKET_MAX_TX_SIZE);
    return SPIPacket::RESULT::OK;
}
#endif
