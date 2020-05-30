import QtQuick 2.0
Rectangle {
    id: root
    color: "transparent"
    property string source
    property real volume
    property bool started: false
    signal initialized
    signal error
    signal videoFramePainted
    Loader {id: contentLoader}
    Connections {
        id: errorConnection
        onFatalError: {
            console.log("[qmlvideo] Content.onFatalError");
            stop();
            root.error();
        }
        ignoreUnknownSignals: true
    }
    onWidthChanged: {if (contentItem()){contentItem().width = width}     }
    onHeightChanged: { if (contentItem()){contentItem().height = height} }
    function initialize() {
        contentLoader.source = "VideoItem.qml"
        if (Loader.Error == contentLoader.status) {root.error();}
        contentLoader.item.volume = volume
        if (contentLoader.item) {
            contentLoader.item.sizeChanged.connect(updateRootSize)
            contentLoader.item.parent = root
            contentLoader.item.width = root.width
            errorConnection.target = contentLoader.item
            root.start()
        }
        root.initialized()
    }
    function start() {
        if (contentLoader.item) {
            contentLoader.item.mediaSource = root.source
            contentLoader.item.start();
            root.started = true;
        }
    }
    function stop() {
        if (contentLoader.item) {
            contentLoader.item.stop()
            contentLoader.item.mediaSource = ""
            root.started = false
        }
    }
    function contentItem() { return contentLoader.item }
    function updateRootSize() { root.height = contentItem().height }
    Component.onCompleted: {}
}
