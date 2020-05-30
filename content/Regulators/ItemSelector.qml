import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
Item{
    property ListModel testedModel
    property int maxValue: testedModel.count-1
    property int minValue: 0
    property color mainColor: "#000000"
    property color fontColor :   "white"
    property color sliderColor :   "cyan"
    property int currentVal: 1
    property int realVal: 1
    signal clicked
    id:root
    focus:true
    anchors { horizontalCenter: parent.horizontalCenter}
    width:parent.width
    height:parent.height
    Keys.onLeftPressed: {
        if(currentVal>minValue){
            currentVal=currentVal-1
            showBtn.text=testedModel.get(currentVal).title
        }
    }
    Keys.onRightPressed:{
        if(currentVal<maxValue){
            currentVal=currentVal+1
            showBtn.text=testedModel.get(currentVal).title
        }
    }
    Keys.onReturnPressed:{root.clicked()}
    Button{
        id:showBtn
        bgColor:mainColor
        textColor: {(currentVal==realVal) ? sliderColor : fontColor;}
        text: testedModel.get(currentVal).title
        enabled:false
        anchors {fill:parent; horizontalCenter: parent.horizontalCenter}
        Component.onCompleted:{text=testedModel.get(realVal).title}
        }
}

