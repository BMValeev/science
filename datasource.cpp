
#include "datasource.h"
#include <QtCharts/QXYSeries>
#include <QtCharts/QAreaSeries>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtCore/QDebug>
//#include <QtCore/QRandomGenerator>
#include <QtCore/QtMath>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#define Ntap 31
#define PI 3.14159265
QT_CHARTS_USE_NAMESPACE

Q_DECLARE_METATYPE(QAbstractSeries *)
Q_DECLARE_METATYPE(QAbstractAxis *)

DataSource::DataSource(QObject *parent) :
        QObject(parent),
        epsilon(0.2),
        m_index(-1),
        size(2048),
        rad(10.0),
        cap_L(0.00001),
        max_cnt(8){
    qRegisterMetaType<QAbstractSeries*>();
    qRegisterMetaType<QAbstractAxis*>();
    cR = new QEnumerableInt(parent,"1",10,100);cR->writeVal(30);
    cr1 = new QEnumerableInt(parent,"1",1,100);cr1->writeVal(15);
    cr2 = new QEnumerableInt(parent,"1",1,100); cr2->writeVal(20);
    cr3 = new QEnumerableInt(parent,"1",1,100); cr3->writeVal(30);
    t1 = new QEnumerableInt(parent,"1",1,255);t1->writeVal(2);
    f = new QEnumerableInt(parent,"1",100,1000);f->writeVal(300);
    diff1 = new QEnumerableBool(parent,"1",true);
    C0=00.0*std::pow(10,-12);
    loadData();
    loadCal();
    reconf();
}
void DataSource::renewData(){
    auto t1=std::chrono::system_clock::now();
//    static unsigned int v(0);
    float dur;
    static unsigned int cnt_index=0;
    unsigned int index= giver->renewPtr();
    QVector<float>* val=giver->renewVector();
    float l_mean=0.0,d_mean;
    //unsigned int l_size=(giver->size)>>3;
    unsigned int m_size=(giver->size);
    static bool init=false;
    static int cnt=0, cnt_ptr=0;
    //std::cout<<"period: "<<std::pow(10,9)/giver->period()<< std::endl;
    float d;
    double temp;
    unsigned int i,cntr;
    if(cnt_index>index){i=m_size-cnt_index+index;}
    else{i=index-cnt_index;}
    std::cout<<" i: " <<i ;
    std::cout<<" cnt_index: " <<  cnt_index ;
    std::cout<<" index: " <<   index << std::endl;
    for(unsigned int n(0);n<(m_size-i);n++){
        m_data[n]=QPoint(n,m_data[n+i].y());
        m_simple[n]=QPoint(n,m_simple[n+i].y());
    }
    std::cout<<" count from : " <<0 ;
    std::cout<<" to: " <<  m_size-i<< std::endl ;
    cntr=0;
    for(unsigned int n(m_size-i);n<(m_size);n++){
        d=val->at((cnt_index+(cntr++))%m_size);
        temp=(fix(FtoC(d))) ;
        m_data[n]=QPoint(n,temp);
        m_simple[n]=QPoint(n,d);
        l_mean+=d;
        d_mean+=temp;
    }
    std::cout<< std::endl ;
    std::cout<<" count from : " <<m_size-i ;
    std::cout<<" to: " <<  m_size<< std::endl ;
    std::cout<<"Sensor count from : " <<cnt_index ;
    std::cout<<" Sensor to: " <<  cnt_index+cntr<< std::endl ;
    /*for(unsigned int i(index);i<(m_size);i++){
        d=val->at(i);
        l_mean+=d;
        temp=fix(FtoC(d));
        d_mean+=temp;
        m_data[i-index]=QPoint(i-index,temp);
        m_simple[i-index]=QPoint(i-index,d);
    }
    for(unsigned int i(0);i<index;i++){
        d=val->at(i);
        l_mean+=d;
        temp=fix(FtoC(d));
        d_mean+=temp;
        m_data[m_size-index+i]=QPoint(m_size-index+i, temp);
        m_simple[m_size-index+i]=QPoint(m_size-index+i,d);
    }*/
    cnt_index=index;
    meanVal*=(1-epsilon);
    meanValD*=(1-epsilon);
    meanVal+=epsilon*l_mean/i;
    meanValD+=epsilon*d_mean/i;
    dur=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()-t1).count();
    std::cout<<"fix : "<<fix(FtoC(meanVal));
    std::cout<<" meanVal : "<<((meanValD))<< std::endl;
    calcValues();
    cnt++;
    dur=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()-t1).count();
    //std::cout<<"data process+receive: "<<dur<< std::endl;
}


