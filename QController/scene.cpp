#include "scene.h"

scene::scene(QObject *parent):QObject(parent) {
    qRegisterMetaType<scene*>();
    curGammaValue=new GammaValue(parent,0,100);
    curGammaStatus=new GammaStatus(parent,false);
    curColorValue=new ColorGain(parent,0,100);
    curHueValue=new HueValue(parent,0,100);
    curContrastValue=new ContrastValue(parent,0,100);
    curSharpValue=new SharpGain(parent,0,100);
    curBrightValue=new BrightGain(parent,0,100);
    curVolume=new Volume(parent,0,100);
    curPort=new OwnPort(parent,100,10000);
    curBalanceRed = new WBRed(parent,0,100);
    curBalanceBlue = new WBBlue(parent,0,100);
    curAreaAnalysis = new AETarget(parent,0,100);
    /*Manual data selection*/
    std::map<int,string> values;
    values.insert(std::pair<int,string>(0,"Push lock"));
    values.insert(std::pair<int,string>(1,"Auto"));
    values.insert(std::pair<int,string>(2,"Manual"));
    curWhiteBalance = new WhiteBalance(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Auto"));
    values.insert(std::pair<int,string>(1,"Manual"));
    curExposition = new Exposure(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Spot"));
    values.insert(std::pair<int,string>(1,"Center"));
    values.insert(std::pair<int,string>(2,"Wide"));
    curAreaRegion = new AERegion(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"1920x1080"));
    values.insert(std::pair<int,string>(1,"1280x720"));
    curImageParam = new ImageSize(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Полнострочная"));
    values.insert(std::pair<int,string>(1,"Черезстрочная"));
    curImageRate = new ImageRate(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Баланс Белого + Снимок"));
    values.insert(std::pair<int,string>(1,"Снимок + Запись"));
    values.insert(std::pair<int,string>(2,"Стоп + Снимок"));
    values.insert(std::pair<int,string>(3,"Яркость"));
    values.insert(std::pair<int,string>(4,"Четкость"));
    values.insert(std::pair<int,string>(5,"Констраст"));
    values.insert(std::pair<int,string>(6,"Усиление"));
    curButtons = new Buttons(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(30,"Низкое"));
    values.insert(std::pair<int,string>(21,"Среднее"));
    values.insert(std::pair<int,string>(15,"Высокое"));
    curRecordQuality = new RecordQuality(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(500000,"500МБ"));
    values.insert(std::pair<int,string>(1000000,"1000МБ"));
    values.insert(std::pair<int,string>(2000000,"2000МБ"));
    curRecordSize = new RecordSize(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Статический"));
    values.insert(std::pair<int,string>(1,"Динамическй"));
    curIPMethod = new IPMethod(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Русский"));
    values.insert(std::pair<int,string>(1,"English"));
    curLanguage = new Language(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Короткие сообщения"));
    values.insert(std::pair<int,string>(1,"Полные сообщения"));
    curMessageVersion = new MessageVersion(parent,values);
    values.clear();
    values.insert(std::pair<int,string>(0,"Д_М_Г_Ч_М"));
    values.insert(std::pair<int,string>(1,"М_Д_Г_Ч_М"));
    values.insert(std::pair<int,string>(2,"Ч_М_С_Д_М_Г"));
    values.insert(std::pair<int,string>(3,"Ч_М_С_Д_М"));
    values.insert(std::pair<int,string>(4,"Г_М_Д_Ч_М_С"));
    curRecordName= new RecordName(parent,values);
    curPhotoName= new PhotoName(parent,values);

}
/*
void cscene::writeWhiteBalance(Fpga_fhd::WhiteBalance val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->whiteBalance(data,response)!=OK_I2C){return;}
    curWhiteBalanceChanged(val);
    whiteBalance=val;
};

void cscene::writeExposition(Fpga_fhd::Exposure val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setExposition(data,response)!=OK_I2C){return;}
    curExpositionChanged(val);
    exposition=val;
};
void cscene::writeAreaExposition(Fpga_fhd::AETarget val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setAnalysisSurface(data,response)!=OK_I2C){return;}
    curAreaExpositionChanged(val);
    expositionArea=val;
};
void cscene::writeImageSize(Fpga_fhd::ImageSize val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setResolution(data,response)!=OK_I2C){return;}
    curImageSizeChanged(val);
    imageParam=val;
};
void cscene::writeRecordQuality(VideoControllerBase::RecordQuality val){VideoBus->setRecordQuality(val);};
void cscene::writeRecordName(VideoControllerBase::Name val){VideoBus->setRecordName(val);};
void cscene::writePhotoName(VideoControllerBase::Name val){VideoBus->setPhotoName(val);};
void cscene::writeRecordSize(VideoControllerBase::RecordSize val){VideoBus->setRecordSize(val);};
void cscene::writeIPMethod(VideoControllerBase::IPChoose val){VideoBus->setIPGateChoose(val);};
void cscene::writeLang(Language val){};

void cscene::writeMessagesVersion(MessageVersion val){};
void cscene::writePreset(Buttons val){
    switch(val){
        case cscene::PRESET_WB_SN: I2CBus->writeButtons(WB,SN); break;
        case cscene::PRESET_SN_RD: I2CBus->writeButtons(SN,RECORD); break;
        case cscene::PRESET_BRIGHTNESS: I2CBus->writeButtons(BRIGHT_DOWN,BRIGHT_UP); break;
        case cscene::PRESET_CONTRAST: I2CBus->writeButtons(CONTRAST_DOWN,CONTRAST_UP); break;
        case cscene::PRESET_SHARPNESS: I2CBus->writeButtons(SHARP_DOWN,SHARP_UP); break;
        case cscene::PRESET_GAIN: I2CBus->writeButtons(GAIN_DOWN,GAIN_UP); break;
        default:break;
    }
    preset=val;
};
*//*
void cscene::writeWBRed(unsigned int val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setRed(data,response)!=OK_I2C){return;}
    curWBRedChanged(val);
    whiteBalanceBlue=val;
};
void cscene::writeWBBlue(unsigned int val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setBlue(data,response)!=OK_I2C){return;}
    curWBBlueChanged(val);
    whiteBalanceBlue=val;
};
void cscene::writeColorGain(unsigned int val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setColor(data,response)!=OK_I2C){return;}
    curColorGainChanged(val);
    colorValue=val;
};
void cscene::writeHue(unsigned int val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setHue(data,response)!=OK_I2C){return;}
    curHueChanged(val);
    hueValue=val;
};
void cscene::writeSharpGain(unsigned int val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setSharpness(data,response)!=OK_I2C){return;}
    curSharpGainChanged(val);
    sharpValue=val;
};
void cscene::writeBrightGain(unsigned int val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setBrightness(data,response)!=OK_I2C){return;}
    curBrightGainChanged(val);
    brightValue=val;
};
void cscene::writeGammaValue(unsigned int val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    //if(I2CBus->fpga()->setGammaRate(data,response)!=OK_I2C){return;}
    gammaCorrValue=val;
    std::cout<<val<<std::endl;
    curGammaValueChanged(val);
};
void cscene::writeGammaStatus(Fpga_fhd::GammaCorr val){
    std::vector<uint8_t> response,data;
    data.push_back(static_cast<uint8_t>(val));
    if(I2CBus->fpga()->setGamma(data,response)!=OK_I2C){return;}
    curGammaStatusChanged(val);
    gammaCorrStatus=val;
};
void cscene::writeIPAddress(int val){VideoBus->setIPaddress(val);};
void cscene::writeIPGate(int val){VideoBus->setIPGate(val);};
void cscene::writeVolume(unsigned int val){I2CBus->board();};*/



