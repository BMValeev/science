import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "."
import "../../MenuClasses"
Item{
    id:root
    width:parent.width
    height:parent.height
    MenuInt{
        value:devicemodel.cscene.color
    }
}