double DataSource::FtoC(double val){
   // static double CHFIN=1;
   // CHFIN=diff()->val()?1:2;
    static long double Fref=4*std::pow(10,7);
    static long double DIV=std::pow(2,28);
    static long double L=18*std::pow(10,-6);
    static long double C=33*std::pow(10,-12);
    static long double gg=2*Fref/DIV;
    static long double vv=L*4*PI*PI;
    long double FF=val*gg;
   // double FF=val*CHFIN*Fref/DIV;
    double CC=((1/(vv*FF*FF))-C0-C);
    return CC;
}
float DataSource::median_f(float x){
    static std::vector<float> median;
    static float val=0.0;
    auto val2=(x+val)/2;
    val=x;
    return val2;
    median.push_back(x);
    if(median.size()>5){median.erase(median.begin());}
    std::vector<float> median2(median);
    std::sort(median2.begin(),median2.end(),std::greater<float>());
    return median2[2];
}
void DataSource::generateNet(){
    if (changedTable==false){return;}
    m_cap.clear();
    for (unsigned int j(0); j < 1000; j++) {
        cap_L=j/10.0;
        m_cap.append(QPointF(cap_L, evalC()));
        std::cout<< "L: "<<cap_L  << "|| cap: " <<evalC() <<std::endl;
    }
    saveCal();
    saveData();
    changedTable=false;
}
float DataSource::fix(float x){
    //return x;
    return x*std::pow(10,15);
    auto i=m_cap.size()/2;
    unsigned int step=m_cap.size()/4;
    unsigned int cnt=0;
    while ((i>1) && (i<m_cap.size())&&(cnt++<30) &&(step>0)){
        if (m_cap[i].y()>x){i+=step;}
        else{i-=step;}
        step>>=1;
    }
    return m_cap[i].x()*1000;
    /*for(int i=1;i<m_cap.size();i++){
       if (m_cap[i].y()<x){return m_cap[i].x();}
    }
    return  m_cap[m_cap.size()-2].x();*/
}
float DataSource::fir(float NewSample) {
    float FIRCoef[Ntap] = {
            -0.00299381734600348470,
            -0.00282445904020355970,
            0.00488222654195747270,
            0.00437745898522847160,
            -0.00809886804873909470,
            -0.00674204022556069200,
            0.01376027141795409400,
            0.01022344566071104600,
            -0.02419492170379065200,
            -0.01497073209306316900,
            0.04484143089706242600,
            0.02049543043868030600,
            -0.09296736467395119700,
            -0.02524867600219906800,
            0.31475229006731847000,
            0.52941665024919760000,
            0.31475229006731847000,
            -0.02524867600219906800,
            -0.09296736467395119700,
            0.02049543043868030600,
            0.04484143089706242600,
            -0.01497073209306316900,
            -0.02419492170379065200,
            0.01022344566071104600,
            0.01376027141795409400,
            -0.00674204022556069200,
            -0.00809886804873909470,
            0.00437745898522847160,
            0.00488222654195747270,
            -0.00282445904020355970,
            -0.00299381734600348470
    };
    static float x[Ntap]; //input samples
    float y=0;            //output sample
    int n;
    for(n=Ntap-1; n>0; n--){x[n] = x[n-1];}
    x[0] = NewSample;
    for(n=0; n<Ntap; n++){y += FIRCoef[n] * x[n];}
    return y;
}

