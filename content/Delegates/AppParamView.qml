
import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "../Regulators"
ListView {
    property ListModel testedModel
    property color mainColor: "#000000"
    id:test1
    focus: true
    model: testedModel
    width: parent.width
    height: parent.height
    delegate: ParamDelegate {
        buttonColor:mainColor
        text: title
        source: src
        selectedColor: ListView.isCurrentItem ? "cyan" : "white"
        onClicked: {if(title=="Назад"){stackView.pop();}}
        currentFocus: ListView.isCurrentItem ? true : false
    }
}
