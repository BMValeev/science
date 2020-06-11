/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <vector>
#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QtQml/QQmlApplicationEngine>
#include "comcpp/src/c_class/I2C/I2C.h"
#include <QTimer>
#include <QThread>
#include "sensordata.h"
#include <QtCore/QtMath>
#include <QSettings>
#include "configSensor.h"
#include "QEnumerableMap.h"
#include <math.h>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QQuickView;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE
class DataSource : public QObject
{
Q_OBJECT
    Q_PROPERTY(float min READ min NOTIFY minChanged)
    Q_PROPERTY(float max READ max NOTIFY maxChanged)
    Q_PROPERTY(QEnumerableInt* c_R READ c_R NOTIFY RChanged)
    Q_PROPERTY(QEnumerableInt* c_r1 READ c_r1 NOTIFY r1Changed)
    Q_PROPERTY(QEnumerableInt* c_r2 READ c_r2 NOTIFY r2Changed)
    Q_PROPERTY(QEnumerableInt* c_r3 READ c_r3 NOTIFY r3Changed)
    Q_PROPERTY(QEnumerableInt* t READ t NOTIFY tChanged)
    Q_PROPERTY(QEnumerableInt* freqVal READ freqVal NOTIFY freqValChanged)
    Q_PROPERTY(QEnumerableBool* diff READ diff NOTIFY diffChanged)

public:
    explicit DataSource(QObject *parent = 0);
    QTimer* mWatcherStatuses;
    //QThread workerThread;
    const double TwoPi = 6.283185307179586;
    float epsilon,qMin,qMax;
    float min(){return qMin;}
    float max(){return qMax;}
    void addGiver(sensordata* ptr){giver=ptr;}
    float fix(float x);
    float fir(float NewSample);
    bool loadData();
    bool loadFactory();
    bool loadCal();

Q_SIGNALS:
signals:
    void minChanged();
    void maxChanged();
    void calibrated();
    void RChanged();
    void r1Changed();
    void r2Changed();
    void r3Changed();
    void tChanged();
    void freqValChanged();
    void diffChanged();
public slots:
    void changeTable(){std::cout<< "changedTable called" <<std::endl; changedTable=true;};
    void changeConf(){std::cout<< "changedConf called" <<std::endl; changedConf=true;};
    void saveData();
    bool saveCal();
    void update(QAbstractSeries *series,unsigned int val);
    void calcValues();
    void calibrate1();
    void calibrate2();
    void start();
    void renewData();
    float maxNearestValue(QVector<float> data,unsigned int indice);
    float maxNearestIndice(QVector<float> data,unsigned int indice);
    void reconf();
    float minV(unsigned int val);
    float maxV(unsigned int val);
    float getVal(unsigned int val);
    void generateNet();
    QEnumerableInt* c_R(){return cR;};
    QEnumerableInt* c_r1(){return cr1;};
    QEnumerableInt* c_r2(){return cr2;};
    QEnumerableInt* c_r3(){return cr3;};
    QEnumerableInt* t(){return t1;};
    QEnumerableInt* freqVal(){return f;};
    QEnumerableBool* diff(){return diff1;};
private:
    QEnumerableInt *cR,*cr2,*cr3,*cr1,*t1,*f;
    QEnumerableBool *diff1;
    sensordata* giver;
    QQuickView *m_appViewer;
    QVector<QPointF> m_simple,m_data,m_fft,m_round,m_chatter,m_round_ideal,m_cap;
    std::vector <double> for_fft;
    int m_index;
    unsigned int size,val;
    float roundness,chatter,rad,meanVal,meanValD;
    float C0,cap_L;
    bool changedTable=false;
    bool changedConf=false;
    void updateCircles(double C,double R, unsigned int F);
    void generateData();
    void FFTAnalysis();
    double evalC();
    double integral1( double a, double b, int n);
    double integral2( double a, double b, int n);
    double integral3( double a, double b, int n);
     double valC(double x,double r);
     double valC1(double x){return valC(x,1.5*0.001);}
     //double valC1(double x){return valC(x,c_r1()->val()*0.001);}
     //double valC2(double x){return valC(x,c_r2()->val()*0.001);}
    // double valC3(double x){return valC(x,c_r3()->val()*0.001);}
     double FtoC(double x);
     float median_f(float x);
     int max_cnt;
};

#endif // DATASOURCE_H