double DataSource::integral1( double a, double b, int n) {
    double step = (b - a) / n;  // width of each small rectangle
    double area = 0.0;  // signed area
    for (int i = 0; i < n; i ++) {
        area += valC1(a + (i + 0.5) * step) * step; // sum up each small rectangle
    }
    return area;
}
double DataSource::valC(double x,double r){
    //static double l_R=c_R()->val()*std::pow(10,-3);
    static double var=4*8.85418781762039*1.00058986*std::pow(10,-12);
    double l_R=10*std::pow(10,-3);
    static  double l_R2=l_R*l_R;
    double l_L=cap_L*std::pow(10,-6);
    double x2=x*x;
    return var*(sqrt(r*r-x2)/((l_R+l_L)-sqrt(l_R2-x2)));
}
double DataSource::evalC(){
    double C1=integral1(0,c_r1()->val()*0.0001,2000);
    //double C2=integral2(0,c_r2()->val()*0.001,2000);
    //double C3=integral3(0,c_r3()->val()*0.001,2000);
    //return diff()->val()?  C1*(C3-C2)/(C1+C3-C2):C1;
    return C1;
}
void DataSource::updateCircles(double C,double R, unsigned int F){
    static bool init=false;
    static std::vector <float> cos2,cos1,sin1;
    if (!init){
        std::cout<<"init"<<std::endl;
        cos2.reserve(360);
        cos1.reserve(360);
        sin1.reserve(360);
        for(unsigned int i(0);i<360;i++){
            auto t=i*2*PI/180;
            cos2.push_back(cos(t));
            t/=2;
            cos1.push_back(cos(t));
            sin1.push_back(sin(t));
        }
        init=true;
    }
    if(F<3){        chatter=0.0;        roundness=0.0;        return;    }
    else{
        chatter=(1-epsilon)*chatter+epsilon*C;
        roundness=(1-epsilon)*roundness+epsilon*R;
    }
    //m_chatter.clear();
    //m_round.clear();
    //m_round_ideal.clear();
    auto v1=rad+0.5*roundness;
    for(unsigned int i(0);i<360;i+=10){
        auto v=v1+0.5*roundness*cos2[i];
        //m_chatter[i].setX(chatter*sin1[i]);
        //m_chatter[i].setY(chatter*cos1[i]);
        m_round[i].setX(v*sin1[i]);
        m_round[i].setY(v*cos1[i]);
        //m_chatter.append(QPointF(chatter*sinus,chatter*cosine));
        //m_round.append(QPointF(v*sinus,v*cosine));
        //m_round_ideal.append(QPointF(rad*sin(i*PI/180),rad*cos(i*PI/180)));
    }    
}

void DataSource::FFTAnalysis() {
    //double *AVal, double *FTvl, int Nvl, int Nft
    static QVector<QPointF> reservedData(m_fft);
    unsigned int l_size=(giver->size);
    int Nvl=l_size;
    int Nvl2=l_size*max_cnt;
    int Nft=l_size;
    int i, j, n, m, Mmax, Istp;
    double Tmpr, Tmpi, Wtmp, Theta;
    double Wpr, Wpi, Wr, Wi;
    static bool init=false;
    static std::vector <double> Tmvl,Tmvl2;
    n = Nvl * 2;
    if(!init){
        std::cout<<"init fft"<<std::endl;
        for(int i(0);i<n;i++){Tmvl.push_back(0.0);}
        //for(int i(0);i<Nvl2;i++){Tmvl2.push_back(0.0);}
        init=true;
    }
    for (i = 0; i < n; i+=2) {
        Tmvl[i] = 0;
        Tmvl[i+1] = m_simple.at(i/2).y();
        //Tmvl[i+1] = for_fft[i/2];
    }
    i = 1; j = 1;
    while (i < n) { if (j > i) {
            Tmpr = Tmvl[i]; Tmvl[i] = Tmvl[j]; Tmvl[j] = Tmpr;
            Tmpr = Tmvl[i+1]; Tmvl[i+1] = Tmvl[j+1]; Tmvl[j+1] = Tmpr;
        }
        i += 2; m = Nvl;
        while ((m >= 2) && (j > m)) { j = j - m; m = m >> 1; }
        j+=  m;
    }

    Mmax = 2;
    while (n > Mmax) {
        Theta = -TwoPi / Mmax; Wpi = sin(Theta);
        Wtmp = sin(Theta / 2); Wpr = Wtmp * Wtmp * 2;
        Istp = Mmax * 2; Wr = 1; Wi = 0; m = 1;

        while (m < Mmax) {
            i = m; m +=  2; Tmpr = Wr; Tmpi = Wi;
            Wr -= (Tmpr * Wpr + Tmpi * Wpi);
            Wi += (Tmpr * Wpi - Tmpi * Wpr);

            while (i < n) {
                j = i + Mmax;
                Tmpr = Wr * Tmvl[j] - Wi * Tmvl[j-1];
                Tmpi = Wi * Tmvl[j] + Wr * Tmvl[j-1];

                Tmvl[j] = Tmvl[i] - Tmpr; Tmvl[j-1] = Tmvl[i-1] - Tmpi;
                Tmvl[i] += Tmpr; Tmvl[i-1] +=  Tmpi;
                i += Istp;
            }
        }
        Mmax = Istp;
    }
    /*reservedData.clear();
    for (i = 0; i < Nft/2; i++) {
        reservedData.append(QPointF(m_fft.at(i).x(),m_fft.at(i).y()*(1-epsilon)));
    }
    m_fft.clear();*/
    auto freq=(2*std::pow(10,9)/giver->period())/Nft;
    for (i = 0; i < Nft/2; i++) {j = i * 2;
        //m_fft[i].setY(m_fft[i].y()*(1-epsilon)+epsilon*(sqrt(Tmvl[j]*Tmvl[j] + Tmvl[j+1]*Tmvl[j+1])/Nvl));
        m_fft[i].setY((sqrt(Tmvl[j]*Tmvl[j] + Tmvl[j+1]*Tmvl[j+1])/Nvl));
        m_fft[i].setX(m_fft[i].x()*(1-epsilon)+epsilon*(freq*i));
    }
    m_fft[0]=QPointF(0,0.0);
    m_fft[Nft-1]=QPointF(Nft-1,0.0);
}

