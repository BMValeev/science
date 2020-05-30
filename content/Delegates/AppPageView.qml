
import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "../Delegates"
import "../Regulators"
import "../Pages"
ListView {
    property ListModel testedModel
    property color mainColor: "#000000"
    property color selectedColor: "cyan"
    property color unselectedColor: "white"
    id:test1
    focus: true
    model: testedModel
    width: parent.width
    height: parent.height
    delegate: AndroidDelegate {
                buttonColor:mainColor
                text: title
                selectedColor: ListView.isCurrentItem ? test1.selectedColor : test1.unselectedColor
                onClicked: {
                    if(title==="Назад"||title==="Выход"){stackView.pop();}
                    else{stackView.push(Qt.resolvedUrl(page));}
                }
            }
        }
