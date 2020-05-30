import QtQuick 2.9

import LineEditor 1.0

Item {
    id: root
    // Properties
    property int decimals: 1
    property real from: 0
    property real to: 1
    property real stepSize: 0.1
    property real initialValue: 0.1
    property real value: spinbox.realValue
    // ALiases
    property alias spinbox: spinbox
    property alias backgroundRectangle: backgroundRectangle

    Component.onCompleted: spinbox.value = initialValue * spinbox.factor

    Rectangle {
        id: backgroundRectangle
        anchors.fill: parent
        color: "black"
        border.width: 2
    }

    SpinBox {
        id: spinbox
        // Properties
        property real factor: Math.pow(10, root.decimals)
        property real realValue: value / factor
        // Geometry
        x: 0; y: 0; height: parent.height; width: parent.width
        bottomPadding: 0;
        topPadding: 0;
        font.pointSize: 12;

        stepSize: root.stepSize * factor
        to: root.to * factor
        from: root.from * factor

        contentItem: TextInput {
            z: 2
            text: spinbox.textFromValue(spinbox.value, spinbox.locale)

            //anchors.top: parent.top
            //anchors.bottom: parent.bottom
            //anchors.left: spinbox.down.indicator.right
            //anchors.right: spinbox.up.indicator.left
            baselineOffset: 0
            anchors.centerIn: parent
            font: spinbox.font
            color: "#21be2b"
            selectionColor: "#21be2b"
            selectedTextColor: "#ffffff"
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter


            readOnly: !spinbox.editable
            validator: spinbox.validator
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        validator: DoubleValidator {
            bottom: Math.min(spinbox.from, spinbox.to)*spinbox.factor
            top:  Math.max(spinbox.from, spinbox.to)*spinbox.factor
        }

        textFromValue: function(value, locale) {
            return Number(value*1.0/factor).toLocaleString(locale, 'f', root.decimals)
        }

        valueFromText: function(text, locale) {
            return Number.fromLocaleString(locale, text) * factor
        }
    }
}


/*##^## Designer {
    D{i:0;autoSize:true;height:37;width:120}
}
 ##^##*/
