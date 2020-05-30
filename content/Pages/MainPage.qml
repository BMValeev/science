
import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import QtCharts 2.1
import "../Delegates"
import "../Regulators"
import "../Pages"
Item{
    property var defaultFocusItem: test1
    property color mainColor: "#000000"
    width: parent.width
    height: parent.height
    focus: true
    id:mainpage
        property date currentDate: new Date()
        property string dateString
property var locale: Qt.locale()
    transform: Rotation {
        angle: 180
        origin.x: parent.width / 2
        origin.y: parent.height / 2
    }
    Column{
    id:test1;
    spacing: 2
    width:parent.width/4;
    height:parent.height

        Button{        text: "next";height:parent.height/4;width:parent.width;
            onClicked: {
            stackView.push(Qt.resolvedUrl("./SecondPage.qml"));           }
            }
        Button{text: "stop";height:parent.height/4;width:parent.width;
            onClicked:closeTimer1.running=false;
        }
        Button{text: "start";height:parent.height/4;width:parent.width;
            onClicked:closeTimer1.running=true;
        }
        Button{text: "exit";height:parent.height/4;width:parent.width;
            onClicked:Qt.quit()
        }
    }
    ChartView {
    id: chartView
        title: "Показания датчика во времени"
        anchors {
            left:test1.right;
            right:parent.right;
            top:parent.top;
            bottom:parent.bottom
         }
        antialiasing: true
        animationOptions: ChartView.NoAnimation
        theme: ChartView.ChartThemeDark
        SplineSeries {
        id:lineSeries1
            axisX: axisX
            axisY: axisY
            useOpenGL:true
        }
        ValueAxis {
            id: axisY
            //min: 2550
            min: 0
            //max: 2650
            max: 5
        }

        ValueAxis {
            id: axisX
            min: 0
            max: 128
        }
    }
        Timer {
            property bool status:  false
            id: closeTimer1
            interval: 1000; running: true; repeat: true
            onTriggered: {
                if(mainpage.focus==true){
                    dateString = currentDate.toLocaleDateString();
                    print(new Date());
                    dataSource.updateFFT(chartView.series(0));
                }
            }
        }

}
