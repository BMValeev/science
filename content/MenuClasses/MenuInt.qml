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
    Regulator{
        currentVal: value.val
        onClickedUp: {value.val=value.val+1}
        onClickedDown:{value.val=value.val -1}
        maxValue: value.maxVal
        minValue: value.minVal
    }
}
