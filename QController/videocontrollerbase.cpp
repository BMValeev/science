//
// Created by eleps on 03.07.19.
//

#include "videocontrollerbase.h"
#include "vector"
#include "iostream"
#define DEFAULT_MOUNT_POINT "/mnt/flash"
#define DEFAULT_PARTIRION_POINT "/dev/sda1"

#define MAX_COMMAND_LEN 5
#define NO_USB


VideoControllerBase::VideoControllerBase(){
    mainApp=new VideoApp();
    snapshot= new VideoSnapshot(mainApp);
    recorder = new VideoRecordTranslation(mainApp);
    begin();
#ifndef NO_USB
    usbDevice=DEFAULT_PARTIRION_POINT;
    usbMount=DEFAULT_MOUNT_POINT;
    FlashCard &usb_object = FlashCard::getInstance(usbDevice);
    usb_object.setMountPoint(usbMount);
    #endif
    status=true;
}
VideoControllerBase::~VideoControllerBase(){
    status=false;
    delete recorder;
    delete snapshot;
    delete mainApp;
#ifndef NO_USB
    delete usb_object;
#endif
}
bool VideoControllerBase::begin(LogCallback cb) {
    setLogCallback(cb);
    printLog(DebugLog, static_cast<std::string>(__func__) + " Initialized");
    return false;
}

bool VideoControllerBase::enableCamera(){
    if (mainApp->isEnabled()){return false;}
    if (mainApp->enableCamera()){return true;}
    return false;
}
bool VideoControllerBase::restartCamera(){
    if(mainApp->restartDevice()){return true;}
    return false;
}
bool VideoControllerBase::disableCamera(){
    if (!mainApp->isEnabled()){return false;}
    if(mainApp->disableCamera()){return true;}
    return false;
}

bool VideoControllerBase::startRecord(){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    FlashCard &usb_object = FlashCard::getInstance(DEFAULT_PARTIRION_POINT);
    if(usb_object.mountFlash()){return true;}
    if(!usb_object.checkFlashSize(MIN_FREE_SIZE)){return true;}
    if(f->startRecord()){return true;}
    return false;

}
bool VideoControllerBase::stopRecord(){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("Record"));
    if(f->stopRecord()){return true;}
    FlashCard &usb_object = FlashCard::getInstance(DEFAULT_PARTIRION_POINT);
    usb_object.unmountFlash();
    return false;
}
bool VideoControllerBase::makeSnapshot(){
    VideoSnapshot *f=dynamic_cast<VideoSnapshot *>(mainApp->getChild("Photo"));
    FlashCard &usb_object = FlashCard::getInstance(DEFAULT_PARTIRION_POINT);
    if(usb_object.mountFlash()){return true;}
    if(f==nullptr) {return true;}
    if(f->makeSnapshot()){return true;}
    sleep(1);
    return false;
}
bool VideoControllerBase::startTranslation(){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    if(f->startTranslation()){return true;}
    return false;
}
bool VideoControllerBase::stopTranslation(){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("Record"));
    if(f->stopTranslation()){return true;}
    return false;
}
void VideoControllerBase::handleFlashSize(){
    FlashCard &usb_object = FlashCard::getInstance(DEFAULT_PARTIRION_POINT);
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    if(f->isRecording()){
        if(usb_object.isMounted()){stopRecord();}
        if(!usb_object.checkFlashSize(MIN_FREE_SIZE)){stopRecord();}
    }
}
bool VideoControllerBase::setRecordSize(RecordSize val){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    return f->setSize(val.curValue());
};
bool VideoControllerBase::setRecordName(RecordName val){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    return f->setName(val.curValue());
};
bool VideoControllerBase::setPhotoName(PhotoName val){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    return f->setName(val.curValue());
};
bool VideoControllerBase::setRecordQuality(RecordQuality val){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    return f->setQuality(val.curValue());
};
bool VideoControllerBase::setIPGateChoose(IPMethod val){ //!!!!!!!!!!!
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    //return f->setIP(val);
    return false;
};
bool VideoControllerBase::setIPaddress(OwnIP val){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    return f->setIP(val.getString().toStdString());
};
bool VideoControllerBase::setIPGate(GateIp val){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    return f->setIP(val.getString().toStdString());
};
bool VideoControllerBase::setPort(OwnPort val){
    VideoRecordTranslation *f=dynamic_cast<VideoRecordTranslation *>(mainApp->getChild("RecordTranslation"));
    return f->setPort(val.val());
};
//done&
bool VideoControllerBase::mountUSB(){
    FlashCard &usb_object = FlashCard::getInstance(usbDevice);
    return (usb_object.mountFlash());
}
bool VideoControllerBase::unmountUSB(){
    FlashCard &usb_object = FlashCard::getInstance(usbDevice);
    return (usb_object.unmountFlash());
}
bool VideoControllerBase::mountUSBStatus(){
    FlashCard &usb_object = FlashCard::getInstance(usbDevice);
    return usb_object.isMounted();
}
//make later
float VideoControllerBase::getFreeSize(){
    FlashCard &usb_object = FlashCard::getInstance(DEFAULT_PARTIRION_POINT);
    return usb_object.checkFlashSize();
}
float VideoControllerBase::getUsedSize(){
    FlashCard &usb_object = FlashCard::getInstance(DEFAULT_PARTIRION_POINT);
    return usb_object.checkFlashSize();
}
float VideoControllerBase::getMountPoint(){
    FlashCard &usb_object = FlashCard::getInstance(DEFAULT_PARTIRION_POINT);
    return usb_object.checkFlashSize();
}

