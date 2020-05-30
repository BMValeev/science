
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
    //transform: Rotation {        angle: 180        origin.x: parent.width / 2        origin.y: parent.height / 2}
    Column{
    id:test1;
    spacing: 2
    width:parent.width/4;
    height:parent.height
        Button{        text: "Назад";height:parent.height/4;width:parent.width;
            onClicked: {stackView.source="ThirdPage.qml";}
            }
    }
    Rectangle{
    id:test2;
    anchors.right: parent.right
    width:0.75*parent.width
    color:"black"
    height:parent.height
        Text {id:text1
            anchors.top:parent.top;
            width:parent.width;
            color: "white"
            font.family: "Helvetica"
            font.pointSize : 20
            text: qsTr("Установите датчик на расстояние 1 cм. ")
        }
        Text {id:text2
            anchors.top:text1.bottom;
            width:parent.width;
            color: "white"
            font.family: "Helvetica"
            font.pointSize : 20
            text: qsTr("от поверхности и нажмите <Установлено> ")
        }
        Button{
            id:firstButton
            visible:true;
            anchors.verticalCenter:parent.verticalCenter;
            anchors.horizontalCenter:parent.horizontalCenter;
            text: "Установлено";
            height:parent.height/4;
            width:parent.width;
            onClicked:{
                dataSource.calibrate1();
                text1.text=qsTr("Установите датчик на расстояние 10 мкм. ")
                firstButton.visible=false;
                secondButton.visible=true;
            }
        }
        Button{
            id:secondButton
            visible:false
            anchors.verticalCenter:parent.verticalCenter;
            anchors.horizontalCenter:parent.horizontalCenter;
            text: "Установлено";
            height:parent.height/4;
            width:parent.width;
            onClicked:{
                dataSource.calibrate2();
                text1.text=qsTr("Калиборвка завершена ")
                text2.text=qsTr("  ")
                thirdButton.visible=true;
                secondButton.visible=false;
            }
        }
        Button{
            id:thirdButton
            visible:false
            anchors.verticalCenter:parent.verticalCenter;
            anchors.horizontalCenter:parent.horizontalCenter;
            text: "Повторная калибровка";
            height:parent.height/4;
            width:parent.width;
            onClicked:{
                text1.text=qsTr("Установите датчик на расстояние 1 cм. ")
                text2.text=  qsTr("от поверхности и нажмите <Установлено> ")
                firstButton.visible=true;
                secondButton.visible=false;
                thirdButton.visible=false;
            }
        }
    }

}
