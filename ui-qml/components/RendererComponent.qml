import QtQuick 2.12
import AdvancedRayTracer 1.0

Item {
    RendererController {
        objectName: "rendererController"
        width: parent.width
        height: parent.height
        // SequentialAnimation on t {
        //     NumberAnimation { to: 1; duration: 2500; easing.type: Easing.InQuad }
        //     NumberAnimation { to: 0; duration: 2500; easing.type: Easing.OutQuad }
        //     loops: Animation.Infinite
        //     running: true
        // }
    }
}
