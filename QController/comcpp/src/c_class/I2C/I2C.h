/*
 *Created by eleps on 27.04.18.
 */
#ifndef C_CLASS_I2C_H
#define C_CLASS_I2C_H

#include <vector>
#include <mutex>

#include "../Rest/defs.h"
#include "../Rest/loggable.h"


// I2C Settings
#define OK_I2C 0x00
#define NOK_I2C 0x01

#ifndef I2C_RX_BUFFER_SIZE
    #define I2C_RX_BUFFER_SIZE 40
#endif

#ifdef __linux__


// Low level class that implements basic information exchange via I2C on Hamming board
class I2C : public Loggable
{
public:
    static I2C & getInstance();

    uint32_t begin(std::string deviceName, LogCallback cb = printToCout);
    std::vector<uint8_t> recData() { return mLastRecMsg; }
    void resetRecData() { std::fill(mLastRecMsg.begin(), mLastRecMsg.end(), 0); }
    bool isInitialized() const { return theOneTrueInstance != nullptr; }

    // Transmission
    uint32_t transaction(uint8_t address, std::vector<uint8_t> &buffer, uint32_t ansLen);
    uint32_t transaction_add(uint8_t address, uint32_t ansLen);

protected:
    I2C();
    ~I2C() { }

private:
    static I2C * theOneTrueInstance;
    bool mInit;
    std::string mDeviceName;
    std::vector<uint8_t>  mLastRecMsg;
    std::mutex mMutex;
    const uint32_t mMaxLen;
    uint32_t mMsgLen;
    struct i2c_client *mI2CData;

    // Helpers
    void setDeviceName(std::string name);
};

#endif // __linux__
#endif // C_CLASS_I2C_H
