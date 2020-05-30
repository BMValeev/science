
import QtQuick 2.2
import QtQuick.Controls 1.2 //as CCC1
import QtQuick.Controls 2.2 as CCC2
import QtQuick.Controls.Styles 1.1
import "content/Pages"
import "content/Delegates"
import "content/Regulators"
import "content/MenuOptions"
import "content/Popups"
import "content/FileSystem"
ApplicationWindow {
    id: main
    visible: true
    width: 800
    height: 480
    color: "#000000"
    property color buttonColor :"#000000"
    property color selectedColor :   "white"
    Loader {
        id: stackView
        anchors.fill: parent
        //focus: true
        //initialItem: SecondPage{}
        //initialItem: ThirdPage{}
        source: "content/Pages/ThirdPage.qml"
        //onCurrentItemChanged: {if (currentItem) {currentItem.defaultFocusItem.focus = true; }}
        //visible:true
    }

    //Component.onCompleted:{dataSource.generateData();}
}