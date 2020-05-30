#ifndef DEVICEDATA_H
#define DEVICEDATA_H

//#include "scene.h"
#include "vector"
#include <string>
#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include "ButtonTest.h"
#include "i2ccontroller.h"


class DeviceData : public QObject {
    Q_OBJECT
    Q_PROPERTY(scene* cscene READ cscene NOTIFY sceneChanged)
    Q_PROPERTY(QEnumerableMap* curScene READ curScene  NOTIFY curSceneChanged)
    Q_PROPERTY(QEnumerableBool* curRecord READ curRecord NOTIFY curRecordChanged)
    Q_PROPERTY(QEnumerableBool* translStatus READ translStatus NOTIFY translStatusChanged)
    Q_PROPERTY(QEnumerableBool* pixCorrection READ pixCorrection NOTIFY pixCorrectionChanged)
    Q_PROPERTY(QEnumerableIP* ownIP READ ownIP NOTIFY ownIPnChanged)
    Q_PROPERTY(QEnumerableIP* gateIP READ gateIP NOTIFY gateIPnChanged)
    Q_PROPERTY(QEnumerableDate* date READ date NOTIFY dateChanged)
    Q_PROPERTY(ButtonTest* btest READ btest NOTIFY btestChanged)

public:

    explicit DeviceData(QObject *parent = nullptr);
    ~DeviceData();
    bool loadData();
    void saveData();
    bool saveCurScene(unsigned int number);
    bool loadCurScene(unsigned int number);
    scene* currentScene;
    scene* cscene(){return currentScene;}
    ButtonTest* btest(){return btest1;}
    QEnumerableBool* curRecord(){return recordingStatus;}
    QEnumerableBool* translStatus(){return translationStatus;}
    QEnumerableBool* pixCorrection(){ return pixelCorrection;}
    QEnumerableMap* curScene(void){return curSceneVal;};
    int curDate(){return (I2CBus->date())->getDate();};


    QEnumerableIP* ownIP(){return ownAddress;};
    QEnumerableIP* gateIP(){return gateAddress;};
    QEnumerableDate* date(){return dateTime;};
signals:
    void btestChanged();
    void curRecordChanged ();
    void translStatusChanged();
    void pixCorrectionChanged();
    void ownIPnChanged();
    void gateIPnChanged();
    void dateChanged();
    void curSceneChanged ();
    void sceneChanged(scene *scene);


protected:
    ButtonTest* btest1;
    RecordStatus* recordingStatus;
    TranslationStatus* translationStatus;
    PixelCorrection* pixelCorrection;
    OwnIP* ownAddress;
    GateIp* gateAddress;
    CurrentDate* dateTime;

    SceneSelect* curSceneVal;
    vector<scene* > scenes;
    I2CController *I2CBus;
    VideoControllerBase* VideoBus;
    QTimer* mWatcherStatuses;

private slots:
    void checkStatuses();
public slots:
    void finish();
    void start();
    void writeDate(int val);


};
Q_DECLARE_METATYPE(DeviceData*);
#endif // DEVICEDATA_H