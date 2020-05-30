//#include "devicedata.h"
#include "qtquickcontrolsapplication.h"
#include "comcpp/src/c_class/I2C/I2C.h"
#include <QtQml/QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtCore/QDir>
#include <QDebug>
#include <QTranslator>
#include <QObject>
#include <QLocale>
#include <QThread>
#include <iostream>
#include <string>
#include "datasource.h"
#include "sensordata.h"
#include "configSensor.h"
//registers
#define FDC2214_DEVICE_ID           		0x7F
#define FDC2214_MUX_CONFIG          		0x1B
#define FDC2214_CONFIG              		0x1A
#define FDC2214_RCOUNT_CH0          		0x08
#define FDC2214_OFFSET_CH0		          	0x0C
#define FDC2214_SETTLECOUNT_CH0     		0x10
#define FDC2214_CLOCK_DIVIDERS_CH0  		0x14
#define FDC2214_STATUS              		0x18
#define FDC2214_DATA_CH0_LSB    		    0x00
#define FDC2214_DRIVE_CH0           		0x1E
// mask for 28bit data to filter out flag bits
#define FDC2214_DATA_CHx_MASK_DATA         	0x0FFF
#define FDC2214_DATA_CHx_MASK_ERRAW        	0x1000
#define FDC2214_DATA_CHx_MASK_ERRWD        	0x2000



#undef DEMO
//#define DEMO
void shutdown(void);

int main(int argc, char *argv[]) {

    std::vector<uint8_t> data,received;
    //gst_init (&argc, &argv);


    //DeviceData devicemodel;
    //atexit(shutdown);
    configSensor senConfig;
    QThread* sensorThread = new QThread;
    QtQuickControlsApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QSettings settings(senConfig.settingsPath(), QSettings::IniFormat); settings.setIniCodec("UTF-8");
    DataSource dataSource(&engine);
    dataSource.loadData();
    sensordata* giver = new sensordata();
    engine.rootContext()->setContextProperty(QStringLiteral("dataSource"), &dataSource);
#ifdef DEMO
    //engine.load(QUrl(QStringLiteral("qrc:/demo.qml")));
#else
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
#endif

    giver->moveToThread(sensorThread);
    //giver->startTimer();
    dataSource.addGiver(giver);
    QObject::connect(sensorThread, SIGNAL(started()), giver, SLOT(renewData()));
    sensorThread->start(QThread::TimeCriticalPriority);
    dataSource.start();
    //QObject::connect(&DevModelThread,&QThread::finished,&devicemodel,&DeviceData::finish);
    //DevModelThread.start();
    if (engine.rootObjects().isEmpty()){ return -1;}
    int r=app.exec();
    //DevModelThread.quit();
    //DevModelThread.wait();
    return r;
}
void shutdown(void)
{
#ifdef DEMO // shut down only on hamming
    //system("shutdown -hP now");
#endif //DEMO
}