//
// Created by eleps on 03.07.19.
//

#ifndef VIDEORECORDER_VIDEOCONTROLLERBASE_H
#define VIDEORECORDER_VIDEOCONTROLLERBASE_H

#include <mutex>
#include <vector>
#include <thread>
#include <string>
#include <comcpp/src/c_class/Rest/FlashCard.h>
#include <videofiles/VideoApp.h>
#include <videofiles/VideoRecord.h>
#include <videofiles/VideoShow.h>
#include <videofiles/VideoSnapshot.h>
#include <videofiles/VideoRecordTranslation.h>
#include <comcpp/src/c_class/Rest/loggable.h>
#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <Params.h>
#define MIN_FREE_SIZE           150.0
#define MIN_SNAP_SIZE           10.0
/*Statuses*/

class VideoControllerBase : public Loggable, public QObject{
    //
    //Q_OBJECT
    //Q_PROPERTY(QEnumerableInt* volume READ volume NOTIFY volumeChanged)


private:
    bool status;
public:
    VideoControllerBase();
    ~VideoControllerBase();


    enum Recording {STARTED_RECORD,STOPPED_RECORD,};
    enum USB_Mount {USB_MOUNTED,USB_UNMOUNTED,};
    enum Translating {STARTED_TRANSLATION,STOPPED_TRANSLATION,};
    bool getStatus(){ return status; }

    bool restartCamera();
    bool enableCamera();
    bool disableCamera();
    bool startRecord();
    bool stopRecord();
    bool makeSnapshot();
    bool startTranslation();
    bool stopTranslation();

    bool setRecordSize(RecordSize val);
    bool setRecordName(RecordName val);
    bool setPhotoName(PhotoName val);
    bool setRecordQuality(RecordQuality val);
    bool setIPaddress(OwnIP val);
    bool setIPGate(GateIp val);
    bool setPort(OwnPort val);
    bool setIPGateChoose(IPMethod val);

    float getFreeSize();
    float getUsedSize();
    float getMountPoint();
    bool mountUSB();
    bool unmountUSB();
    bool mountUSBStatus();

protected:
    bool begin( LogCallback cb = printToCout);
    std::string usbDevice,usbMount;
    VideoApp *mainApp;
    VideoInterface *snapshot, *recorder;
    void handleFlashSize();
};

#endif //VIDEORECORDER_VIDEOCONTROLLERBASE_H
