#ifndef I2CCONTROLLER_H
#define I2CCONTROLLER_H
#include<string>

#include "comcpp/src/c_class/I2C/Board_FHD.h"
#include "comcpp/src/c_class/I2C/Fpga_fhd.h"
#include "comcpp/src/c_class/I2C/ConnModule.h"
#include "comcpp/src/c_class/Rest/DateModule.h"
#include "comcpp/src/c_class/Serial/CameraHead.h"
#include <linux/input.h>
#include <linux/uinput.h>
#include <QObject>
#include <QTimer>
#include "comcpp/src/c_class/I2C/I2C.h"

#define KEYS_WATCH_INTERVAL_MS 100
using namespace std;
class I2CController : public QObject {
    Q_OBJECT
    Q_PROPERTY(Board_fhd* board READ board)
    Q_PROPERTY(Fpga_fhd* fpga READ fpga)
    Q_PROPERTY(ConnModule* blue READ blue)
    Q_PROPERTY(DateModule* date READ date)
public:
    I2CController(string I2CbusName,string SerialbusName);
    ~I2CController();
    Board_fhd* board() {return BoardFHD;}
    Fpga_fhd* fpga() {return FPGAFHD;}
    ConnModule* blue() {return BlueModule;}
    DateModule* date() {return DATEMODULE;}
    void writeButtons(unsigned int valLeft,unsigned int valRight);
    void checkKeys(uint16_t &st);
public slots:

private:
    int fd_keyEmulator;
    Board_fhd* BoardFHD;
    Fpga_fhd* FPGAFHD;
    ConnModule* BlueModule;
    DateModule* DATEMODULE;
    CameraHead* ButtonModule;
    QTimer mWatcherCheckKeys;
    int leftButton=KEY_Q,rightButton=KEY_W;


    int SetupUinputDevice();
    int SendKeyboardEvents(int fd_dev, int event_type, int key_code, int value);
    unsigned int countSetBits(int n);
    int CloseUinputDevice(int fd_dev);
};

#endif // I2CCONTROLLER_H