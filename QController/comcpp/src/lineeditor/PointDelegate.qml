import QtQuick 2.9

import LineEditor 1.0

PointDelegateForm {
    id: root
    indexText.text: index

    // X Value
    xSpinBox.initialValue: xRole
    xSpinBox.onValueChanged: xRole = xSpinBox.value
    xSpinBox.from: 0
    xSpinBox.to: 2000
    xSpinBox.stepSize: 0.1

    // Y Value
    ySpinBox.initialValue: yRole
    ySpinBox.onValueChanged: yRole = ySpinBox.value
    ySpinBox.from: 0
    ySpinBox.to: 5000
    ySpinBox.stepSize: 0.1

    ListView.onRemove: SequentialAnimation {
        PropertyAction {
            target: root
            property: "ListView.delayRemove"
            value: true
        }
        NumberAnimation {
            target: root
            property: "height"
            to: 0
            easing.type: Easing.InOutQuad
        }
        PropertyAction {
            target: root
            property: "ListView.delayRemove"
            value: false
        }
    }
}
