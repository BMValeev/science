/*
 *Created by eleps on 27.04.18.
 */
#ifdef __linux__

#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include "I2C.h"


// I2C class
I2C* I2C::theOneTrueInstance = nullptr;

I2C& I2C::getInstance()
{
    if (theOneTrueInstance == nullptr) {
        // Allocate on heap so that it does not get destroyed after
        theOneTrueInstance = new I2C();
    }
    return *theOneTrueInstance;
}

I2C::I2C()
    : Loggable ()
    , mInit(false)
    , mMaxLen(40)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + "I2C constructor called");
    if (theOneTrueInstance) throw std::logic_error("Instance already exists");
    theOneTrueInstance = this;
}

/* Used for configuration of the device in construction */
void I2C::setDeviceName(std::string name)
{
    if (mDeviceName == name)
        return;

    mDeviceName = name;
    printLog(InfoLog, "I2C --> new device name set - " + name);
}

uint32_t I2C::begin(std::string deviceName, LogCallback cb)
{
    // Lock the mutex first
    std::lock_guard<std::mutex> lock(mMutex); // automatically unlocks when function is leaved, no need to call unlock

    setLogCallback(cb);
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    if (mInit) {
        printLog(InfoLog, static_cast<std::string>(__func__) + " I2C already initialized");
        return NOK_I2C;
    }

    // Setups
    mLastRecMsg.reserve(I2C_RX_BUFFER_SIZE);
    setDeviceName(deviceName);

    // Initialization
    mInit = true;

    printLog(DebugLog, static_cast<std::string>(__func__)+ " ended succesfully");

    return OK_I2C;
}

uint32_t I2C::transaction(uint8_t address, std::vector<uint8_t>& buffer, uint32_t ansLen)
{
    // Lock the mutex first
    std::lock_guard<std::mutex> lock(mMutex); // automatically unlocks when function is leaved, no need to call unlock

    printLog(DebugLog, static_cast<std::string>(__func__) + " started");
    printLog(DebugLog, static_cast<std::string>(__func__) + " buffer size = " + std::to_string(buffer.size()));

    mLastRecMsg.resize(ansLen, 0);
    resetRecData();

    std::string data_send, data_rec;

    i2c_rdwr_ioctl_data message;
    memset(&message, 0, sizeof(message));

    i2c_msg message_packet[2];
    memset(&message_packet, 0, sizeof(i2c_msg)*2);

    // Messages config
    message.msgs = message_packet;
    message.nmsgs = ansLen != 0? 2 : 1;
    // Tx/Rx config
    address = address >> 1; // since I2C driver wants 7-bit address
    message_packet[0].addr = address;
    message_packet[0].flags = 0;
    message_packet[0].len = static_cast<uint16_t>(buffer.size());
    message_packet[0].buf = buffer.data();
    message_packet[1].addr = address;
    message_packet[1].flags = I2C_M_RD; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
    message_packet[1].buf = mLastRecMsg.data();
    message_packet[1].len = static_cast<uint16_t>(ansLen);

    int file = open(mDeviceName.c_str(), O_RDWR);

    if (file == -1) {
        printLog(WarningLog, static_cast<std::string>(__func__) + " device open error");
        close(file);
        return NOK_I2C;
    }

    if (ioctl(file, I2C_SLAVE, address) < 0) {
        printLog(WarningLog, static_cast<std::string>(__func__) + " failed to acquire bus access and/or talk to slave");
        close(file);
        return NOK_I2C;
    }

    int ret = ioctl(file, I2C_RDWR, &message);
    if (ret<0) {
        printLog(WarningLog, static_cast<std::string>(__func__) + strerror(-ret) + " unable to send message");
        fprintf (stderr, "%s.\n", strerror(-ret));
        close(file);
        return NOK_I2C;
    }

    close(file);

    printLog(DebugLog, static_cast<std::string>(__func__) + " ended succesfully");
    return OK_I2C;
}
uint32_t I2C::transaction_add(uint8_t address, uint32_t ansLen)
{
    // Lock the mutex first
    std::lock_guard<std::mutex> lock(mMutex); // automatically unlocks when function is leaved, no need to call unlock

    mLastRecMsg.resize(ansLen, 0);
    resetRecData();

    std::string data_rec;

    i2c_rdwr_ioctl_data message;
    memset(&message, 0, sizeof(message));
    i2c_msg message_packet[1];
    memset(&message_packet, 0, sizeof(i2c_msg));

    // Messages config
    message.msgs = message_packet;
    message.nmsgs = 1;
    // Tx/Rx config
    address = address >> 1; // since I2C driver wants 7-bit address
    message_packet[0].addr = address;
    message_packet[0].flags = I2C_M_RD; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
    message_packet[0].buf = mLastRecMsg.data();
    message_packet[0].len = static_cast<uint16_t>(ansLen);

    int file = open(mDeviceName.c_str(), O_RDWR);

    if (file == -1) {
        printLog(WarningLog, static_cast<std::string>(__func__) + " device open error");
        close(file);
        return NOK_I2C;
    }

    if (ioctl(file, I2C_SLAVE, address) < 0) {
        printLog(WarningLog, static_cast<std::string>(__func__) + " failed to acquire bus access and/or talk to slave");
        close(file);
        return NOK_I2C;
    }

    int ret = ioctl(file, I2C_RDWR, &message);
    if (ret<0) {
        printLog(WarningLog, static_cast<std::string>(__func__) + strerror(-ret) + " unable to send message");
        fprintf (stderr, "%s.\n", strerror(-ret));
        close(file);
        return NOK_I2C;
    }

    close(file);
    printLog(DebugLog, static_cast<std::string>(__func__) + " ended succesfully");
    return OK_I2C;
}
#endif // __linux__
