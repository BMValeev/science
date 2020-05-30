
#ifndef I2CPACKET_H
#define I2CPACKET_H

#include <vector>

#include "../Rest/defs.h"
#include "../Rest/loggable.h"


#define I2C_PACKET_MAX_TX_SIZE 16384
#define I2C_PACKET_TRANSACTION_ATTEMPTS_NUMBER 3

#define ACK_I2C 0x06
#define NACK_I2C 0x015
#define BOF_I2C 0x20
#define MSP_I2C 0x21
#define ACK_I2C_V2 0x03
#define EXEC_I2C_V2 0x30


class I2CPacket : public Loggable
{
public:
    I2CPacket(std::string deviceName, uint8_t addr, LogCallback cb = printToCout);
    virtual ~I2CPacket();

    // Getters
    uint8_t address() const { return mAddr; }
    std::string deviceName() const { return mDeviceName; }

protected:
    // Helpers
    uint8_t send(uint8_t cmd,
                 std::vector<uint8_t>& payload,
                 std::vector<uint8_t>& answer,
                 uint8_t ansLen,
                 int attempts = I2C_PACKET_TRANSACTION_ATTEMPTS_NUMBER) const;
    // I2C is only used in this function, so possible to reimplement over another protocol
    uint8_t transaction(uint8_t cmd,
                        std::vector<uint8_t>& txMsg,
                        std::vector<uint8_t>& rxMsg,
                        uint8_t ansLen) const;

private:
    const std::string mDeviceName;
    const uint8_t mAddr;

};

#endif // I2CPACKET_H
