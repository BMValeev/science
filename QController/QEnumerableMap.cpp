//
// Created by eleps on 18.07.19.
//

#include "QEnumerableMap.h"
QEnumerableMap::QEnumerableMap(QObject *parent,QString mainName)
        : QObject(parent) {
    paramName=mainName;
    loadData(paramName);
    return;
}
QEnumerableMap::QEnumerableMap(QObject *parent,QString mainName,std::map<int,string> val)
        : QObject(parent){
    paramName=mainName;
    for (auto it = val.begin(); it != val.end(); ++it) {
        names.append(QString::fromStdString((*it).second));
        param.push_back((*it).first);
    }
    max=val.size()-1;
    min=0;
}

void QEnumerableMap::writeCurValue(unsigned int value){
    if((val>max)||(val<min)) {return;}
    if(setParam(param.at(val))){return;}
    val = value;
    curValueChanged(val);
    return;
};
bool QEnumerableMap::loadData(QString val){return false;};
QString QEnumerableMap::saveData(){return paramName;};


QEnumerableInt::QEnumerableInt(QObject *parent,QString mainName)
        : QObject(parent){
    paramName=mainName;
    qRegisterMetaType<QEnumerableInt*>();
    loadData(paramName);
    return;
}
QEnumerableInt::QEnumerableInt(QObject *parent,QString mainName,unsigned int minimalValue,unsigned int maximalValue)
        : QObject(parent){
    paramName=mainName;
    min=minimalValue;
    max=maximalValue;
    qRegisterMetaType<QEnumerableInt*>();
    return;
}
void QEnumerableInt::writeVal(unsigned int val){
    if((val>max)||(val<min)) {return;}
    if(setParam(val)){return;}
    value = val;
    curValChanged(value);
    return;
};
bool QEnumerableInt::loadData(QString val){return false;};
QString QEnumerableInt::saveData(){return paramName;};


QEnumerableBool::QEnumerableBool(QObject *parent,QString mainName)
        : QObject(parent){
    paramName=mainName;
    loadData(paramName);
    return;
}
QEnumerableBool::QEnumerableBool(QObject *parent,QString mainName,bool curVal)
        : QObject(parent){
    paramName=mainName;
    value=curVal;
    return;
}
void QEnumerableBool::writeVal(bool val){
    if(setParam(val)){return;}
    value = val;
    curValChanged(value);
    return;
};
bool QEnumerableBool::loadData(QString val){return false;};
QString QEnumerableBool::saveData(){return paramName;};

QEnumerableDate::QEnumerableDate(QObject *parent,QString mainName)
        : QObject(parent){
    paramName=mainName;
    loadData(paramName);
    return;
}
void QEnumerableDate::writeMin(int val){
    if(setParam()){return;}
    l_min = val;
    minChanged(l_min);
    return;
};
void QEnumerableDate::writeHour(int val){
    if(setParam()){return;}
    l_hour = val;
    hourChanged(l_hour);
    return;
};
void QEnumerableDate::writeDay(int val){
    if(setParam()){return;}
    l_day = val;
    dayChanged(l_day);
    return;
};
void QEnumerableDate::writeMonth(int val){
    if(setParam()){return;}
    l_month = val;
    monthChanged(l_month);
    return;
};
void QEnumerableDate::writeYear(int val){
    if(setParam()){return;}
    l_year = val;
    yearChanged(l_year);
    return;
};
bool QEnumerableDate::loadData(QString val){return false;};
QString QEnumerableDate::saveData(){return paramName;};




QEnumerableIP::QEnumerableIP(QObject *parent,QString mainName)
        : QObject(parent){
    paramName=mainName;
    loadData(paramName);
    return;
}
void QEnumerableIP::writeByte1(unsigned char val){
    if(setParam()){return;}
    val1 = val;
    byte1Changed(val1);
    return;
};
QString QEnumerableIP::getString(){
    return QString::fromStdString(std::to_string(val1)+"."+
        std::to_string(val2)+"."+
        std::to_string(val3)+"."+
        std::to_string(val4));
}
void QEnumerableIP::writeByte2(unsigned char val){
    if(setParam()){return;}
    val2 = val;
    byte1Changed(val2);
    return;
};
void QEnumerableIP::writeByte3(unsigned char val){
    if(setParam()){return;}
    val3 = val;
    byte1Changed(val3);
    return;
};
void QEnumerableIP::writeByte4(unsigned char val){
    if(setParam()){return;}
    val4 = val;
    byte1Changed(val4);
    return;
};
bool QEnumerableIP::loadData(QString val){return false;};
QString QEnumerableIP::saveData(){return paramName;};
