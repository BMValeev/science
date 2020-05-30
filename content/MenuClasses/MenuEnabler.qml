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
    Enabler{
        id:enTest
        status: value.val
        Keys.onReturnPressed:{
            if(focusedItem==1){value.val=!value.val; }
        }
        onFocusedItemChanged:{
            if(focusedItem==0){        main.navStatus("bool");        }
            if(focusedItem==1){        main.navStatus("apply");        }
        }
    }
}
