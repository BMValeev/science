#ifndef SCENE_H
#define SCENE_H

#include "string"
#include "comcpp/src/c_class/I2C/Fpga_fhd.h"
#include "comcpp/src/c_class/I2C/I2C.h"
#include "videocontrollerbase.h"
#include "i2ccontroller.h"
#include <linux/input.h>
#include <linux/uinput.h>
#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "Params.h"

using namespace std;
class scene: public QObject {
Q_OBJECT
    Q_PROPERTY(QEnumerableMap* whiteBalance READ whiteBalance NOTIFY whiteBalanceChanged)
    Q_PROPERTY(QEnumerableMap* exposition READ exposition NOTIFY expositionChanged)
    Q_PROPERTY(QEnumerableInt* areaAnalysis READ areaAnalysis NOTIFY areaAnalysisChanged)
    Q_PROPERTY(QEnumerableMap* areaRegion READ areaRegion NOTIFY areaRegionChanged)
    Q_PROPERTY(QEnumerableMap* imageParam READ imageParam NOTIFY imageParamChanged)
    Q_PROPERTY(QEnumerableMap* imageRate READ imageRate NOTIFY imageRateChanged)
    Q_PROPERTY(QEnumerableMap* recordQuality READ recordQuality NOTIFY recordQualityChanged)
    Q_PROPERTY(QEnumerableMap* recordName READ recordName  NOTIFY recordNameChanged)
    Q_PROPERTY(QEnumerableMap* photoName READ photoName  NOTIFY photoNameChanged)
    Q_PROPERTY(QEnumerableMap* recordSize READ recordSize NOTIFY recordSizeChanged)
    Q_PROPERTY(QEnumerableMap* buttons READ buttons NOTIFY buttonsChanged)
    Q_PROPERTY(QEnumerableMap* ipMethod READ ipMethod NOTIFY ipMethodChanged)
    Q_PROPERTY(QEnumerableMap* messageVersion READ messageVersion NOTIFY messageVersionChanged)
    Q_PROPERTY(QEnumerableMap* language READ language NOTIFY languageChanged)
    Q_PROPERTY(QEnumerableInt* gamma READ gamma NOTIFY gammaChanged)
    Q_PROPERTY(QEnumerableInt* wbred READ wbred NOTIFY wbredChanged)
    Q_PROPERTY(QEnumerableInt* wbblue READ wbblue NOTIFY wbblueChanged)
    Q_PROPERTY(QEnumerableInt* color READ color NOTIFY colorChanged)
    Q_PROPERTY(QEnumerableInt* hue READ hue NOTIFY hueChanged)
    Q_PROPERTY(QEnumerableInt* contrast READ contrast NOTIFY contrastChanged)
    Q_PROPERTY(QEnumerableInt* sharp READ sharp NOTIFY sharpChanged)
    Q_PROPERTY(QEnumerableInt* bright READ bright NOTIFY brightChanged)
    Q_PROPERTY(QEnumerableInt* volume READ volume NOTIFY volumeChanged)
    Q_PROPERTY(QEnumerableInt* port READ port NOTIFY portChanged)
    Q_PROPERTY(QEnumerableBool* gammaStatus READ gammaStatus NOTIFY curGammaStatusChanged)


     public:
    QEnumerableMap* whiteBalance(){return curWhiteBalance;}
    QEnumerableMap* exposition(){return curExposition;}

    QEnumerableMap* areaRegion(){return curAreaRegion;}
    QEnumerableMap* imageParam(){return curImageParam;}
    QEnumerableMap* imageRate(){return curImageRate;}
    QEnumerableMap* buttons(){return curButtons;}
    QEnumerableMap* recordQuality(){return curRecordQuality;}
    QEnumerableMap* recordName(){return curRecordName;}
    QEnumerableMap* photoName(){return curPhotoName;}
    QEnumerableMap* recordSize(){return curRecordSize;}
    QEnumerableMap* ipMethod(){return curIPMethod;}
    QEnumerableMap* language(){return curLanguage;}
    QEnumerableMap* messageVersion(){return curMessageVersion;}

    QEnumerableInt* areaAnalysis(){return curAreaAnalysis;}
    QEnumerableInt* gamma(){return curGammaValue;}
    QEnumerableInt* wbred() {return curBalanceRed;};
    QEnumerableInt* wbblue() {return curBalanceBlue;};
    QEnumerableInt* color(){return curColorValue;};
    QEnumerableInt* hue(){return curHueValue;};
    QEnumerableInt* contrast(){return curContrastValue;};
    QEnumerableInt* sharp(){return curSharpValue;};
    QEnumerableInt* bright(){return curBrightValue;};
    QEnumerableInt* volume(){return curVolume;};
    QEnumerableInt* port(){return curPort;};

    QEnumerableBool* gammaStatus(){return curGammaStatus;};

    int curIPAddress(){return ipAdress;};
    int curIPGate(){return ipGate;};
    scene(QObject *parent);
    ~scene(){};
    int ipAdress;
    int ipGate;
private:
    GammaValue* curGammaValue;
    GammaStatus* curGammaStatus;

    WBRed* curBalanceRed;
    WBBlue* curBalanceBlue;
    ColorGain* curColorValue;
    HueValue* curHueValue;
    ContrastValue* curContrastValue;
    SharpGain* curSharpValue;
    BrightGain* curBrightValue;
    Volume* curVolume;
    OwnPort* curPort;
    WhiteBalance* curWhiteBalance;
    Exposure* curExposition;
    AETarget* curAreaAnalysis;
    AERegion* curAreaRegion;
    ImageSize* curImageParam;
    ImageRate* curImageRate;
    Buttons* curButtons;
    RecordQuality* curRecordQuality;
    RecordName* curRecordName;
    PhotoName* curPhotoName;
    RecordSize* curRecordSize;
    IPMethod* curIPMethod;
    Language* curLanguage;
    MessageVersion* curMessageVersion;

    VideoControllerBase* VideoBus;
    I2CController *I2CBus;
signals:
    void whiteBalanceChanged();
    void expositionChanged();
    void areaAnalysisChanged();
    void areaRegionChanged();
    void imageParamChanged();
    void imageRateChanged();
    void recordQualityChanged();
    void recordNameChanged();
    void photoNameChanged();
    void recordSizeChanged();
    void buttonsChanged();
    void ipMethodChanged();
    void messageVersionChanged();
    void languageChanged();
    void gammaChanged();
    void wbredChanged();
    void wbblueChanged();
    void colorChanged();
    void hueChanged();
    void contrastChanged();
    void sharpChanged();
    void brightChanged();
    void volumeChanged();
    void portChanged();
    void curGammaStatusChanged();
};
Q_DECLARE_METATYPE(scene*);
//class test{};
#endif // SCENE_H