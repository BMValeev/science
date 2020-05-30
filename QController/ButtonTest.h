//
// Created by eleps on 19.09.19.
//

#ifndef MENUCAMERAFHD_BUTTONTEST_H
#define MENUCAMERAFHD_BUTTONTEST_H
#include "scene.h"
#include "vector"
#include <string>
#include <QObject>
#include "i2ccontroller.h"

class ButtonTest: public QObject {
    Q_OBJECT
    Q_PROPERTY(unsigned int upBtn READ upBtn WRITE writeUpBtn NOTIFY upBtnChanged)
    Q_PROPERTY(unsigned int downBtn READ downBtn WRITE writeDownBtn NOTIFY downBtnChanged)
    Q_PROPERTY(unsigned int leftBtn READ leftBtn WRITE writeLeftBtn NOTIFY leftBtnChanged)
    Q_PROPERTY(unsigned int rightBtn READ rightBtn WRITE writeRightBtn NOTIFY rightBtnChanged)
    Q_PROPERTY(unsigned int menuBtn READ menuBtn WRITE writeMenuBtn NOTIFY menuBtnChanged)
    Q_PROPERTY(unsigned int recordBtn READ recordBtn WRITE writeRecordBtn NOTIFY recordBtnChanged)
    Q_PROPERTY(unsigned int screenBtn READ screenBtn WRITE writeScreenBtn NOTIFY screenBtnChanged)
    Q_PROPERTY(unsigned int balBtn READ balBtn WRITE writeBalBtn NOTIFY balBtnChanged)

    Q_PROPERTY(bool upButton READ upButton WRITE writeUpButton NOTIFY upButtonChanged)
    Q_PROPERTY(bool downButton READ downButton WRITE writeDownButton NOTIFY downButtonChanged)
    Q_PROPERTY(bool leftButton READ leftButton WRITE writeLeftButton NOTIFY leftButtonChanged)
    Q_PROPERTY(bool rightButton READ rightButton WRITE writeRightButton NOTIFY rightButtonChanged)
    Q_PROPERTY(bool menuButton READ menuButton WRITE writeMenuButton NOTIFY menuButtonChanged)
    Q_PROPERTY(bool recordButton READ recordButton WRITE writeRecordButton NOTIFY recordButtonChanged)
    Q_PROPERTY(bool screenButton READ screenButton WRITE writeScreenButton NOTIFY screenButtonChanged)
    Q_PROPERTY(bool balButton READ balButton WRITE writeBalButton NOTIFY balButtonChanged)
    Q_PROPERTY(bool enterButton READ enterButton WRITE writeEnterButton NOTIFY enterButtonChanged)
    Q_PROPERTY(bool offButton READ offButton WRITE writeOffButton NOTIFY offButtonChanged)
    Q_PROPERTY(bool byteButton READ byteButton WRITE writeByteButton NOTIFY byteButtonChanged)
    Q_PROPERTY(bool bitButton READ bitButton WRITE writeBitButton NOTIFY bitButtonChanged)
    Q_PROPERTY(bool noButton READ noButton WRITE writeNoButton NOTIFY noButtonChanged)

public:
    void setI2C(I2CController *data){I2CBus=data;}
    explicit ButtonTest(QObject *parent= nullptr);
    ~ButtonTest(){}
    void checkStatuses();
    unsigned int upBtn(){return upB;};
    unsigned int downBtn(){return downB;};
    unsigned int leftBtn(){return leftB;};
    unsigned int rightBtn(){return rightB;};
    unsigned int menuBtn(){return menuB;};
    unsigned int recordBtn(){return recordB;};
    unsigned int screenBtn(){return screenB;};
    unsigned int balBtn(){return balB;};
    unsigned int upButton(){return upBut;};
    unsigned int downButton(){return downBut;};
    unsigned int leftButton(){return leftBut;};
    unsigned int rightButton(){return rightBut;};
    unsigned int menuButton(){return menuBut;};
    unsigned int recordButton(){return recordBut;};
    unsigned int screenButton(){return screenBut;};
    unsigned int balButton(){return balBut;};
    unsigned int enterButton(){return enterBut;};
    unsigned int offButton(){return offBut;};
    unsigned int byteButton(){return byteBut;};
    unsigned int bitButton(){return bitBut;};
    unsigned int noButton(){return noBut;};
signals:
    void upBtnChanged (unsigned int val) ;
    void downBtnChanged (unsigned int val) ;
    void rightBtnChanged (unsigned int val) ;
    void leftBtnChanged (unsigned int val) ;
    void menuBtnChanged (unsigned int val) ;
    void recordBtnChanged (unsigned int val) ;
    void screenBtnChanged (unsigned int val) ;
    void balBtnChanged (unsigned int val) ;
    void upButtonChanged (bool val) ;
    void downButtonChanged (bool val) ;
    void rightButtonChanged (bool val) ;
    void leftButtonChanged (bool val) ;
    void menuButtonChanged (bool val) ;
    void recordButtonChanged (bool val) ;
    void screenButtonChanged (bool val) ;
    void balButtonChanged (bool val);
    void enterButtonChanged (bool val);
    void offButtonChanged (bool val);
    void byteButtonChanged (bool val);
    void bitButtonChanged (bool val);
    void noButtonChanged (bool val);
protected:
    I2CController *I2CBus;
    unsigned int balB=0;
    unsigned int upB=0;
    unsigned int downB=0;
    unsigned int leftB=0;
    unsigned int rightB=0;
    unsigned int menuB=0;
    unsigned int recordB=0;
    unsigned int screenB=0;
    bool balBut=false;
    bool upBut=false;
    bool downBut=false;
    bool leftBut=false;
    bool rightBut=false;
    bool menuBut=false;
    bool recordBut=false;
    bool screenBut=false;
    bool enterBut=false;
    bool offBut=false;
    bool byteBut=false;
    bool bitBut=false;
    bool noBut=false;


public slots:

    void writeUpBtn(unsigned int val);
    void writeDownBtn(unsigned int val);
    void writeLeftBtn(unsigned int val);
    void writeRightBtn(unsigned int val);
    void writeMenuBtn(unsigned int val);
    void writeRecordBtn(unsigned int val);
    void writeBalBtn(unsigned int val);
    void writeScreenBtn(unsigned int val);
    void writeUpButton(bool val);
    void writeDownButton(bool val);
    void writeLeftButton(bool val);
    void writeRightButton(bool val);
    void writeMenuButton(bool val);
    void writeRecordButton(bool val);
    void writeBalButton(bool val);
    void writeScreenButton(bool val);
    void writeOffButton(bool val);
    void writeEnterButton(bool val);
    void writeByteButton(bool val);
    void writeBitButton(bool val);
    void writeNoButton(bool val);
};
Q_DECLARE_METATYPE(ButtonTest*);


#endif //MENUCAMERAFHD_BUTTONTEST_H
