import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
Item{
    property bool   currentVal: false
    property bool   realVal: false
    property color mainColor :"#000000"
    property color fontColor :   "white"
    property color sliderColor :   "cyan"
    signal clicked
    id:root
    focus:true
    width:parent.width
    height:parent.height
    Switch {
        id:switcher
        anchors { horizontalCenter: parent.horizontalCenter}
        height:parent.height
        style: switchStyle
        checked:currentVal
    }
    Component {
        id: switchStyle
        SwitchStyle {
            groove: Rectangle {
                implicitHeight: 50
                implicitWidth: 152
                Rectangle {
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                    width: parent.width/2 - 2
                    height: 20
                    anchors.margins: 2
                    color: control.checked ? "#468bb7" : "#222"
                    Behavior on color {ColorAnimation {}}
                    Text {
                        font.pixelSize: 23
                        color: (realVal)?"cyan":"white"
                        anchors.centerIn: parent
                        text: "Вкл"
                    }
                }
                Item {
                    width: parent.width/2
                    height: parent.height
                    anchors.right: parent.right
                    Text {
                        font.pixelSize: 23
                        color: (realVal)?"white":"cyan"
                        anchors.centerIn: parent
                        text: "Выкл"
                    }
                }
                color: "#222"
                border.color: "#444"
                border.width: 2
            }
            handle: Rectangle {
                width: parent.parent.width/2
                height: control.height
                color: "#444"
                border.color: "#555"
                border.width: 2
            }
        }
    }
}
