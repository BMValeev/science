
#include "devicedata.h"
DeviceData::DeviceData(QObject *parent)
        : QObject(parent) {
    qRegisterMetaType<DeviceData*>();
    currentScene=new scene(parent);
    std::map<int,string> values;
    values.insert(std::pair<int,string>(0,"Сцена 1"));
    values.insert(std::pair<int,string>(1,"Сцена 2"));
    values.insert(std::pair<int,string>(2,"Сцена 3"));
    values.insert(std::pair<int,string>(3,"Сцена 4"));
    curSceneVal = new SceneSelect(parent,values);
    recordingStatus=new RecordStatus(parent,false);
    translationStatus=new TranslationStatus(parent,false);
    pixelCorrection=new PixelCorrection(parent,false);
    ownAddress=new OwnIP(parent);
    gateAddress=new GateIp(parent);
    dateTime=new CurrentDate(parent);

}
DeviceData::~DeviceData(){
    saveData();
}
bool DeviceData::loadData(){return false;};
void DeviceData::saveData(){};
void DeviceData::checkStatuses(){
    btest1->checkStatuses();
    /*uint16_t status=I2CBus->checkKeys();
    cout<<status<<endl;
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
    }*/
    qDebug() << "update() called";
}
void DeviceData::start(){
    try{
        I2CBus=new I2CController(string("/dev/i2c-2"),string("/dev/ttymxc1"));
        cout<<1<<endl;
        btest1=new ButtonTest();
        btest1->setI2C(I2CBus);
        cout<<2<<endl;
        VideoBus=new VideoControllerBase();
        mWatcherStatuses= new QTimer(this);
        connect(mWatcherStatuses, &QTimer::timeout, this, &DeviceData::checkStatuses);
        mWatcherStatuses->start(100);
        if(loadData()){return;}
    }
    catch (exception& e) { cout << e.what() << endl; }
}
void DeviceData::finish(){
    std::cout<<"exit"<<std::endl;
    mWatcherStatuses->stop();
    delete VideoBus;
    delete I2CBus;
    delete btest1;
}
/*Getters for properties*/
bool DeviceData::saveCurScene(unsigned int number){
    if(number>scenes.size()){return true;}
    //scenes.at(number)=currentScene;
    return false;
}
bool DeviceData::loadCurScene(unsigned int number){
    //cscene tempscene;
    if(number>scenes.size()){return true;}
    //tempscene= scenes.at(number);

    return false;
}
void DeviceData::writeDate(int val){(I2CBus->date())->setDate();};

/*Setters for properties*/
