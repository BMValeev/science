#include "charge.h"
#include "I2C.h"
using namespace std;
Charge::Charge(std::string deviceName, LogCallback cb)
    : Loggable(cb)
    , mDeviceName(deviceName)
{
#ifdef __linux__
    // Initialize I2C
    I2C::getInstance().begin(deviceName);
#endif // __linux__

    // Initialize STC3115
    if (!STC3115::Init(&mStcConfig, &mStcBatteryData))
        printLog(WarningLog,"Failed to initialize STC3115");
}

Charge::~Charge()
{
    STC3115::Stop();
}

uint8_t Charge::readCharge()
{
    switch (STC3115::Task(&mStcConfig, &mStcBatteryData))
    {
        case -1:
            printLog(WarningLog,"Failed to read from STC3115");
            return 0;
        case 0:
        case 1:
        default:
            return static_cast<uint8_t>(mStcBatteryData.SOC/10);
    }
}

bool Charge::readIsCharging()
{
    return false;
}
#ifdef C_CLASS_DEBUG
void PrintToC(uint8_t status, string msg)
{
    cout<<status<<msg<<endl;
}
int main(void)
{
    std::string filename="/dev/i2c-2";
    cout<<"1"<<endl;
    Charge charge(filename,PrintToC);
    cout<<"2"<<endl;
    std::vector<unsigned char> data;
    charge.read_charge();
    cout<<"3\n";
    printf("%zu\n",data.size());
    return 1;
}
#endif
