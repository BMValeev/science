import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
Item{
    property int maxValue: 100
    property int minValue: 0
    property int currentVal:0
    property color mainColor :"#000000"
    property color fontColor :   "white"
    property color sliderColor :   "cyan"
    property int butHeight:60
    signal clickedUp
    signal clickedDown
    id:root
    focus:true
    width:parent.width
    height:parent.height
    //Keys.onLeftPressed: {if(currentVal>minValue){currentVal=currentVal-1}}
    //Keys.onRightPressed:{if(currentVal<maxValue){currentVal=currentVal+1}}
    Keys.onReturnPressed:{root.clicked()}
    //function plus{if(currentVal>minValue){currentVal=currentVal-1}}
    //function minus{if(currentVal<maxValue){currentVal=currentVal+1}}
Rectangle{
    focus:true
    width:parent.width
    height: butHeight
    color:mainColor
     anchors { horizontalCenter: parent.horizontalCenter;
               verticalCenter: parent.verticalCenter;}
    Rectangle{
        id:valSelector
        width:parent.width
        height:parent.height
        color:mainColor
        ProgressBar {
            id:line
            anchors{
                margins:5
                left:parent.left
                top:parent.top
                bottom:parent.bottom
            }
            style: touchStyle
            width: parent.width-3*lineValue.width
            value: currentVal/maxValue
        }
        Button {
            id:lineValue
            width:parent.height
            height: parent.height
            anchors.left:line.right
            bgColor: mainColor
            textColor: fontColor
            text: currentVal
            enabled: false
        }
        Button {
            id:dec
            width:parent.height
            height: parent.height
            anchors.left:lineValue.right
            bgColor: mainColor
            textColor: fontColor
            text: "-"
            enabled: true
            onClicked: clickedDown();
        }
            Button {
                id:inc
                width:parent.height
                height: parent.height
                anchors.left:dec.right
                bgColor: mainColor
                textColor: fontColor
                text: "+"
                enabled: true;
                onClicked: clickedUp();
            }
    }
}
Component {
    id: touchStyle
    ProgressBarStyle {
        panel: Rectangle {
            radius: 10
            implicitHeight: 15
            implicitWidth: 400
            color: root.fontColor
            Rectangle {
                antialiasing: true
                radius: 10
                color: root.sliderColor
                height: parent.height
                width: parent.width * control.value / control.maximumValue
            }
        }
    }
}

}
