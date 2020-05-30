import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "../../Regulators"
Item{
    property alias   status: insertBtn.text
    property alias   mountable: montableBtn.text
    property alias   isMounted: mountBtn.text
    id:root
    width:parent.width
    height:parent.height/5
    anchors.bottom:parent.bottom
    Rectangle{
        color:"cyan"
        radius:75
        anchors.fill:parent
            Column{
            height:50
            
                Row{
                    height:parent.height
                    Button{text:"Usb Носитель: "}
                    Button{id:insertBtn; text:"Обнаружен"}

                }
                Row{
                    height:parent.height
                    Button{text:"Файловая система: "}
                    Button{  id:mountBtn; text:"Fat32"}
                }
                Row{
                    height:parent.height
                    Button{text:"Статус: "}
                    Button{id:montableBtn; text:"не монтируется"}
                }
                ProgressBar{height:parent.height}
            }

    }
}
