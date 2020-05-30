import QtQuick 2.0
Rectangle {
    property string source
    property color bgColor: "black"
    color :bgColor
    id: root
    focus:true
    Image {
        id: content
        source: parent.source
        anchors{fill:parent; centerIn: parent;}
        focus:true
    }
    function init(){content.initialize()}
    Component.onCompleted: {}
    Keys.onPressed: {
        //if (event.key===Qt.Key_Return||event.key===Qt.Key_Select){event.accepted = true;}
        if (event.key===Qt.Key_Return||event.key===Qt.Key_Select){parent.show(true);}
        //else if (event.key === Qt.Key_Up) {parent.show(true);}
        event.accepted = true;
    }
}
