import QtQuick 2.11
import QtQuick.Window 2.4
import QtQuick.Controls 2.4
import QtQml 2.11
import AdvancedRayTracer 1.0
import "../components"

ApplicationWindow {
    id: root

    visible: true
    width: 1280
    height: 720
    title: qsTr("AdvancedRayTracer")

    header: MenuComponent {
        id: menu
        width: parent.width
    }
}
