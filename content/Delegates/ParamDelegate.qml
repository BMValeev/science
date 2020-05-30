import QtQuick 2.2
import "../Regulators"
Item {
    property alias source: paramLoader.source
    property alias text: but.text
    property bool currentFocus: false
    signal clicked
    property var butWidth: 0.6
    property color buttonColor: "#000000"
    property color selectedColor: "#000000"
    Keys.onReturnPressed: {root.clicked(); }
    id: root
    width: parent.width
    height: 88
    focus: true
    Button {
        id:but
        width: parent.width*butWidth
        height: parent.height
        bgColor: buttonColor
        text: modelData
        textColor: selectedColor
        enabled: false
    }
    Loader{
        id:paramLoader
        focus:currentFocus
        anchors.left:but.right
        height:parent.height
        width: parent.width*(1-butWidth)
    }
}
