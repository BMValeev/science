import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "../Service"
import "../../MenuClasses"
Item{
    id:root
    width:parent.width
    height:parent.height
    MenuIP{value:devicemodel.gateIP    }
}
