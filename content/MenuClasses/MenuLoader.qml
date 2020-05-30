import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
import "../Regulators"
Item{
    id:root
    property url element
    width:parent.width
    height:parent.height
    Enabler{
        Keys.onReturnPressed:{
            if(focusedItem==1){stackView.push(Qt.resolvedUrl(element)); }
        }
        onFocusedItemChanged:{
            if(focusedItem==0){        main.navStatus("bool");        }
            if(focusedItem==1){        main.navStatus("apply");        }
        }
    }
}
