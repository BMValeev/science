import QtQuick 2.2
import QtQuick.Controls 1.2 //as CCC1
import QtQuick.Controls 2.2 as CCC2
CCC2.Popup{
    property bool enab: false
    id: popup
    parent: CCC2.Overlay.overlay
    x: Math.round( parent.width*0.1  )
    y: Math.round( parent.height*0.7 )
    height:parent.height/4
    width:parent.width*0.75;
    onEnabChanged:{
        if(enab){popup.open()}
        else{popup.close()}
    }
    Component.onCompleted:{if(enab){popup.open()}}
    function setClosed(){enab=false;}
    function setOpened(){enab=true;}
    exit: Transition {NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }}
    enter: Transition {NumberAnimation { property: "opacity"; from: 0.0; to: 1.0 }}
    Rectangle{height:parent.height;width:parent.width;
             color: "white"
             radius: height / 15
             Text {
                 id: text
                 anchors.centerIn: parent
                 text: "Расстояние между датчиком и валом больше 50 мкм"
                 font.pixelSize: 20
                 horizontalAlignment: Text.AlignHCenter
                 verticalAlignment: Text.AlignVCenter
             }
     }
}