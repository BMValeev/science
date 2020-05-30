//
// Created by eleps on 16.01.20.
//

#ifndef MENUCAMERAFHD_SENSORDATA_H
#define MENUCAMERAFHD_SENSORDATA_H
#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QtQml/QQmlApplicationEngine>
#include "comcpp/src/c_class/I2C/I2C.h"
#include <QTimer>
#include <QThread>

class sensordata : public QObject{
Q_OBJECT
public:
    sensordata();
    void configure(unsigned int val,unsigned int CHFIN);
    QVector<float> values;
    QTimer* timer;
    unsigned int size,m_index;
    const double TwoPi = 6.283185307179586;
    double time;
    double eps=0.01,eps1=0.99;
public slots:
    void renewData();
    void reconfigure();
    void reconf(unsigned int val,unsigned int CHFIN){configure(val,CHFIN);}
    QVector<float>* renewVector(){return &values;}
    unsigned int renewPtr(){return m_index;}
    double period(){return time;}

};


#endif //MENUCAMERAFHD_SENSORDATA_H
