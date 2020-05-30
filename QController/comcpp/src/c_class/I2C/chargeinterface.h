#ifndef CHARGEINTERFACE_H
#define CHARGEINTERFACE_H

#include <stdint.h>

class ChargeInterface
{
public:
    virtual ~ChargeInterface() = 0;
    // Заряд в процентах от 0 до 100
    virtual uint8_t readCharge() = 0;
    // заряжается или нет
    virtual bool readIsCharging() = 0;

};

#endif // CHARGEINTERFACE_H

