import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
Item{
    property int minYear: 1970
    property int maxSecond: 59
    property int maxMinute: 59
    property int maxHour: 23
    property int maxMonth: 12
    property int maxYear: 2070
    property int maxDay: 31
    property int minValue: 1
    property int curSecond: 0
    property int curMinute: 0
    property int curHour: 0
    property int curMonth: 6
    property int curYear: 1991
    property int curDay: 13
    property int maxControl:6
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
        if(focusedItem<maxControl){focusedItem=focusedItem+1 }
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
             text: curDay
             enabled: false
             focus:(focusedItem==1)
             Keys.onDownPressed:  {if(curDay>minValue){curDay=curDay-1}}
             Keys.onUpPressed: {if(curDay<maxDay){curDay=curDay+1}}
         }
         Button{
                text:"."
                bgColor: mainColor
                width: lineValue1.width/3
         }
         Button {
             id:lineValue2
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: curMonth
             enabled: false
             focus:(focusedItem==2)
             Keys.onDownPressed:  {if(curMonth>minValue){curMonth=curMonth-1}}
             Keys.onUpPressed: {if(curMonth<maxMonth){curMonth=curMonth+1}}
         }
         Button{
                text:"."
                bgColor: mainColor
                width: lineValue1.width/3
         }
         Button {
             id:lineValue3
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: curYear
             enabled: false
             focus:(focusedItem==3)
             Keys.onDownPressed:  {if(curYear>minYear){curYear=curYear-1}}
             Keys.onUpPressed: {if(curYear<maxYear){curYear=curYear+1}}
         }
         Button{
                text:" "
                bgColor: mainColor
                width: lineValue1.width/3
         }
         Button {
             id:lineValue4
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: curHour
             enabled: false
             focus:(focusedItem==4)
             Keys.onDownPressed:  {if(curHour>minValue){curHour=curHour-1}}
             Keys.onUpPressed: {if(curHour<maxHour){curHour=curHour+1}}
         }
         Button{
                text:":"
                bgColor: mainColor
                width: lineValue1.width/3
         }
         Button {
             id:lineValue5
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: curMinute
             enabled: false
             focus:(focusedItem==5)
             Keys.onDownPressed:  {if(curMinute>minValue){curMinute=curMinute-1}}
             Keys.onUpPressed: {if(curMinute<maxMinute){curMinute=curMinute+1}}
         }
         Button{
                text:":"
                bgColor: mainColor
                width: lineValue1.width/3
         }
         Button {
             id:lineValue6
             bgColor: mainColor
             textColor: focus? sliderColor:fontColor
             text: curSecond
             enabled: false
             focus:(focusedItem==6)
             Keys.onDownPressed:  {if(curSecond>minValue){curSecond=curSecond-1}}
             Keys.onUpPressed: {if(curSecond<maxSecond){curSecond=curSecond+1}}
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
