import AdvancedRayTracer 1.0
import QtQuick 2.12

CustomPaintedItem {
    objectName: "paintedItem"
    // TODO : a scene2D controller
    Keys.onPressed: keyPressedEvent(event.key)
}