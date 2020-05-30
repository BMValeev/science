
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
    id:secondpage
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
        Button{        text: "След.";height:parent.height/4;width:parent.width;
            onClicked: {stackView.pop();      }
            }
        Button{text: "Авто";height:parent.height/4;width:parent.width;
            onClicked:{axisY.max=dataSource.maxVal()+5; axisY.min=dataSource.minVal()-5;}
        }
        Button{text: "Шире";height:parent.height/4;width:parent.width;
            onClicked:{axisY.max+=5; axisY.min-=5;}
        }
        Button{text: "Выход";height:parent.height/4;width:parent.width;
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
            name: "АЦП"
            useOpenGL:true
        }
        ValueAxis {
            id: axisY
            min: 1350
            max: 1400
        }

        ValueAxis {
            id: axisX
            min: 0
            max: 2048
        }
    }
        Timer {
            property bool status:  false
            id: closeTimer2
            interval: 1000; running: true; repeat: true
            onTriggered: {
                if(secondpage.focus==true){
                console.log("22")  ;
                dataSource.update(chartView.series(0));
                //axisY.max=dataSource.maxVal()+5;
                //axisY.min=dataSource.minVal()-5;
                }
             }
        }

}
