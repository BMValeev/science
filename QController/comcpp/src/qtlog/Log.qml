//import QtQml.Models 2.2
import Qt.labs.folderlistmodel 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import style 1.0
import qtlog 1.0

Rectangle {
    id: root
    color: "white"
    border.width: 2
    border.color: "lightgray"
    property bool drawerEnabled: root.enabled
    property alias filterTextField: regexpTextField
    signal keysPressed()

    function colorLog(datetime,threadNumber,msgcat,msgsubcat,file,callFunction,lineNumber,msg) {
        var caller = '['+file+'|'+callFunction+'|'+lineNumber+']';
        threadNumber = '(' + threadNumber + ')';
        msg += ' ';
        // Coloring
        switch (msgcat) {
        case "WRN:":
            datetime = coloredString(datetime,'#ffff99');
            threadNumber = coloredString(threadNumber+' ','#ffff99');
            msgcat = coloredString(msgcat,"Yellow") + ' ';
            msg = coloredString(msg,"#ffffAA");
            caller = coloredString(caller,"#e6ccb3");
            break;
        case "CRT:":
            datetime = coloredString(datetime,'#ff5555');
            threadNumber = coloredString(threadNumber,'#ff5555');
            msgcat = coloredString(msgcat,"#ff0000") + ' ';
            msg = coloredString(msg,"#ff7777");
            caller = coloredString(caller,"#ff5555");
            break;
        case "FTL:":
            datetime = coloredString(datetime,'red');
            threadNumber = coloredString(threadNumber,'red');
            msgcat = coloredString(msgcat,'red') + ' ';
            msg = coloredString(msg,'red');
            caller = coloredString(caller,'red');
            break;
        case "DBG":
            datetime = coloredString(datetime,'#b3e6ff');
            threadNumber = coloredString(threadNumber,'#A0ffA0');
            msgcat = coloredString(msgcat,"#cc9900") + ' ';
            msgsubcat = coloredString(msgsubcat,"#cc9900") + ' ';
            caller = coloredString(caller,"#e6ccb3");
            break;
        default:
            datetime = coloredString(datetime,'#b3e6ff');
            threadNumber = coloredString(threadNumber,'#A0ffA0');
            msgcat = coloredString(msgcat,"#f2f2f2") + ' ';
            msgsubcat = coloredString(msgsubcat,"#f2f2f2") + ' ';
            caller = coloredString(caller,"#e6ccb3");
            break;
        }

        return datetime + threadNumber + msgcat + msgsubcat + msg + caller;
    }

    function coloredString(s,color) {
        return '<font color="' + color + '">' + s + '</font>'
    }

    LogSortFilterProxyModel {
        id: filteredModel
        source: logModel
        filterRegExp: { new RegExp(regexpTextField.text) }
        filterRole: logModel.roleIndexForStringName(filterRoleCombobox.currentText)
    }


    LogModel{
        id: logModel
    }

    LogFileModel{
        id: logFileModel
        source: ""
    }

    Component {
        id: logMessageDelegate
        Rectangle{
            implicitHeight: Math.max(20,dText.implicitHeight + 2*dText.anchors.margins)
            width: parent.width
            color: "black"
            Text{
                id: dText
                text: colorLog(datetime,
                               threadNumber,
                               type,
                               category,
                               file,
                               callFunction,
                               lineNumber,
                               message)
                anchors.fill: parent
                anchors.margins: 1
                color: "white"
                wrapMode: Text.Wrap
            }
        }
    }

    Drawer {
        id: fileDrawer
        edge: Qt.RightEdge
        width: parent.width * 0.33
        height: parent.height
        //parent: root
        interactive: drawerEnabled
        Rectangle {
            id: drawerBackground
            anchors.fill: parent
            color: "gray"
        }

        ColumnLayout {
            spacing: 2
            rotation: Style.layout.screenRotation
            anchors.fill: parent
            anchors.leftMargin: 2

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 50
                color: ma.pressed? "gray" : "black"
                Text {
                    anchors.fill: parent
                    anchors.margins: 10
                    text: qsTr("Текущий лог")
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 500
                    font.bold: true
                    fontSizeMode: Text.Fit
                    clip: true
                }
                MouseArea {
                    id: ma
                    anchors.fill: parent
                    onClicked: {
                        filteredModel.source = logModel

                        fileDrawer.close()
                    }
                }
            }

            ListView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                model: folderModel
                delegate: fileDelegate
                clip: true

                FolderListModel {
                    id: folderModel
                    showDirsFirst: true
                    showOnlyReadable: true
                    //nameFilters: ['log*','wclog*']
                }

                Component {
                    id: fileDelegate
                    ItemDelegate {
                        id: deleg
                        text: fileName
                        font.pixelSize: Qt.application.font.pixelSize
                        width: parent.width
                        background: Rectangle {
                            border.width: 2
                            border.color: "gray"
                            color: {
                                var c = folderModel.isFolder(index)? "orange" : "lightgray"
                                c = deleg.pressed? Qt.lighter(c,1.25) : c
                                return c
                            }
                        }
                        onClicked: {
                            // If the folder is clicked we browse into it
                            if (folderModel.isFolder(index)) {
                                folderModel.folder += "/" + fileName
                                return
                            }
                            // Set the model to a file model
                            logFileModel.source = (folderModel.folder + "/" + fileName).replace(/^(file:\/{3})/,"/")
                            filteredModel.source = logFileModel

                            fileDrawer.close()
                        }
                    }
                }
            }
            Button {
                id: backBtn
                Layout.fillWidth: true
                Layout.minimumHeight: 50
                text: qsTr("Back")
                onClicked: folderModel.folder = folderModel.parentFolder
                background: Rectangle {
                    color: backBtn.pressed? Qt.lighter("lightgray",1.25) : "lightgray"
                }
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        RowLayout {
            Layout.preferredHeight: 45
            Layout.fillWidth: true
            Layout.fillHeight: false
            spacing: 0

            ComboBox {
                id: filterRoleCombobox
                Layout.preferredWidth: 200
                Layout.fillHeight: true
                model: [ "datetime", "threadNumber", "type", "category", "message", "file", "callFunction", "lineNumber" ]
            }
            TextField {
                id: regexpTextField
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "white"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                autoScroll: false
                clip: true
                placeholderText: "regular expression"
                font.pixelSize: 30
                background: Rectangle {
                    id: back
                    color: "black"
                    border.width: 2
                    border.color: "lightgray"
                }
                Keys.onPressed: root.keysPressed()
                maximumLength: 35
            }
        }
        ListView {
            id: logListView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 2
            spacing: 1
            clip: true
            model: filteredModel
            Component.onCompleted: {
                positionViewAtEnd();
            }
            onCountChanged: {
                positionViewAtEnd();
            }
            delegate: logMessageDelegate
        }
    }
}
