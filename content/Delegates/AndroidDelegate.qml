
import QtQuick 2.2
import "../Delegates"
import "../Regulators"
import "../Pages"
Item {
    id: root
    width: parent.width
    height: 88
    focus: true
    property alias text: but.text
    signal clicked
    property int itemHeight: 25
    property color buttonColor: "#000000"
    property color selectedColor: "#000000"
    Keys.onReturnPressed: root.clicked()
    Button {
        id:but
        width: parent.width
        height: parent.height
        bgColor: buttonColor
        text: modelData
        textColor: selectedColor
        enabled: false
    }
}
