import QtQuick 2.0
Rectangle {
    property string source
    property real volume
    property color bgColor: "black"
    color :bgColor
    id: root
    focus:true
    Content {
        id: content
        source: parent.source
        anchors{fill:parent; centerIn: parent;}
        focus:true
    }
    SeekControl {
        anchors {left: parent.left;right: parent.right;margins: 10;bottom: parent.bottom;}
        duration: content.contentItem() ? content.contentItem().duration : 0
        playPosition: content.contentItem() ? content.contentItem().position : 0
        onSeekPositionChanged: {content.contentItem().seek(seekPosition);}
    }
    function init(){content.initialize()}
    Component.onCompleted: {}
    Keys.onPressed: {
                //if (event.key===Qt.Key_Return||event.key===Qt.Key_Select){event.accepted = true;}
                if (event.key===Qt.Key_Return||event.key===Qt.Key_Select){parent.show(true);}
                else if (event.key === Qt.Key_Down) {
                    if(content.contentItem().status){content.contentItem().pause()}
                    else{content.contentItem().start()}
                }
                else if (event.key === Qt.Key_Right) {
                    if((content.contentItem().duration-content.contentItem().position)<10000){content.contentItem().seek(content.contentItem().duration)}
                    else{content.contentItem().seek(content.contentItem().position+10000)}
                }
                else if (event.key === Qt.Key_Left) {
                    if(content.contentItem().position<10000){content.contentItem().seek(0)}
                    else{content.contentItem().seek(content.contentItem().position-10000)}
                }
                //else if (event.key === Qt.Key_Up) {parent.show(true);}
                //else if (event.key === Qt.Key_Up) {parent.show(true);}
                event.accepted = true;
            }
}