void DataSource::update(QAbstractSeries *series,unsigned int val){
    //auto t1=std::chrono::system_clock::now();
    QXYSeries *xySeries = static_cast<QXYSeries *>(series);
    switch(val){
        case 0:   xySeries->replace(m_data) ; break;
        case 1: xySeries->replace(m_simple); break;
        case 2:  xySeries->replace(m_fft) ; break;
        case 3:  xySeries->replace(m_round) ; break;
        case 4:  xySeries->replace(m_round_ideal) ; break;
        case 5:  xySeries->replace(m_chatter) ; break;
        default: xySeries->replace(m_data) ; break;
    }
    //double dur=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()-t1).count();
    //std::cout<<"points renew time: "<<dur<< std::endl;
}
float DataSource::maxNearestValue(QVector<float> data,unsigned int indice){
    return data.at(floor(indice/2))>data.at(round(indice/2))?data.at(floor(indice/2)):data.at(round(indice/2));
}
float DataSource::maxNearestIndice(QVector<float> data,unsigned int indice){
    return data.at(floor(indice/2))>data.at(round(indice/2))?floor(indice/2):round(indice/2);
}
void DataSource::generateData(){
        unsigned int l_size=(giver->size);
        m_data.reserve(l_size);
        m_fft.reserve(l_size*10);
        m_simple.reserve(l_size);
        m_round.reserve(360);
        m_round_ideal.reserve(360);
        m_chatter.reserve(360);
        for (unsigned int j(0); j < l_size; j++) {
            m_data.append(QPointF(j, 0));
            m_fft.append(QPointF(j, 0));
            m_simple.append(QPointF(j, 0));
        }
    for (unsigned int j(0); j < l_size*max_cnt; j++) {        m_fft.append(QPointF(j, 0));    }
    for (unsigned int j(0); j < 360; j++) {
        m_round.append(QPointF(0, 0));
        m_round_ideal.append(QPointF(rad*sin(j*PI/180),rad*cos(j*PI/180)));
        m_chatter.append(QPointF(0, 0));
    }

}

/*qm; getters*/
float DataSource::maxV(unsigned int val){
    auto ptr=m_data;
    switch(val){
        case 0: ptr=m_data; break;
        case 1: ptr=m_fft; break;
        case 2: ptr=m_simple; break;
        default: ptr=m_simple; break;
    }
    qreal max=ptr[0].y();
            foreach(auto p, ptr ){max=p.y()>max?p.y():max;        }
    std::cout<<"maxval: "<< max<< std::endl;
    return max;
}
float DataSource::minV(unsigned int val){
    auto ptr=m_data;
    switch(val){
        case 0: ptr=m_data; break;
        case 1: ptr=m_fft; break;
        case 2: ptr=m_simple; break;
        default: ptr=m_simple; break;
    }
    qreal min=ptr[0].y();
            foreach(auto p, ptr ){min=p.y()<min?p.y():min;        }
    std::cout<<"minval: "<< min << std::endl;
    return min;
}
float DataSource::getVal(unsigned int val){
    switch(val){
        case 0: return roundness;
        case 1: return chatter;
        case 2: return meanVal;
        case 3: return meanValD;
        default: return meanValD;
    }
}
void DataSource::calibrate1(){
    C0=0;
    C0=FtoC(meanVal);
    generateNet();
}
void DataSource::calibrate2(){
    calibrated();
}
void DataSource::reconf(){
    if( changedConf){
        giver->reconf(t()->val(),(diff()->val())?0x10:0x20);
        changedConf=false;
        std::cout<< "changedConf inside" <<std::endl;
    }
}


