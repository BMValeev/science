
import QtQuick 2.0
import Qt.labs.folderlistmodel 2.0
import "."
Rectangle {
    id: fileBrowser
    color: "transparent"
    property string folder
    property string curFolder
    property int itemHeight: Math.min(parent.width, parent.height) / 15
    property int buttonHeight: Math.min(parent.width, parent.height) / 12
    signal fileSelected(string file)
    Loader {id: loader    }
    Component {id: fileBrowserComponent
    Rectangle {
        id: root
        color: "black"
        property bool showFocusHighlight: false
        property variant folders: folders1
        property variant view: view1
        property alias folder: folders1.folder
        property color textColor: "white"
        FolderListModel {
            id: folders1;
            rootFolder:fileBrowser.folder
            folder: root.folder;
            nameFilters: [ "*.png", "*.jpg" , "*.avi" ];
            //showDotAndDotDot:true;
        }
        SystemPalette {id: palette}
        ListView {
            id: view1
            anchors{ top: titleBar.bottom;bottom: parent.bottom}
            width: parent.width
            model: folders1
            delegate: folderDelegate
            highlight: Rectangle {
                color: "#212121"
                visible: root.showFocusHighlight && view1.count != 0
                width: view1.currentItem == null ? 0 : view1.currentItem.width
            }
            highlightMoveVelocity: 1000
            pressDelay: 100
            focus: true
            x:0
            Keys.onPressed: root.keyPressed(event.key)
        }
        Keys.onPressed: {
            root.keyPressed(event.key);
            if (event.key===Qt.Key_Return||event.key===Qt.Key_Select||event.key === Qt.Key_Right){
                if (view.currentItem==null){event.accepted = true;return;}
                view.currentItem.launch();//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
                view.currentIndex=0;
                event.accepted = true;
                }
            else if (event.key === Qt.Key_Left) {up();view.currentIndex=0;}
        }
        Rectangle {
            id: titleBar
            width: parent.width
            height: buttonHeight + 10
            anchors.top: parent.top
            color: "black"
            Rectangle {
                anchors{top:parent.top;margins:5;left: parent.left;right: parent.right;}
                width: parent.width;
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
        Component {id: folderDelegate
            Rectangle {
                id: wrapper
                width: root.width
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
                    color: (wrapper.ListView.isCurrentItem && root.showFocusHighlight) ? palette.highlightedText : textColor
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
                function launch() {
                    var path ="file://";
                    path += filePath;
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
        function down(path) {//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
            if(folders.folder.toString().search(folders.rootFolder.toString())!=0){folders.folder =folders.rootFolder;}
            folders.folder = path;
        }
        function up() {//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
            var path = folders.parentFolder;
            if(folders.folder.toString().search(folders.rootFolder.toString())!=0){folders.folder =folders.rootFolder;}
            if(folders.folder.toString()===folders.rootFolder.toString()){return;}
            if (path.toString().length === 0 || path.toString() === 'file:'){return;}
            folders.folder = path;
        }
        function keyPressed(key) {
            switch (key) {
            case Qt.Key_Up:
            case Qt.Key_Down:
            case Qt.Key_Left:
            case Qt.Key_Right:root.showFocusHighlight = true;break;
            default:break;
            }
        }
    }
}
    function selectFile(file) {//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
        if (file !== "") {folder = loader.item.folders.folder;fileBrowser.fileSelected(file);}
        else{loader.sourceComponent = undefined}
    }
    function show(old) {
        loader.sourceComponent = fileBrowserComponent;
        loader.item.parent = fileBrowser;
        loader.item.anchors.fill = fileBrowser;
        loader.item.folder =(old)? fileBrowser.curFolder:fileBrowser.folder;
    }
}
