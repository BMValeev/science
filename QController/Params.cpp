//
// Created by eleps on 18.07.19.
//

#include "Params.h"
SceneSelect::SceneSelect(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"SceneSelect",val){qRegisterMetaType<GammaValue*>();}
SceneSelect::SceneSelect(QObject *parent): QEnumerableMap(parent,"SceneSelect"){qRegisterMetaType<SceneSelect*>();}
bool SceneSelect::setParam(unsigned int val) {    return false;};

WhiteBalance::WhiteBalance(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"WhiteBalance",val){qRegisterMetaType<GammaValue*>();}
WhiteBalance::WhiteBalance(QObject *parent): QEnumerableMap(parent,"WhiteBalance"){qRegisterMetaType<WhiteBalance*>();}
bool WhiteBalance::setParam(unsigned int val) {return false;};

Exposure::Exposure(QObject *parent,std::map<int,string> val) : QEnumerableMap(parent,"Exposure",val){qRegisterMetaType<Exposure*>();}
Exposure::Exposure(QObject *parent): QEnumerableMap(parent,"Exposure"){qRegisterMetaType<Exposure*>();}
bool Exposure::setParam(unsigned int val) {return false;};

AERegion::AERegion(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"AERegion",val){qRegisterMetaType<AERegion*>();}
AERegion::AERegion(QObject *parent): QEnumerableMap(parent,"AERegion"){qRegisterMetaType<AERegion*>();}
bool AERegion::setParam(unsigned int val) {return false;};

ImageSize::ImageSize(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"ImageSize",val){qRegisterMetaType<ImageSize*>();}
ImageSize::ImageSize(QObject *parent): QEnumerableMap(parent,"ImageSize"){qRegisterMetaType<ImageSize*>();}
bool ImageSize::setParam(unsigned int val) {return false;};

ImageRate::ImageRate(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"ImageRate",val){qRegisterMetaType<ImageRate*>();}
ImageRate::ImageRate(QObject *parent): QEnumerableMap(parent,"ImageRate"){qRegisterMetaType<ImageRate*>();}
bool ImageRate::setParam(unsigned int val) {return false;};

Buttons::Buttons(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"Buttons",val){qRegisterMetaType<Buttons*>();}
Buttons::Buttons(QObject *parent): QEnumerableMap(parent,"Buttons"){qRegisterMetaType<Buttons*>();}
bool Buttons::setParam(unsigned int val) {return false;};

RecordQuality::RecordQuality(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"RecordQuality",val){qRegisterMetaType<RecordQuality*>();}
RecordQuality::RecordQuality(QObject *parent): QEnumerableMap(parent,"RecordQuality"){qRegisterMetaType<RecordQuality*>();}
bool RecordQuality::setParam(unsigned int val) {return false;};

RecordName::RecordName(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"RecordName",val){qRegisterMetaType<RecordName*>();}
RecordName::RecordName(QObject *parent): QEnumerableMap(parent,"RecordName"){qRegisterMetaType<RecordName*>();}
bool RecordName::setParam(unsigned int val) {return false;};

PhotoName::PhotoName(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"PhotoName",val){qRegisterMetaType<PhotoName*>();}
PhotoName::PhotoName(QObject *parent): QEnumerableMap(parent,"PhotoName"){qRegisterMetaType<PhotoName*>();}
bool PhotoName::setParam(unsigned int val) {return false;};

IPMethod::IPMethod(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"IPMethod",val){qRegisterMetaType<IPMethod*>();}
IPMethod::IPMethod(QObject *parent): QEnumerableMap(parent,"IPMethod"){qRegisterMetaType<IPMethod*>();}
bool IPMethod::setParam(unsigned int val) {return false;};

Language::Language(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"Language",val){qRegisterMetaType<Language*>();}
Language::Language(QObject *parent): QEnumerableMap(parent,"Language"){qRegisterMetaType<Language*>();}
bool Language::setParam(unsigned int val) {return false;};

MessageVersion::MessageVersion(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"MessageVersion",val){qRegisterMetaType<MessageVersion*>();}
MessageVersion::MessageVersion(QObject *parent): QEnumerableMap(parent,"MessageVersion"){qRegisterMetaType<MessageVersion*>();}
bool MessageVersion::setParam(unsigned int val) {return false;};

RecordSize::RecordSize(QObject *parent,std::map<int,string> val): QEnumerableMap(parent,"RecordSize",val){qRegisterMetaType<RecordSize*>();}
RecordSize::RecordSize(QObject *parent): QEnumerableMap(parent,"RecordSize"){qRegisterMetaType<RecordSize*>();}
bool RecordSize::setParam(unsigned int val) {return false;};


AETarget::AETarget(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"AETarget",minimalValue,maximalValue){qRegisterMetaType<AETarget*>();}
AETarget::AETarget(QObject *parent): QEnumerableInt(parent,"AETarget"){qRegisterMetaType<AETarget*>();}
bool AETarget::setParam(unsigned int val) {return false;};

GammaValue::GammaValue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"GammaValue",minimalValue,maximalValue){qRegisterMetaType<GammaValue*>();}
GammaValue::GammaValue(QObject *parent): QEnumerableInt(parent,"GammaValue"){qRegisterMetaType<GammaValue*>();}
bool GammaValue::setParam(unsigned int val) {return false;};

WBRed::WBRed(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"WBRed",minimalValue,maximalValue){qRegisterMetaType<WBRed*>();}
WBRed::WBRed(QObject *parent): QEnumerableInt(parent,"WBRed"){qRegisterMetaType<WBRed*>();}
bool WBRed::setParam(unsigned int val) {return false;};

