#include "i2ccontroller.h"

#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <iostream>
#include <linux/uinput.h>
I2CController::I2CController(string I2CbusName,string SerialbusName) {
    BoardFHD=new Board_fhd(I2CbusName,nullptr);
    FPGAFHD=new Fpga_fhd(I2CbusName,nullptr);
    BlueModule=new ConnModule(I2CbusName,nullptr);
    DATEMODULE=new DateModule();
    ButtonModule=new CameraHead(SerialbusName);
    //connect(&mWatcherCheckKeys, &QTimer::timeout, this, &I2CController::checkKeys);
    mWatcherCheckKeys.start(KEYS_WATCH_INTERVAL_MS);
    fd_keyEmulator = SetupUinputDevice();

}
I2CController::~I2CController(){
    delete BoardFHD;
    delete FPGAFHD;
    delete BlueModule;
    delete DATEMODULE;
    delete ButtonModule;
}
void I2CController::writeButtons(unsigned int valLeft,unsigned int valRight){

}
void I2CController::checkKeys(uint16_t &st){
    vector<uint8_t> data;
    vector<uint8_t> response;
    uint16_t status=0x0000;
    uint16_t key=0x0000;
    board()->getStatus(data,response);
    if (fd_keyEmulator==-1){return;}
    if(response.size()<2){status=0x0400;}
    else{ status=(static_cast<uint16_t>(response.at(0)<<8)|static_cast<uint16_t>(response.at(1)));}
    if(countSetBits(status)>1){status=0x0800;}
    switch (status){
        case Board_fhd::UP:key= KEY_UP; break;//up
        case Board_fhd::DOWN:key= KEY_DOWN; break;//down
        case Board_fhd::LEFT:key= KEY_LEFT; break;//left
        case Board_fhd::RIGHT:key= KEY_RIGHT; break;//right
        case Board_fhd::CHOOSE:key= KEY_ENTER; break;//Choose
        case Board_fhd::MENU:key= KEY_ESC; break;//menu
        case Board_fhd::POWER:key= KEY_Q; break;//Disable
        case Board_fhd::BALANCE:key= KEY_W; break;//Balance
        case Board_fhd::SNAPSHOT:key= KEY_E; break;//screen
        case Board_fhd::RECORD:key= KEY_R; break;//record
        case 0x0400:key= KEY_T; break;//record
        case 0x0800:key= KEY_Y; break;//record
        default:key=KEY_U; break;
    }
    //return key;
    if (key!=0x0000){
        SendKeyboardEvents(fd_keyEmulator, EV_KEY, key, 1);
        SendKeyboardEvents(fd_keyEmulator, EV_SYN, SYN_REPORT, 0);
        usleep(100);
        SendKeyboardEvents(fd_keyEmulator, EV_KEY, key, 0);
        //SendKeyboardEvents(fd_keyEmulator, EV_SYN, SYN_REPORT, 0);
    }
    //CloseUinputDevice(fd_keyEmulator);
    /*key=0x0000;
    //CameraHead::PressedButtons uart_status=ButtonModule->getButtons();
    switch(CameraHead::ERROR_PRESSED){
        case CameraHead::LEFT_PRESSED: key=leftButton; break;
        case CameraHead::RIGHT_PRESSED: key=rightButton; break;
        default:key=0x0000; break;
    }
    if (key!=0x0000){
        SendKeyboardEvents(fd_keyEmulator, EV_KEY, key, 1);
        SendKeyboardEvents(fd_keyEmulator, EV_SYN, SYN_REPORT, 0);
        usleep(50);
        SendKeyboardEvents(fd_keyEmulator, EV_KEY, key, 0);
        SendKeyboardEvents(fd_keyEmulator, EV_SYN, SYN_REPORT, 0);
    }*/

}
int I2CController::SetupUinputDevice() {
    int fd_uinput_device;
    fd_uinput_device = open("/dev/uinput", O_WRONLY |  O_NONBLOCK | O_NDELAY );//
    if(fd_uinput_device < 0) { return -1;    }
    struct uinput_user_dev dev_key_board_emulator;
    memset(&dev_key_board_emulator, 0, sizeof(uinput_user_dev));
    snprintf(dev_key_board_emulator.name, UINPUT_MAX_NAME_SIZE, "zebra-scanner-hidkb-emulator");
    dev_key_board_emulator.id.bustype = BUS_USB;
    dev_key_board_emulator.id.vendor = 0x01;
    dev_key_board_emulator.id.product = 0x02;
    dev_key_board_emulator.id.version = 1;
    if(ioctl(fd_uinput_device, UI_SET_EVBIT, EV_KEY) < 0) {      return -1;    }
    for(int iEvent=0; iEvent < 254; iEvent++){
        if(ioctl(fd_uinput_device, UI_SET_KEYBIT, iEvent) < 0){
            std::cout << "Error : ioctl : UI_SET_KEYBIT for event ID: " << iEvent << " : " << strerror(errno) << std::endl;
        }
    }
    if(ioctl(fd_uinput_device, UI_SET_EVBIT, EV_SYN) < 0){      return -1;    }
    if(write(fd_uinput_device, &dev_key_board_emulator, sizeof(uinput_user_dev)) < 0) { return -1;    }
    if(ioctl(fd_uinput_device, UI_DEV_CREATE) < 0)    {  return -1;    }
    return fd_uinput_device;
}
int I2CController::SendKeyboardEvents(int fd_dev, int event_type, int key_code, int value) {
    struct input_event key_input_event;
    memset(&key_input_event, 0, sizeof(input_event));
    key_input_event.type = event_type;
    key_input_event.code = key_code;
    key_input_event.value = value;
    if(write(fd_dev, &key_input_event, sizeof(input_event)) < 0)    {return -1; }
    return 0;
}
unsigned int I2CController::countSetBits(int n) {
    unsigned int count = 0;
    while (n) {
        n &= (n-1);
        count++;
    }
    return count;
}
int I2CController::CloseUinputDevice(int fd_dev) {
    if(ioctl(fd_dev, UI_DEV_DESTROY) < 0) { return -1;  }
    if(close(fd_dev) < 0)    {  return -1;  }
    return 0;
}