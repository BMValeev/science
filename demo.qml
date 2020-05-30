
import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import "content/Pages"
import "content/Delegates"
import "content/Regulators"
import "content/MenuOptions"
ApplicationWindow {
    id: main
    visible: true
    //focus: true
    width: 800
    height: 480
    color: "#000000"
    property color buttonColor :"#000000"
    property color selectedColor :   "white"
        StackView {
            id: stackView
            anchors.fill: parent
            focus: true
            initialItem: mainThing
                onCurrentItemChanged: {if (currentItem) {currentItem.forceActiveFocus()}                }
            //Component.onCompleted:{currentItem.forceActiveFocus()}
        }
    Column{
    id: mainThing
    anchors.fill:parent
    Keys.onPressed: {
            console.log("pressed")
            leftBtn.textColor= (event.key == Qt.Key_Left)? "cyan" :"white"
            rightBtn.textColor= (event.key == Qt.Key_Right)? "cyan" :"white"
            upBtn.textColor= (event.key == Qt.Key_Up)? "cyan" :"white"
            downBtn.textColor= (event.key == Qt.Key_Down)? "cyan" :"white"
            menuBtn.textColor= (event.key == Qt.Key_Escape)? "cyan" :"white"
            recordBtn.textColor= (event.key == Qt.Key_R)? "cyan" :"white"
            screenBtn.textColor= (event.key == Qt.Key_E)? "cyan" :"white"
            disableBtn.textColor= (event.key == Qt.Key_Q)? "cyan" :"white"
            chooseBtn.textColor= (event.key == Qt.Key_Return)? "cyan" :"white"
            balBtn.textColor= (event.key == Qt.Key_W)? "cyan" :"white"
            bytesBtn.textColor= (event.key == Qt.Key_T)? "cyan" :"white"
            bitsBtn.textColor= (event.key == Qt.Key_Y)? "cyan" :"white"
            noBtn.textColor= (event.key == Qt.Key_U)? "cyan" :"white"
            if(event.key == Qt.Key_Q){Qt.quit()}
            event.accepted = true;
    }
    Keys.onReleased:{
            leftBtn.textColor= "white"
            rightBtn.textColor= "white"
            upBtn.textColor= "white"
            downBtn.textColor= "white"
            menuBtn.textColor= "white"
            recordBtn.textColor= "white"
            screenBtn.textColor= "white"
            disableBtn.textColor= "white"
            chooseBtn.textColor= "white"
            balBtn.textColor= "white"
            bytesBtn.textColor= "white"
            bitsBtn.textColor= "white"
            noBtn.textColor= "white"
            event.accepted = true;
    }
    Row{
        height:parent.height/5
        width:parent.width
        //Keys.onLeftPressed:{console.log("111")}
        Button{
            id:upBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.upButton ? "red": buttonColor
            text:"Up"
            textColor:selectedColor
            //textColor:devicemodel.btest.upButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:leftBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.leftButton ? "red": buttonColor
            textColor:selectedColor
            text:"Left"
            //textColor:devicemodel.btest.leftButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:rightBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.rightButton ? "red": buttonColor
            textColor:selectedColor
            text:"Right"
            //textColor:devicemodel.btest.rightButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:downBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.downButton ? "red": buttonColor
            textColor:selectedColor
            text:"Down"
            //textColor:devicemodel.btest.downButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:menuBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.menuButton ? "red": buttonColor
            textColor:selectedColor
            text:"Menu"
            //textColor:devicemodel.btest.menuButton ?"white": "cyan";
            enabled:false
        }
    }
    Row{
        height:parent.height/5
        width:parent.width
        Button{
            id:chooseBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.enterButton ? "red": buttonColor
            textColor: selectedColor
            text:"Enter"
            //textColor:devicemodel.btest.enterButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:recordBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.recordButton ? "red": buttonColor
            textColor: selectedColor
            text:"Record"
            //textColor:devicemodel.btest.recordButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:screenBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.screenButton ? "red": buttonColor
            textColor: selectedColor
            text:"Photo"
            //textColor:devicemodel.btest.screenButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:balBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.balButton ? "red": buttonColor
            textColor: selectedColor
            text:"Balance"
            //textColor:devicemodel.btest.balButton ?"white": "cyan";
            enabled:false
        }
        Button{
            id:disableBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.offButton ? "red": buttonColor
            textColor: selectedColor
            text:"Off"
            //textColor:devicemodel.btest.offButton ?"white": "cyan";
            enabled:false
        }
    }
    Row{
        height:parent.height/5
        width:parent.width
        Button{
            height:parent.height
            width:parent.width/5
            bgColor:"gray"
            text:"Up"
            onClicked:{ devicemodel.btest.upBtn=devicemodel.btest.upBtn+1}
        }
        Button{
            height:parent.height
            width:parent.width/5
            bgColor:"gray"
            text:"Left"
            onClicked:{ devicemodel.btest.leftBtn=devicemodel.btest.leftBtn+1}
        }
        Button{
            height:parent.height
            width:parent.width/5
            bgColor:"gray"
            text:"Right"
            onClicked:{ devicemodel.btest.rightBtn=devicemodel.btest.rightBtn+1}
        }
        Button{
            height:parent.height
            width:parent.width/5
            bgColor:"gray"
            text:"Down"
            onClicked:{ devicemodel.btest.downBtn=devicemodel.btest.downBtn+1}
        }
        Button{
            height:parent.height
            width:parent.width/5
            bgColor:"gray"
            text:"Menu"
            onClicked:{ devicemodel.btest.menuBtn=devicemodel.btest.menuBtn+1}
        }
    }
    Row{
        height:parent.height/5
        width:parent.width
        Button{
            height:parent.height
            width:parent.width/4
            bgColor:"gray"
            text:"Record"
            onClicked:{ devicemodel.btest.recordBtn=devicemodel.btest.recordBtn+1}
        }
        Button{
            height:parent.height
            width:parent.width/4
            bgColor:"gray"
            text:"Photo"
            onClicked:{ devicemodel.btest.screenBtn=devicemodel.btest.screenBtn+1}
        }
        Button{
            height:parent.height
            width:parent.width/4
            bgColor:"gray"
            text:"Balance"
            onClicked:{ devicemodel.btest.balBtn=devicemodel.btest.balBtn+1}
        }
        Button{
            height:parent.height
            width:parent.width/4
            bgColor:"gray"
            text:"Quit"
            onClicked:{ Qt.quit()}
        }
    }
    Row{
        height:parent.height/5
        width:parent.width
        Button{
            id:bytesBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.byteButton ? "red": buttonColor
            //textColor: selectedColor
            text:"Byte err"
            //textColor:devicemodel.btest.byteButton ?"white": "cyan"
            enabled:false
        }
        Button{
            id:bitsBtn
            height:parent.height
            width:parent.width/5
            //bgColor: buttonColor
            bgColor: devicemodel.btest.bitButton ? "red": buttonColor
            textColor: selectedColor
            text:"Bit err"
            enabled:false
        }
        Button{
            id:noBtn
            height:parent.height
            width:parent.width/5
            bgColor: devicemodel.btest.noButton ? "red": buttonColor
            textColor: selectedColor
            text:"No button"
            //textColor:devicemodel.btest.noButton ?"white": "cyan"
            enabled:false
        }

    }
    }
}
/*


*/
