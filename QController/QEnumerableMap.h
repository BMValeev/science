//
// Created by eleps on 18.07.19.
//

#ifndef MENUCAMERAFHD_QENUMERABLEMAP_H
#define MENUCAMERAFHD_QENUMERABLEMAP_H
//#include "videocontrollerbase.h"
#include <string>
#include <iostream>
#include <QObject>
#include <QString>
#include <QList>
#include <QThread>
#include <QDebug>
using namespace std;
class QEnumerableMap: public QObject{
    Q_OBJECT
    Q_PROPERTY(unsigned int curValue READ curValue WRITE writeCurValue  NOTIFY curValueChanged)
    Q_PROPERTY(unsigned int maxValue READ maxValue)
    Q_PROPERTY(unsigned int minValue READ minValue)
    Q_PROPERTY(QList<QString> allNames READ allNames)
public: /*Constructors and destructors*/
    QEnumerableMap(QObject *parent,QString mainName,std::map<int,string> val);
    QEnumerableMap(QObject *parent,QString mainName);
    QEnumerableMap(QObject *parent);
    ~QEnumerableMap(){saveData();}
public slots:
    unsigned int curValue(void){return val;};
    unsigned int maxValue(void){return max;};
    QList<QString> allNames(void){return names;};
    unsigned int minValue(void){return min;};
    void writeCurValue(unsigned int value);
    virtual bool setParam(unsigned int val)=0;
    signals:
    void curValueChanged(unsigned int val);
protected:
    QList<QString>   names={};
    vector<int> param;
    QString paramName;
    unsigned int val=0;
    unsigned int max=0;
    unsigned int min=0;
    bool loadData(QString val);
    QString saveData(void);
};
class QEnumerableInt: public QObject{
Q_OBJECT
    Q_PROPERTY(unsigned int val READ val WRITE writeVal  NOTIFY curValChanged)
    Q_PROPERTY(unsigned int maxVal READ maxVal)
    Q_PROPERTY(unsigned int minVal READ minVal)
public:
    QEnumerableInt(QObject *parent,QString mainName,unsigned int minimalValue,unsigned int maximalValue);
    QEnumerableInt(QObject *parent,QString mainName);
    QEnumerableInt(QObject *parent);
    ~QEnumerableInt(){saveData();}
public slots:
    unsigned int val(void){return value;};
    unsigned int maxVal(void){return max;};
    unsigned int minVal(void){return min;};
    void writeVal(unsigned int val);
    bool setParam(unsigned int val){return false;};
signals:
    void curValChanged(unsigned int val);
protected:
    QString paramName;
    unsigned int value=0;
    unsigned int max=0;
    unsigned int min=0;
    bool loadData(QString val);
    QString saveData(void);
};
class QEnumerableBool: public QObject{
Q_OBJECT
    Q_PROPERTY(bool val READ val WRITE writeVal  NOTIFY curValChanged)
public:
    QEnumerableBool(QObject *parent,QString mainName,bool curVal);
    QEnumerableBool(QObject *parent,QString mainName);
    QEnumerableBool(QObject *parent);
    ~QEnumerableBool(){saveData();}
public slots:
    bool val(void){return value;};
    void writeVal(bool val);
    virtual bool setParam(bool val){return false;}
signals:
    void curValChanged(bool val);
protected:
    QString paramName;
    bool value=false;
    bool loadData(QString val);
    QString saveData(void);
};
class QEnumerableDate: public QObject{
Q_OBJECT
    Q_PROPERTY(int min READ min WRITE writeMin  NOTIFY minChanged)
    Q_PROPERTY(int hour READ hour WRITE writeHour  NOTIFY hourChanged)
    Q_PROPERTY(int day READ day WRITE writeDay  NOTIFY dayChanged)
    Q_PROPERTY(int month READ month WRITE writeMonth  NOTIFY monthChanged)
    Q_PROPERTY(int year READ year WRITE writeYear  NOTIFY yearChanged)
public:
    QEnumerableDate(QObject *parent,QString mainName);
    QEnumerableDate(QObject *parent);
    ~QEnumerableDate(){saveData();}
public slots:
    int min(void){return l_min;};
    int hour(void){return l_hour;};
    int day(void){return l_day;};
    int month(void){return l_month;};
    int year(void){return l_year;};
    void writeMin(int val);
    void writeHour(int val);
    void writeDay(int val);
    void writeMonth(int val);
    void writeYear(int val);
    virtual bool setParam()=0;
signals:
    void minChanged(int val);
    void hourChanged(int val);
    void dayChanged(int val);
    void monthChanged(int val);
    void yearChanged(int val);
protected:
    QString paramName;
    int l_min=12;
    int l_hour=20;
    int l_day=13;
    int l_month=6;
    int l_year=1990;
    bool loadData(QString val);
    QString saveData(void);
};
class QEnumerableIP: public QObject{
Q_OBJECT
    Q_PROPERTY(unsigned char byte1 READ byte1 WRITE writeByte1  NOTIFY byte1Changed)
    Q_PROPERTY(unsigned char byte2 READ byte2 WRITE writeByte2  NOTIFY byte2Changed)
    Q_PROPERTY(unsigned char byte3 READ byte3 WRITE writeByte3  NOTIFY byte3Changed)
    Q_PROPERTY(unsigned char byte4 READ byte4 WRITE writeByte4  NOTIFY byte4Changed)
public:
    QEnumerableIP(QObject *parent,QString mainName);
    QEnumerableIP(QObject *parent);
    ~QEnumerableIP(){saveData();}
    QString getString();
public slots:
    unsigned char byte1(void){return val1;};
    unsigned char byte2(void){return val2;};
    unsigned char byte3(void){return val3;};
    unsigned char byte4(void){return val4;};
    void writeByte1(unsigned char val);
    void writeByte2(unsigned char val);
    void writeByte3(unsigned char val);
    void writeByte4(unsigned char val);
    virtual bool setParam()=0;
signals:
    void byte1Changed(unsigned char val);
    void byte2Changed(unsigned char val);
    void byte3Changed(unsigned char val);
    void byte4Changed(unsigned char val);
protected:
    QString paramName;
    unsigned char val1=192;
    unsigned char val2=168;
    unsigned char val3=0;
    unsigned char val4=0;
    bool loadData(QString val);
    QString saveData(void);
};
Q_DECLARE_METATYPE(QEnumerableInt*);
#endif //MENUCAMERAFHD_QENUMERABLEMAP_H