void DataSource::start(){
    generateData();
    mWatcherStatuses= new QTimer(this);
    connect(mWatcherStatuses, &QTimer::timeout, this, &DataSource::renewData);
    connect(cR, &QEnumerableInt::curValChanged, this, &DataSource::changeTable);
    connect(cr1, &QEnumerableInt::curValChanged, this, &DataSource::changeTable);
    connect(cr2, &QEnumerableInt::curValChanged, this, &DataSource::changeTable);
    connect(cr3, &QEnumerableInt::curValChanged, this, &DataSource::changeTable);
    connect(t1, &QEnumerableInt::curValChanged, this, &DataSource::changeConf);
    connect(diff1, &QEnumerableBool::curValChanged, this, &DataSource::changeConf);
    mWatcherStatuses->start(125);
}
void DataSource::calcValues(){
    auto t1=std::chrono::system_clock::now();
    float dur;
    FFTAnalysis();
    dur=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()-t1).count();
    //std::cout<<"FFTAnalysis: "<<dur<< std::endl;
    //updateCircles(10,10, 5);
    dur=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()-t1).count();
    //std::cout<<"updateCircles: "<<dur<< std::endl;
}
/*qm; loaders*/
bool DataSource::loadData(){
    configSensor senConfig;
    QSettings settings(senConfig.settingsPath(), QSettings::IniFormat); settings.setIniCodec("UTF-8");
    settings.setIniCodec("UTF-8");
    settings.beginGroup("Common");
    c_R()->writeVal(settings.value("R", 0).toInt());
    c_r1()->writeVal(settings.value("r1", 0).toInt());
    c_r2()->writeVal(settings.value("r2", 0).toInt());
    c_r3()->writeVal(settings.value("r3", 0).toInt());
    t()->writeVal(settings.value("Ts", 0).toInt());
    //C0=settings.value("C0", 0).toFloat();
    diff()->writeVal(settings.value("diff", 0).toBool());
    settings.endGroup();
    return false;
};
bool DataSource::loadCal(){
    configSensor senConfig;
    QSettings settings(senConfig.settingsPath(), QSettings::IniFormat); settings.setIniCodec("UTF-8");
    settings.beginGroup("Calibrate");
    m_cap.clear();
    for (unsigned int j(0); j < 400; j++) {
        cap_L=j/4.0;
        m_cap.append(QPointF(cap_L, settings.value(QString::number(cap_L), 0).toDouble()));
    }
    settings.endGroup();
    return false;
}
bool DataSource::saveCal(){
    configSensor senConfig;
    QSettings settings(senConfig.settingsPath(), QSettings::IniFormat); settings.setIniCodec("UTF-8");
    settings.beginGroup("Calibrate");
    for (unsigned int j(0); j < 400; j++) {
        cap_L=j/4.0;
        settings.setValue(QString::number(cap_L), m_cap[j].y());
    }
    settings.endGroup();
    return false;
}
bool DataSource::loadFactory(){
    configSensor senConfig;
    QSettings settings(senConfig.charFactoryPath(), QSettings::IniFormat); settings.setIniCodec("UTF-8");
    loadData();
    return false;
};
void DataSource::saveData(){
    configSensor senConfig;
    QSettings settings(senConfig.settingsPath(), QSettings::IniFormat); settings.setIniCodec("UTF-8");
    settings.setIniCodec("UTF-8");
    settings.beginGroup("Common");
    settings.setValue("R", c_R()->val());
    settings.setValue("r1", c_r1()->val());
    settings.setValue("r2", c_r2()->val());
    settings.setValue("r3", c_r3()->val());
    settings.setValue("Ts", t()->val());
    settings.setValue("diff", diff()->val());
    settings.setValue("C0", C0);
    settings.endGroup();
};
/*double DataSource::integral2( double a, double b, int n) {
    double step = (b - a) / n;  // width of each small rectangle
    double area = 0.0;  // signed area
    for (int i = 0; i < n; i ++) {
        area += valC2(a + (i + 0.5) * step) * step; // sum up each small rectangle
    }
    return area;
}
double DataSource::integral3( double a, double b, int n) {
    double step = (b - a) / n;  // width of each small rectangle
    double area = 0.0;  // signed area
    for (int i = 0; i < n; i ++) {
        area += valC3(a + (i + 0.5) * step) * step; // sum up each small rectangle
    }
    return area;
}
*/
/*qreal DataSource::maxVal(){
    qreal max=m_data[0].y();
    foreach(auto p, m_data ){max=p.y()>max?p.y():max;        }
    std::cout<<"maxval: "<< max<< std::endl;
    return max;
}
qreal DataSource::minVal(){
    qreal min=m_data[0].y();
    foreach(auto p, m_data ){min=p.y()<min?p.y():min;        }
    std::cout<<"minval: "<< min << std::endl;
    return min;
}*/

