import QtQuick 2.12
import AdvancedRayTracer 1.0

FbItem {
    objectName: "fbItem"
    // width: parent.width
    // height: parent.height
    Keys.onPressed: mainController.fbItem.keyPressed(event.key)

    MouseArea {
        anchors.fill: parent
        onClicked: parent.focus = true
    }
}
