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
    Switcher{
    id:but
        realVal: value.val
        onClicked: { but.realVal=(but.realVal) ? false:true;}
    }

}