/*void DataSource::update(QAbstractSeries *series){
    if (series) {
        //std::cout<<"maxval: "<< 2777-val << std::endl;
        //qMin=3857-val;//2777
        //qMax=3857-val2;
        //std::cout<<"capacity: "<< std::log10(((128000/(val*M_PI))*(128000/(val*M_PI))-100)/2) << std::endl;
        //std::cout<<"minval: "<< 3857-val2 << std::endl;
        //std::cout<<"capacity: "<< std::log10(((128000/(val2*M_PI))*(128000/(val2*M_PI))-100)/2) << std::endl;
        QXYSeries *xySeries = static_cast<QXYSeries *>(series);
        QVector<QPointF> points = m_data;
        //QVector<QPointF> points = m_fft;
        xySeries->replace(points);

    }
}*/
/*
 *     unsigned int l_size=(giver->size)/2;
    int Nvl=l_size;
    int Nvl2=l_size/2;
    int Nft=l_size;
    int i, j, n, m, Mmax, Istp;
    double Tmpr, Tmpi, Wtmp, Theta;
    double Wpr, Wpi, Wr, Wi;
    double *Tmvl;
    n = Nvl * 2; Tmvl = new double[n];
    for (i = 0; i < n; i+=2) {
        Tmvl[i] = 0;
        Tmvl[i+1] = static_cast<float>(m_data.at(i/2).y());
    }

    i = 1; j = 1;
    while (i < n) { if (j > i) {
            Tmpr = Tmvl[i]; Tmvl[i] = Tmvl[j]; Tmvl[j] = Tmpr;
            Tmpr = Tmvl[i+1]; Tmvl[i+1] = Tmvl[j+1]; Tmvl[j+1] = Tmpr;
        }
        i = i + 2; m = Nvl;
        while ((m >= 2) && (j > m)) { j = j - m; m = m >> 1; }
        j = j + m;
    }

    Mmax = 2;
    while (n > Mmax) {
        Theta = -TwoPi / Mmax; Wpi = sin(Theta);
        Wtmp = sin(Theta / 2); Wpr = Wtmp * Wtmp * 2;
        Istp = Mmax * 2; Wr = 1; Wi = 0; m = 1;

        while (m < Mmax) {
            i = m; m = m + 2; Tmpr = Wr; Tmpi = Wi;
            Wr = Wr - Tmpr * Wpr - Tmpi * Wpi;
            Wi = Wi + Tmpr * Wpi - Tmpi * Wpr;

            while (i < n) {
                j = i + Mmax;
                Tmpr = Wr * Tmvl[j] - Wi * Tmvl[j-1];
                Tmpi = Wi * Tmvl[j] + Wr * Tmvl[j-1];

                Tmvl[j] = Tmvl[i] - Tmpr; Tmvl[j-1] = Tmvl[i-1] - Tmpi;
                Tmvl[i] = Tmvl[i] + Tmpr; Tmvl[i-1] = Tmvl[i-1] + Tmpi;
                i =i+ Istp;
            }
        }
        Mmax = Istp;
    }
 * */

