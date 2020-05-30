import QtQuick 2.9
import QtQuick.Layouts 1.3

import LineEditor 1.0

ColumnLayout {
    id: root
    // Aliases
    property alias xSpinBox: xSpinBox
    property alias ySpinBox: ySpinBox
    property alias indexText: indexText
    property alias indexRectangle: indexRectangle

    // Design
    width: 120
    height: 100
    property alias removeBtn: removeBtn
    spacing: 0

    Rectangle {
        id: indexRectangle
        Layout.fillWidth: true
        Layout.preferredHeight: 20
        color: "#000000"

        Text {
            id: indexText
            color: "#ffffff"
            text: "index"
            anchors.rightMargin: 3
            anchors.leftMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3
            font.pointSize: 40
            lineHeight: 1
            fontSizeMode: Text.Fit
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    PointSpinBox {
        id: ySpinBox
        Layout.fillWidth: true
        Layout.preferredHeight: 25
        spinbox.editable: true
    }

    PointSpinBox {
        id: xSpinBox
        Layout.fillWidth: true
        Layout.preferredHeight: 25
        spinbox.editable: true
    }

    Button {
        id: removeBtn
        Layout.fillWidth: true
        Layout.preferredHeight: 25
        text: qsTr("Remove")
    }
}