WBBlue::WBBlue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"WBBlue",minimalValue,maximalValue){qRegisterMetaType<WBBlue*>();}
WBBlue::WBBlue(QObject *parent): QEnumerableInt(parent,"WBBlue"){qRegisterMetaType<WBBlue*>();}
bool WBBlue::setParam(unsigned int val) {return false;};

ColorGain::ColorGain(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"ColorGain",minimalValue,maximalValue){qRegisterMetaType<ColorGain*>();}
ColorGain::ColorGain(QObject *parent): QEnumerableInt(parent,"ColorGain"){qRegisterMetaType<ColorGain*>();}
bool ColorGain::setParam(unsigned int val) {return false;};

HueValue::HueValue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"HueValue",minimalValue,maximalValue){qRegisterMetaType<HueValue*>();}
HueValue::HueValue(QObject *parent): QEnumerableInt(parent,"HueValue"){qRegisterMetaType<HueValue*>();}
bool HueValue::setParam(unsigned int val) {return false;};

ContrastValue::ContrastValue(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"ContrastValue",minimalValue,maximalValue){qRegisterMetaType<ContrastValue*>();}
ContrastValue::ContrastValue(QObject *parent): QEnumerableInt(parent,"ContrastValue"){qRegisterMetaType<ContrastValue*>();}
bool ContrastValue::setParam(unsigned int val) {return false;};

SharpGain::SharpGain(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"SharpGain",minimalValue,maximalValue){qRegisterMetaType<SharpGain*>();}
SharpGain::SharpGain(QObject *parent): QEnumerableInt(parent,"SharpGain"){qRegisterMetaType<SharpGain*>();}
bool SharpGain::setParam(unsigned int val) {return false;};

BrightGain::BrightGain(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"BrightGain",minimalValue,maximalValue){qRegisterMetaType<BrightGain*>();}
BrightGain::BrightGain(QObject *parent): QEnumerableInt(parent,"BrightGain"){qRegisterMetaType<BrightGain*>();}
bool BrightGain::setParam(unsigned int val) {return false;};

Volume::Volume(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"Volume",minimalValue,maximalValue){qRegisterMetaType<Volume*>();}
Volume::Volume(QObject *parent): QEnumerableInt(parent,"Volume"){qRegisterMetaType<Volume*>();}
bool Volume::setParam(unsigned int val) {return false;};

OwnPort::OwnPort(QObject *parent,unsigned int minimalValue,unsigned int maximalValue): QEnumerableInt(parent,"OwnPort",minimalValue,maximalValue){qRegisterMetaType<OwnPort*>();}
OwnPort::OwnPort(QObject *parent): QEnumerableInt(parent,"OwnPort"){qRegisterMetaType<OwnPort*>();}
bool OwnPort::setParam(unsigned int val) {return false;};

RecordStatus::RecordStatus(QObject *parent,bool curVal): QEnumerableBool(parent,"RecordStatus",curVal){qRegisterMetaType<RecordStatus*>();}
RecordStatus::RecordStatus(QObject *parent): QEnumerableBool(parent,"RecordStatus"){qRegisterMetaType<RecordStatus*>();}
bool RecordStatus::setParam(bool val) {return false;};

USBMount::USBMount(QObject *parent,bool curVal): QEnumerableBool(parent,"USBMount",curVal){qRegisterMetaType<USBMount*>();}
USBMount::USBMount(QObject *parent): QEnumerableBool(parent,"USBMount"){qRegisterMetaType<USBMount*>();}
bool USBMount::setParam(bool val) {return false;};

TranslationStatus::TranslationStatus(QObject *parent,bool curVal): QEnumerableBool(parent,"TranslationStatus",curVal){qRegisterMetaType<TranslationStatus*>();}
TranslationStatus::TranslationStatus(QObject *parent): QEnumerableBool(parent,"TranslationStatus"){qRegisterMetaType<TranslationStatus*>();}
bool TranslationStatus::setParam(bool val) {return false;};

PixelCorrection::PixelCorrection(QObject *parent,bool curVal): QEnumerableBool(parent,"PixelCorrection",curVal){qRegisterMetaType<PixelCorrection*>();}
PixelCorrection::PixelCorrection(QObject *parent): QEnumerableBool(parent,"PixelCorrection"){qRegisterMetaType<PixelCorrection*>();}
bool PixelCorrection::setParam(bool val) {return false;};

GammaStatus::GammaStatus(QObject *parent,bool curVal): QEnumerableBool(parent,"GammaStatus",curVal){qRegisterMetaType<GammaStatus*>();}
GammaStatus::GammaStatus(QObject *parent): QEnumerableBool(parent,"GammaStatus"){qRegisterMetaType<GammaStatus*>();}
bool GammaStatus::setParam(bool val) {return false;};

OwnIP::OwnIP(QObject *parent): QEnumerableIP(parent,"OwnIP"){qRegisterMetaType<OwnIP*>();}
bool OwnIP::setParam() {return false;};

GateIp::GateIp(QObject *parent): QEnumerableIP(parent,"GateIp"){qRegisterMetaType<GateIp*>();}
bool GateIp::setParam() {return false;};

CurrentDate::CurrentDate(QObject *parent): QEnumerableDate(parent,"CurrentDate"){qRegisterMetaType<CurrentDate*>();}
bool CurrentDate::setParam() {return false;};

