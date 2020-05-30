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
    ItemSelector{
    id:something
        testedModel:model
        maxValue:value.maxValue
        currentVal:value.curValue
        realVal: value.curValue
        onClicked: {value.curValue=currentVal}
        onActiveFocusChanged:{
            if(activeFocus){        main.navStatus("apply");        }
            else{main.navStatus("menu");     }
        }
    }
    Component.onCompleted:{init()}
    ListModel{id:model}
    function init(){
        for(var i=value.minValue;i<=value.maxValue;i++){
            model.insert(i,{title: value.allNames[i]});
        }
    }
}
