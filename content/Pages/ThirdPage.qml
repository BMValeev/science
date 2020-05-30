
import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import QtCharts 2.1
import "../Delegates"
import "../Regulators"
import "../Pages"
import "../Popups"
Item{
    Component.onCompleted:{console.log("main created");}
    Component.onDestruction:{console.log("main destructed");}
    property var defaultFocusItem: test1
    property color mainColor: "#000000"
    width: parent.width
    height: parent.height
    focus: true
    id:secondpage
property var locale: Qt.locale()
    Column{
    id:test1;
    spacing: 0
    width:0.25*parent.width;
    height:parent.height
        Button{text: "Данные";height:parent.height/4;width:parent.width;
            onClicked: {stackView.source="DataPage.qml";}
            }
        Button{text: "Меню";height:parent.height/4;width:parent.width;
            onClicked: {stackView.source="MenuPage.qml";}
        }
        Button{text: "Калибр.";height:parent.height/4;width:parent.width;
            onClicked: {stackView.source="LogPage.qml";}
        }
        Button{text: "Выход";height:parent.height/4;width:parent.width;
            onClicked:Qt.quit()
        }
    }
    Column{
    id:test2;
    spacing: 0
    anchors.left:test1.right
    width:0.375*parent.width;
    height:parent.height
        Button{       text: "Некруглость.";height:parent.height/6;width:parent.width;enabled:false;           }
        ChartView {
        margins{top:0; bottom:0; left:0; right:0;}
        id: round
        legend.visible: false
        height:parent.width
        width:parent.width
        antialiasing: true
        animationOptions: ChartView.NoAnimation
        theme: ChartView.ChartThemeDark
        SplineSeries {id:lineSeries1;axisX: axisX;axisY: axisY;useOpenGL:true;}
        SplineSeries {id:lineSeries3;axisX: axisX;axisY: axisY;useOpenGL:true;}
        ValueAxis { id: axisY;min: -10; max: 10; }
        ValueAxis {id: axisX;min: -10;max: 10;}
        }
    }
    Column{
    id:test3;
        spacing: 0
    anchors.left:test2.right
    width:0.375*parent.width;
    height:parent.height
        Button{text: "Биения мкм.";height:parent.height/6;width:parent.width;enabled:false;  }
        Button{id:dex2; text: "Число";height:parent.height/6;width:parent.width; enabled:false;            }
        Button{       text: "Некругл. мкм.";height:parent.height/6;width:parent.width;enabled:false;           }
        Button{id:dex1; text: "Число";height:parent.height/6;width:parent.width;enabled:false; }
    }
    Process{id:error1;enab:false}
    Close{id:error2;enab:false}
    function setClosed(){error1.enab=false;}
    function setOpened(){error1.enab=true;}
    Timer {
    property bool status:  false
    id: closeTimer2
    interval: 1000; running: secondpage.focus; repeat: true
    onTriggered: {
        if(secondpage.focus==true){
        console.log("22")  ;
        if(dataSource.getVal(3)>80.0){
            setOpened();
            dex1.text="Nan"
            dex2.text="Nan"
        }
        else{ if(dataSource.getVal(3)<10.0){
            setOpened();
            dex1.text="Nan"
            dex2.text="Nan"
        }
        else{
            setClosed();
            dex1.text=dataSource.getVal(0).toFixed(2);
            dex2.text=dataSource.getVal(1).toFixed(2);
            dataSource.update(round.series(0),3);
            dataSource.update(round.series(1),4);
        }
        }
        }
    }
    }
}
