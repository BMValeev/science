import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
Item{
    property int maxValue: 255
    property int minValue: 0
    property int   iP1:192
    property int   iP2:168
    property int   iP3:0
    property int   iP4:0
    property int maxControl:4
    property int focusedItem:0
    property color mainColor :"#000000"
    property color fontColor :   "white"
    property color sliderColor :   "cyan"
    property int butHeight:88
    signal clicked
    id:root
    focus:true
    width:parent.width
    height:parent.height
    Keys.onLeftPressed:  {
        if(focusedItem>0){focusedItem=focusedItem-1}
    }
    Keys.onRightPressed: {
        if(focusedItem<maxControl){focusedItem=focusedItem+1; }
    }
    Keys.onReturnPressed:{root.clicked()}
Rectangle{
    width:parent.width
    height: butHeight
    color:mainColor
    anchors { horizontalCenter: parent.horizontalCenter}
    Row{
        width:parent.width
         height: butHeight
         Button {
             id:lineValue1
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: iP1
             enabled: false
             focus:(focusedItem==1)
             Keys.onDownPressed:  {if(iP1>minValue){iP1=iP1-1}}
             Keys.onUpPressed: {if(iP1<maxValue){iP1=iP1+1}}
         }
         Button{
                text:"."
                bgColor: mainColor
                width: lineValue1.width/2
         }
         Button {
             id:lineValue2
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: iP2
             enabled: false
             focus:(focusedItem==2)
             Keys.onDownPressed:  {if(iP2>minValue){iP2=iP2-1}}
             Keys.onUpPressed: {if(iP2<maxValue){iP2=iP2+1}}
         }
         Button{
                text:"."
                bgColor: mainColor
                width: lineValue1.width/2
         }
         Button {
             id:lineValue3
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: iP3
             enabled: false
             focus:(focusedItem==3)
             Keys.onDownPressed:  {if(iP3>minValue){iP3=iP3-1}}
             Keys.onUpPressed: {if(iP3<maxValue){iP3=iP3+1}}
         }
         Button{
                text:"."
                bgColor: mainColor
                width: lineValue1.width/2
         }
         Button {
             id:lineValue4
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: iP4
             enabled: false
             focus:(focusedItem==4)
             Keys.onDownPressed:  {if(iP4>minValue){iP4=iP4-1}}
             Keys.onUpPressed: {if(iP4<maxValue){iP4=iP4+1}}
         }
         Button {
             enabled: false
             visible:false
             focus:(focusedItem==0)
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
            //opacity: 0.8
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
