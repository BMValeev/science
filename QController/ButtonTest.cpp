//
// Created by eleps on 19.09.19.
//
#include "ButtonTest.h"
#include "iostream"

/*Setters for properties*/
ButtonTest::ButtonTest(QObject *parent): QObject(parent) {    qRegisterMetaType<ButtonTest*>();}
void ButtonTest::checkStatuses(){
    uint16_t status=0;
    cout<<1<<endl;
    I2CBus->checkKeys(status);
    cout<<3<<endl;

    writeUpButton (false) ;
    writeDownButton (false) ;
    writeLeftButton (false) ;
    writeRightButton (false) ;
    writeMenuButton (false);
    writeRecordButton (false) ;
    writeBalButton (false) ;
    writeScreenButton (false) ;
    writeOffButton(false);
    writeEnterButton(false);
    writeByteButton(false);
    writeBitButton(false);
    writeNoButton(false);
    switch(status){
        case KEY_Y: writeBitButton(true); break;//up
        case KEY_UP: writeUpButton(true); break;//up
        case KEY_DOWN: writeDownButton(true); break;//down
        case KEY_LEFT: writeLeftButton(true); break;//left
        case KEY_RIGHT: writeRightButton(true); break;//right
        case KEY_ENTER: writeEnterButton(true); break;//right
        case KEY_Q: writeOffButton(true); break;//right
        case KEY_ESC: writeMenuButton(true); break;//menu
        case KEY_W: writeBalButton(true); break;//Balance
        case KEY_E: writeScreenButton(true); break;//screen
        case KEY_R: writeRecordButton(true); break;//record
        case KEY_U: writeNoButton(true); break;//record
        default:writeByteButton(true); break;
    }
}
void ButtonTest::writeUpBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::UP));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    upB=val%3;
    upBtnChanged(upB);
}
void ButtonTest::writeDownBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::DOWN));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    downB=val%3;
    upBtnChanged(downB);
}
void ButtonTest::writeLeftBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::LEFT));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    leftB=val%3;
    upBtnChanged(leftB);
}
void ButtonTest::writeRightBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::RIGHT));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    rightB=val%3;
    upBtnChanged(rightB);
}
void ButtonTest::writeMenuBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::MENU));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    menuB=val%3;
    upBtnChanged(menuB);
}
void ButtonTest::writeRecordBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::RECORD));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    recordB=val%3;
    upBtnChanged(recordB);
}
void ButtonTest::writeBalBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::BALANCE));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    balB=val%3;
    upBtnChanged(balB);
}
void ButtonTest::writeScreenBtn (unsigned int val) {
    vector<unsigned char> data,resp;
    data.push_back((Board_fhd::SNAPSHOT));
    data.push_back(val%3&(0xff));
    cout << "send button " <<val<<endl;
    if(I2CBus->board()->setLED(data,resp)==NOK_I2C){return;}
    screenB=val%3;
    upBtnChanged(screenB);
}
void ButtonTest::writeUpButton (bool val) {
    upBut=val;
    upButtonChanged(upBut);
}
void ButtonTest::writeDownButton (bool val) {
    downBut=val;
    downButtonChanged(downBut);
}
void ButtonTest::writeLeftButton (bool val) {
    leftBut=val;
    leftButtonChanged(leftBut);
}
void ButtonTest::writeRightButton (bool val) {
    rightBut=val;
    rightButtonChanged(rightBut);
}
void ButtonTest::writeMenuButton (bool val) {
    menuBut=val;
    menuButtonChanged(menuBut);
}
void ButtonTest::writeRecordButton (bool val) {
    recordBut=val;
    recordButtonChanged(recordBut);
}
void ButtonTest::writeBalButton (bool val) {
    balBut=val;
    balButtonChanged(balBut);
}
void ButtonTest::writeScreenButton (bool val) {
    screenBut=val;
    screenButtonChanged(screenBut);
}
void ButtonTest::writeEnterButton (bool val) {
    enterBut=val;
    enterButtonChanged(enterBut);
}
void ButtonTest::writeOffButton (bool val) {
    offBut=val;
    offButtonChanged(offBut);
}
void ButtonTest::writeByteButton (bool val) {
    byteBut=val;
    byteButtonChanged(byteBut);
}
void ButtonTest::writeBitButton (bool val) {
    bitBut=val;
    bitButtonChanged(bitBut);
}
void ButtonTest::writeNoButton (bool val) {
    noBut=val;
    noButtonChanged(noBut);
}
