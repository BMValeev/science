import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
import "../../MenuClasses"
import "../../FileSystem"
Item{
    id:root
    width:parent.width
    height:parent.height
    MenuLoader{element:"../../FileSystem/FileBrowser.qml"}
    //MenuLoader{element:"../../Pages/ButtonPage.qml"}
}
