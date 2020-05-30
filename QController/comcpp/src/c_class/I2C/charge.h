#ifndef CHARGE_H
#define CHARGE_H

#include <vector>
#include <string>

#include "QController/c_class/Rest/defs.h"
#include "QController/c_class/Rest/loggable.h"
#include "chargeinterface.h"
#include "stc3115_Driver.h"

class Charge : public ChargeInterface, public Loggable
{
public:
    Charge(std::string deviceName, LogCallback cb);
    ~Charge() override;

    // Заряд в процентах от 0 до 100
    uint8_t readCharge() override;
    // заряжается или нет
    bool readIsCharging() override;

private:
    const std::string mDeviceName;
    STC3115_ConfigData_TypeDef mStcConfig;
    STC3115_BatteryData_TypeDef mStcBatteryData;
};

#endif // CHARGE_H
