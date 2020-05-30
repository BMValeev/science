//
// Created by eleps on 18.07.19.
//

#ifndef MENUCAMERAFHD_PARAMS_H
#define MENUCAMERAFHD_PARAMS_H
#include "QEnumerableMap.h"
#include <linux/input.h>
#include <linux/uinput.h>
#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QList>

class SceneSelect: public QEnumerableMap{
public:
    SceneSelect(QObject *parent,std::map<int,string> val);
    SceneSelect(QObject *parent);
    ~SceneSelect(){saveData();}

private:
    bool setParam(unsigned int val) override;
};
class WhiteBalance: public QEnumerableMap{
public:
    WhiteBalance(QObject *parent,std::map<int,string> val);
    WhiteBalance(QObject *parent);
    ~WhiteBalance(){saveData();}

private:
    bool setParam(unsigned int val) override;
};
class Exposure: public QEnumerableMap{
public:
    Exposure(QObject *parent,std::map<int,string> val);
    Exposure(QObject *parent);
    ~Exposure(){saveData();}

private:
    bool setParam(unsigned int val) override;
};
class AERegion: public QEnumerableMap{
public:
    AERegion(QObject *parent,std::map<int,string> val);
    AERegion(QObject *parent);
    ~AERegion(){saveData();}

private:
    bool setParam(unsigned int val) override;
};
class ImageSize: public QEnumerableMap{
public:
    ImageSize(QObject *parent,std::map<int,string> val);
    ImageSize(QObject *parent);
    ~ImageSize(){saveData();}

private:
    bool setParam(unsigned int val) override;
};
class ImageRate: public QEnumerableMap{
public:
    ImageRate(QObject *parent,std::map<int,string> val);
    ImageRate(QObject *parent);
    ~ImageRate(){saveData();}

private:
    bool setParam(unsigned int val) override;
};
class Buttons: public QEnumerableMap{
public:
    Buttons(QObject *parent,std::map<int,string> val);
    Buttons(QObject *parent); 
    ~Buttons(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};
class RecordQuality: public QEnumerableMap{
public:
    RecordQuality(QObject *parent,std::map<int,string> val);
    RecordQuality(QObject *parent); 
    ~RecordQuality(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};
class RecordName: public QEnumerableMap{
public:
    RecordName(QObject *parent,std::map<int,string> val);
    RecordName(QObject *parent); 
    ~RecordName(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};
class PhotoName: public QEnumerableMap{
public:
    PhotoName(QObject *parent,std::map<int,string> val);
    PhotoName(QObject *parent); 
    ~PhotoName(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};
class RecordSize: public QEnumerableMap{
public:
    RecordSize(QObject *parent,std::map<int,string> val);
    RecordSize(QObject *parent); 
    ~RecordSize(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};
class IPMethod: public QEnumerableMap{
public:
    IPMethod(QObject *parent,std::map<int,string> val);
    IPMethod(QObject *parent); 
    ~IPMethod(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};
class Language: public QEnumerableMap{
public:
    Language(QObject *parent,std::map<int,string> val);
    Language(QObject *parent); 
    ~Language(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};
class MessageVersion: public QEnumerableMap{
public:
    MessageVersion(QObject *parent,std::map<int,string> val);
    MessageVersion(QObject *parent); 
    ~MessageVersion(){saveData();} 

private:
    bool setParam(unsigned int val) override;
};

class AETarget: public QEnumerableInt{
Q_OBJECT
public:
    AETarget(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    AETarget(QObject *parent);
    ~AETarget(){saveData();}
private:
    bool setParam(unsigned int val) override;
};
class GammaValue: public QEnumerableInt{
Q_OBJECT
public:
    GammaValue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    GammaValue(QObject *parent); 
    ~GammaValue(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class WBRed: public QEnumerableInt{
public:
    WBRed(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    WBRed(QObject *parent); 
    ~WBRed(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class WBBlue: public QEnumerableInt{
public:
    WBBlue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    WBBlue(QObject *parent); 
    ~WBBlue(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class ColorGain: public QEnumerableInt{
public:
    ColorGain(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    ColorGain(QObject *parent); 
    ~ColorGain(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class HueValue: public QEnumerableInt{
public:
    HueValue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    HueValue(QObject *parent); 
    ~HueValue(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class ContrastValue: public QEnumerableInt{
public:
    ContrastValue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    ContrastValue(QObject *parent); 
    ~ContrastValue(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class SharpGain: public QEnumerableInt{
public:
    SharpGain(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    SharpGain(QObject *parent); 
    ~SharpGain(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class BrightGain: public QEnumerableInt{
public:
    BrightGain(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    BrightGain(QObject *parent); 
    ~BrightGain(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class Volume: public QEnumerableInt{
public:
    Volume(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    Volume(QObject *parent); 
    ~Volume(){saveData();} 
private:
    bool setParam(unsigned int val) override;
};
class OwnPort: public QEnumerableInt{
public:
    OwnPort(QObject *parent,unsigned int minimalValue,unsigned int maximalValue);
    OwnPort(QObject *parent);
    ~OwnPort(){saveData();}
private:
    bool setParam(unsigned int val) override;
};

class RecordStatus: public QEnumerableBool{
public:
    RecordStatus(QObject *parent,bool curVal);
    RecordStatus(QObject *parent);
    ~RecordStatus(){saveData();}
private:
    bool setParam(bool val) override;
};
class USBMount: public QEnumerableBool{
public:
    USBMount(QObject *parent,bool curVal);
    USBMount(QObject *parent);
    ~USBMount(){saveData();}
private:
    bool setParam(bool val) override;
};
class TranslationStatus: public QEnumerableBool{
public:
    TranslationStatus(QObject *parent,bool curVal);
    TranslationStatus(QObject *parent);
    ~TranslationStatus(){saveData();}
private:
    bool setParam(bool val) override;
};
class PixelCorrection: public QEnumerableBool{
public:
    PixelCorrection(QObject *parent,bool curVal);
    PixelCorrection(QObject *parent);
    ~PixelCorrection(){saveData();}
private:
    bool setParam(bool val) override;
};
class GammaStatus: public QEnumerableBool{
public:
    GammaStatus(QObject *parent,bool curVal);
    GammaStatus(QObject *parent);
    ~GammaStatus(){saveData();}
private:
    bool setParam(bool val) override;
};
class OwnIP: public QEnumerableIP{
public:
    OwnIP(QObject *parent);
    ~OwnIP(){saveData();}
private:
    bool setParam() override;
};
class GateIp: public QEnumerableIP{
public:
    GateIp(QObject *parent);
    ~GateIp(){saveData();}
private:
    bool setParam() override;
};

class CurrentDate: public QEnumerableDate{
public:
    CurrentDate(QObject *parent);
    ~CurrentDate(){saveData();}
private:
    bool setParam() override;
};




Q_DECLARE_METATYPE(SceneSelect*);
Q_DECLARE_METATYPE(WhiteBalance*);
Q_DECLARE_METATYPE(Exposure*);
Q_DECLARE_METATYPE(AETarget*);
Q_DECLARE_METATYPE(AERegion*);
Q_DECLARE_METATYPE(ImageSize*);
Q_DECLARE_METATYPE(ImageRate*);
Q_DECLARE_METATYPE(Buttons*);
Q_DECLARE_METATYPE(RecordQuality*);
Q_DECLARE_METATYPE(RecordName*);
Q_DECLARE_METATYPE(PhotoName*);
Q_DECLARE_METATYPE(RecordSize*);
Q_DECLARE_METATYPE(IPMethod*);
Q_DECLARE_METATYPE(Language*);
Q_DECLARE_METATYPE(MessageVersion*);
Q_DECLARE_METATYPE(GammaValue*);
Q_DECLARE_METATYPE(WBRed*);
Q_DECLARE_METATYPE(WBBlue*);
Q_DECLARE_METATYPE(ColorGain*);
Q_DECLARE_METATYPE(HueValue*);
Q_DECLARE_METATYPE(ContrastValue*);
Q_DECLARE_METATYPE(SharpGain*);
Q_DECLARE_METATYPE(BrightGain*);
Q_DECLARE_METATYPE(Volume*);
Q_DECLARE_METATYPE(OwnPort*);
Q_DECLARE_METATYPE(OwnIP*);
Q_DECLARE_METATYPE(GateIp*);
Q_DECLARE_METATYPE(CurrentDate*);
#endif //MENUCAMERAFHD_PARAMS_H
