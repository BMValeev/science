//
// Created by eleps on 07.02.19.
//

#include "ConnModule.h"
#include "I2C.h"

#ifdef C_CLASS_DEBUG
    #include <iostream>
#endif // C_CLASS_DEBUG

// ConnModule class
// Construction and destruction
ConnModule::ConnModule(std::string deviceName, LogCallback cb)
    : I2CPacket(deviceName, CONN_MODULE_ADDRESS, cb)
{ }

uint8_t ConnModule::setUUID(uint32_t uuid, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    // Construct uuid array of bytes
    std::vector<uint8_t> payload, response;
    payload.push_back(uuid & 0xFF);
    payload.push_back((uuid>>8)  & 0xFF);
    payload.push_back((uuid>>16) & 0xFF);
    payload.push_back((uuid>>24) & 0xFF);

    uint8_t r = send(SET_UUID, payload, response, 1, attempts);

    if (r != OK_I2C || response.front() != ACK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t ConnModule::setName(std::string name, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    name.resize(20, 0x00);
    std::vector<uint8_t> payload(name.begin(), name.end()), response;
    uint8_t r = send(SET_NAME, payload, response, 1, attempts);

    if (r != OK_I2C || response.front() != ACK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t ConnModule::startInit(int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    uint8_t r = send(START_INIT, payload, response, 1, attempts);

    if (r != OK_I2C || response.front() != ACK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t ConnModule::initRecord(std::vector<uint8_t> data, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> response;
    uint8_t r = send(RECORD_INIT, data, response, 1, attempts);

    if (r != OK_I2C || response.front() != ACK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t ConnModule::endInit(int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    uint8_t r = send(END_INIT, payload, response, 1, attempts);

    if (r != OK_I2C || response.front() != ACK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t ConnModule::writeValue(uint16_t id, std::vector<uint8_t> value, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    payload.push_back(static_cast<uint8_t>(id & 0x00FF));
    payload.push_back(static_cast<uint8_t>((id >> 8) & 0x00FF));
    payload.insert(payload.end(), std::begin(value), std::end(value));

    uint8_t r = send(WRITE_VALUE, payload, response, 1, attempts);

    if (r != OK_I2C || response.front() != ACK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t ConnModule::readValue(uint16_t id_rec, std::map<uint16_t,std::vector<uint8_t>>& val, int attempts) /*change order of message*/
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> responce;
    std::vector<uint8_t> payload, answer;

    payload.push_back(id_rec & 0xff);
    payload.push_back((id_rec>>8) & 0xff);

    uint8_t r = send(READ_VALUE, payload, answer, 6, attempts);

    if (r != OK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    val.insert(std::pair<uint16_t,std::vector<uint8_t>>(id_rec, answer));
    return OK_I2C;
}

uint8_t ConnModule::readLastChangedValue(std::map<uint16_t,std::vector<uint8_t>>& vals, int attempts) /*change order of message*/
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> data, response;

    uint8_t r = send(READ_LAST, data, response, 30, attempts);

    if (r != OK_I2C || response.size() % 6)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed");
        return NOK_I2C;
    }

    if (response.size() == 0)
    {
        return OK_I2C;
    }

    uint16_t id;
    vals.clear();
    while(response.size() != 0)
    {
        id = static_cast<uint16_t>(response[0] + (response[1] << 8));
        std::vector<uint8_t> val(response[2], response[5]);
        vals.insert(std::pair<uint16_t,std::vector<uint8_t>>(id,val) );
        response.erase(response.begin(), response.begin() + 6);
    }
    return OK_I2C;
}

uint8_t ConnModule::startBonding(bool db, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    payload.push_back(db);
    uint8_t r = send(START_BONDING, payload, response, 1, attempts);

    if (r != OK_I2C || response.front() != ACK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    return OK_I2C;
}

uint8_t ConnModule::checkBonding(uint8_t& bondingCount, int attempts)
{
    printLog(DebugLog, static_cast<std::string>(__func__) + " started");

    std::vector<uint8_t> payload, response;
    uint8_t r = send(CHECK_BONDING, payload, response, 1, attempts);

    if (r != OK_I2C)
    {
        printLog(DebugLog, static_cast<std::string>(__func__) + " failed, r=" + std::to_string(r));
        return NOK_I2C;
    }

    bondingCount = response.front();
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
    ConnModule mcu(filename,printToC);
    std::cout<<"2"<<std::endl;
    std::vector<uint8_t> data;
    mcu.StartInit(data);
    std::cout<<"3\n";
    printf("%zu\n",data.size());
    return 1;
}
#endif // C_CLASS_DEBUG
