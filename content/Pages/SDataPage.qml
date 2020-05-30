
import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import QtCharts 2.1
import "../Delegates"
import "../Regulators"
import "../Pages"
Item{
    Component.onCompleted:{console.log("data created");}
    Component.onDestruction:{console.log("data destructed");}
    property var defaultFocusItem: test1
    property color mainColor: "#000000"
    width: parent.width
    height: parent.height
    focus: true
    id:secondpage
    property var locale: Qt.locale()
    Column{
        id:test1;
        spacing: 2
        width:parent.width/4;
        height:parent.height
        Button{ text: "Назад";height:parent.height/4;width:parent.width;
                onClicked: {stackView.source="DataPage.qml";}
        }
        Button{text: "Авто";height:parent.height/4;width:parent.width;
                onClicked:{axisY.min=dataSource.getVal(2)-5000;axisY.max=dataSource.getVal(2)+5000;   }
        }
        Button{text: "Clear";height:parent.height/4;width:parent.width;
                onClicked:{dataSource.reconf();  }
        }
    }
    ChartView {
    id: chartView
    legend.visible: false
    anchors {
        left:test1.right;
        right:parent.right;
        top:parent.top;
        bottom:parent.bottom
     }
    antialiasing: false
    animationOptions: ChartView.NoAnimation
    theme: ChartView.ChartThemeDark
    SplineSeries {id:lineSeries1;  axisX: axisX; axisY: axisY;useOpenGL:true; }
    ValueAxis { id: axisY;min: 1400; max: 1500; }
    ValueAxis {id: axisX;min: 0;max: 1000;}
    }
    Timer {
        id: closeTimer2
        interval: 125; running: secondpage.focus; repeat: true
        onTriggered: {
            if(secondpage.focus==true){
            //console.log("4444444");
            dataSource.update(chartView.series(0),1);
            }
         }
    }
}
