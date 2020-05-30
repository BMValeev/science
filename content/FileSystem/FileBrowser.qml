
import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import Qt.labs.folderlistmodel 2.0
import "."
Item {
    property var defaultFocusItem: loader.item
    id: fileBrowser
    property string folder:"file:/home/eleps"
    property string curFolder
    property int itemHeight: Math.min(parent.width, parent.height) / 15
    property int buttonHeight: Math.min(parent.width, parent.height) / 12
    signal fileSelected(string file)
    Keys.onPressed: {}
    Loader {
        id: loader
    Keys.onPressed: { }
    }
    Component {
        id: fileBrowserComponent
    Rectangle {
        function keyPressed(key) {
            switch (key) {
                case Qt.Key_Up:
                case Qt.Key_Down:
                case Qt.Key_Left:
                case Qt.Key_Right:browser.showFocusHighlight = true;break;
                default:break;
            }
        }
        id: browser
        color: "black"
        property bool showFocusHighlight: false
        property color textColor: "white"
        property variant folders: folders1
        property variant view: view1
        property alias folder: folders1.folder
        Rectangle {
            anchors{top:parent.top;left: parent.left;right: parent.right;}
            id: titleBar
            height: buttonHeight + 10
            color: "black"
            Rectangle {
                anchors{top:parent.top;margins:5;left: parent.left;right: parent.right;}
                height: buttonHeight
                color: "#212121"
                radius: buttonHeight / 15
                Text {
                    anchors{left:parent.left;right: parent.right;leftMargin: 5;rightMargin: 5;}
                    height: parent.height
                    text: "USB:"+ folders.folder.toString().slice(folders.rootFolder.toString().length)
                    color: "white"
                    elide: Text.ElideLeft;
                    horizontalAlignment: Text.AlignLeft;
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 24
                }
            }
        }
        ListView{
            id: view1
            focus: true
            anchors{ top: titleBar.bottom;bottom: parent.bottom}
            width: parent.width
            model: folders1
            delegate: folderDelegate
            highlight: Rectangle {
                color: "#212121"
                visible: browser.showFocusHighlight && view1.count != 0
                width: view1.currentItem == null ? 0 : view1.currentItem.width
            }
            highlightMoveVelocity: 1000
            pressDelay: 100
            x:0
            Keys.onPressed: {browser.keyPressed(event.key);}
        }
        Keys.onPressed: {
            browser.keyPressed(event.key);
            view1.forceActiveFocus()
            if (event.key===Qt.Key_Return||event.key===Qt.Key_Select){
                if (view.currentItem!=null){
                    view.currentItem.launch();
                    view.currentIndex=0;
                }
                event.accepted = true;
            }
        }
        FolderListModel {
            id: folders1;
            rootFolder:fileBrowser.folder
            folder: browser.folder;
            nameFilters: [ "*.png", "*.jpg" , "*.avi" ];
            showDotAndDotDot :true
        }
        Component {id: folderDelegate
        Rectangle {
            id: wrapper
            width: browser.width
            height: folderImage.height
            color: "transparent"
            Rectangle {
                id: highlight
                visible: false
                anchors{fill: parent;leftMargin: 5;rightMargin: 5}
                color: "#212121"
            }
            Item {
                id: folderImage
                width: itemHeight
                height: itemHeight
                Image {
                    id: folderPicture
                    anchors{left: parent.left;margins: 5;}
                    source: (wrapper.ListView.isCurrentItem) ?"qrc:/folder_open.png": "qrc:/folder.png";
                    width: itemHeight * 0.9
                    height: itemHeight * 0.9
                    visible: folders.isFolder(index)
                }
                Image {id: imagePicture
                    anchors{left: parent.left;margins: 5;}
                    source: "qrc:/image.png"
                    width: itemHeight * 0.9
                    height: itemHeight * 0.9
                    visible: isImage()
                }
                Image {id: videoPicture
                    anchors{left: parent.left;margins: 5;}
                    source: "qrc:/video.png"
                    width: itemHeight * 0.9
                    height: itemHeight * 0.9
                    visible: isVideo()
                }
            }
            Text {
                id: nameText
                anchors{fill: parent;leftMargin: itemHeight + 10;}
                verticalAlignment: Text.AlignVCenter
                text: fileName
                color: (wrapper.ListView.isCurrentItem && browser.showFocusHighlight) ? palette.highlightedText : textColor
                elide: Text.ElideRight
            }
            states: [
            State {
                name: "pressed"
                when: mouseRegion.pressed
                PropertyChanges { target: highlight; visible: true }
                PropertyChanges { target: nameText; color: palette.highlightedText }
            }
            ]
        SystemPalette {id: palette}
        function launch() {
            var path ="file://";
            path += filePath;
            if(folders.rootFolder.toString()+"/."==path.toString()){stackView.pop();}
            if (folders.isFolder(index)){down(path);}
            else if(isVideo()){
                curFolder=folder
                loader.source="VideoSeek.qml"
                loader.item.source=path
                loader.item.volume=0
                loader.item.parent = fileBrowser;
                loader.item.anchors.fill = fileBrowser;
                loader.item.init();
                }
            else if(isImage()){
                curFolder=folder
                loader.source="ImageFile.qml"
                loader.item.source=path
                loader.item.parent = fileBrowser;
                loader.item.anchors.fill = fileBrowser;
                }
            else {fileBrowser.selectFile(path);}
        }
        function isImage() {
            var suffix=folders.get(index,"fileSuffix")
            if((suffix==="png" )||(suffix==="jpg" )){return true}
            else{return false}
        }
        function isVideo() {
            var suffix=folders.get(index,"fileSuffix")
            if(suffix==="avi" ){return true}
            else{return false}
        }
        }
        }
        function down(path) {
            if(folders.folder.toString().search(folders.rootFolder.toString())!=0){folders.folder =folders.rootFolder;}
            folders.folder = path;
        }
        function up() {
            var path = folders.parentFolder;
            if(folders.folder.toString().search(folders.rootFolder.toString())!=0){folders.folder =folders.rootFolder;}
            if(folders.folder.toString()===folders.rootFolder.toString()){return;}
            if (path.toString().length === 0 || path.toString() === 'file:'){return;}
            folders.folder = path;
        }

    }
}
    function selectFile(file) {
        if (file !== "") {folder = loader.item.folders.folder;fileBrowser.fileSelected(file);}
        else{loader.sourceComponent = undefined}
    }
    function show(old) {
        loader.sourceComponent = fileBrowserComponent;
        loader.item.parent = fileBrowser;
        loader.item.anchors.fill = fileBrowser;
        loader.item.folder =(old)? fileBrowser.curFolder:fileBrowser.folder;
    }
    Component.onCompleted: { show(false)}
}

