import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
import "../Regulators"
Item{
    id:root
    property var value: modelData
    width:parent.width
    height:parent.height
    Address{
    id:something
    iP1:value.byte1
    iP2:value.byte2
    iP3:value.byte3
    iP4:value.byte4
    Keys.onLeftPressed:  {if(focusedItem==0){main.navStatus("bool"); }}
    Keys.onRightPressed: {main.navStatus("date");}
    Keys.onReturnPressed:{
        if(focusedItem>0){
            value.byte1=iP1;
            value.byte2=iP2;
            value.byte3=iP3;
            value.byte4=iP4;
        }
    }
    onActiveFocusChanged:{
        if((!activeFocus)&&(focusedItem==0)){ main.navStatus("bool");  }
    }
    }
}