/*double DataSource::FtoC(double val){
    //double epsilon=1.00058986*8.85418781762039*std::pow(10,-12);
    static double CHFIN=1;
    if(diff()->val()){CHFIN=1;}
    else{CHFIN=2;}
    static double Fref=43400000;
    static double DIV=std::pow(2,15);
    static double L=std::pow(10,-5);
    static double C=33*std::pow(10,-12);
    double FF=(4096-val)*CHFIN*Fref/DIV;
    double CC=1/(L*std::pow(2*PI*FF,2))-C-C0;
    return CC;
    //double l_freq=2*43.4*std::pow(10,6)/(std::pow(2,16));
  }*/
/*
fred=43.4M
 CHFIN=1
 DIV=2^15
 L=10^-5
 C=33*10^-12
 C1=18*10^-12
 FF=3700*CHFIN*Fred.DIV
 CC=(1/(L*2*pi*FF)^2)-C-C1
 1/(2*pi*sqrt(L*(33+18+50)*10^-12))
 FF=(4096-348)*CHFIN*Fred/DIV
 * */
/*unsigned int temp,tempMax;
    tempMax=val2;
    temp=val;
    val=0;
    val2=4096;
    std::vector<uint8_t> data,received;
    I2C &i2c = I2C::getInstance();
    i2c.begin("/dev/i2c-2");
    data.push_back(0x00);
    m_data.clear();
    for(qreal i(0);i<size+64;i++){
        if(OK_I2C==i2c.transaction(0x2B<<1,data,2)) {
            received=i2c.recData();
            auto d=qreal((static_cast<float>(received.at(0)*256+received.at(1))));//fir
            val= (val>d)?val:d;
            val2=(val2<d) ?val2:d;
            //d=300*(std::pow(10,(3.417803723-std::log10(d)))-1);
            //d=std::pow(10,(1.852-std::log10(((128000/(d*M_PI))*(128000/(d*M_PI))-100)/2)));
            //if(i>64){m_data.append(QPointF(qreal(i-64),1/(5*0.0001*(4096-d-463))));}
            if(i>64){m_data.append(QPointF(qreal(i-64),4096-d));}
            std::cout<<"minval: "<< (4096-d)<< std::endl;
        }
        else{
            m_data.append(QPointF(qreal(i), qreal(0)));
        }
    }
     a: 1.42499e+06
    b: 913.805

     */
//double l_freq=2*43.4*std::pow(10,6)/(std::pow(2,16));
/*
fred=43.4M
 CHFIN=1
 DIV=2^15
 L=10^-5
 C=33*10^-12
 C1=18*10^-12
 FF=3700*CHFIN*Fred.DIV
 CC=(1/(L*2*pi*FF)^2)-C-C1
 1/(2*pi*sqrt(L*(33+18+50)*10^-12))
 FF=(4096-348)*CHFIN*Fred/DIV
 * */
/*values.clear();
 float r1,c1;
 for (unsigned int i=0;i<size/8;i++ ) {values.append(m_fft.at(i).y());  }
 if (*std::max_element(values.constBegin(), values.constEnd())<0.00001){    updateCircles(0.0,0.0, 0); return;}
 auto max=*std::max_element(values.constBegin(), values.constEnd());
 auto indice=std::max_element(values.constBegin(), values.constEnd())-values.constBegin();
 if (static_cast<unsigned int>(indice)>size/4){
     auto max2=maxNearestValue(values,indice);
     auto indice2=maxNearestIndice(values,indice);
     std::cout<<"Roundness: "<< max << "in: " <<  indice<< std::endl;
     std::cout<<"Chatter: "<< max2<<"in: " <<  indice2 << std::endl;
     r1=max;
     c1=max2;
     freq=indice2;
     updateCircles(c1,r1, freq);
     return;
 }
 if (maxNearestValue(values,indice*4)>maxNearestValue(values,indice)){
     auto max2=maxNearestValue(values,indice*4);
     auto indice2=maxNearestIndice(values,indice*4);
     std::cout<<"Roundness: "<< max2<< " Freq: " <<indice2 <<  std::endl;
     std::cout<<"Chatter: "<< max<< " Freq: " <<indice <<  std::endl;
     r1=max2;
     c1=max;
     freq=indice;
     updateCircles(c1,r1, freq);
     return;
 }
 auto max2=maxNearestValue(values,indice);
 auto indice2=maxNearestIndice(values,indice);
 std::cout<<"Roundness: "<< max<<" Freq: " <<indice << std::endl;
 std::cout<<"Chatter: "<< max2<< " Freq: " <<indice2 << std::endl;
 r1=max;
 c1=max2;
 freq=indice2;*/