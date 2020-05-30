import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.2 as CCC1
import QtQuick.Controls 2.2 as CCC2
import QtQuick.Controls.Styles 1.1
import "."
Item{
    property string nameText: "Начать"
    property int focusedItem:0
    property color mainColor :"#000000"
    property color fontColor :   "white"
    property color sliderColor :   "cyan"
    property int butHeight:88
    property bool status:false
    signal clicked
    id:root
    focus:true
    width:parent.width
    height:parent.height
    Keys.onLeftPressed:  { if(focusedItem>0){focusedItem=focusedItem-1}}
    Keys.onRightPressed: {if(focusedItem<1){focusedItem=focusedItem+1 }}
    Keys.onReturnPressed:{}
    Rectangle{
        anchors.left: busy.right
        width:parent.width-busy.width
        height: butHeight
        color:mainColor
        anchors { horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
        Button {
             id:lineValue1
             bgColor: mainColor
             textColor: focus ? sliderColor:fontColor
             text: nameText
             enabled: false
             focus:(focusedItem==1)
             Keys.onDownPressed:  {}
             Keys.onUpPressed: {}
             anchors {verticalCenter: parent.verticalCenter}
        }
        Button {
             enabled: false
             visible:false
             focus:(focusedItem==0)
        }
}
}
