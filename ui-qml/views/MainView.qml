import QtQuick 2.3
import QtQuick.Window 2.4
import QtQuick.Controls 2.4
import QtQml 2.3
// import AdvancedRayTracer 1.0
import "../components"

ApplicationWindow {
    id: root

    visible: true
    width: 1280
    height: 720
    title: qsTr("AdvancedRayTracer")
    
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Save")
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    header: MenuComponent {
        id: menu
        width: parent.width
    }

    SidebarComponent {
        id: sidebar
        anchors {
            top: parent.top
            left: parent.left
            bottom: parent.bottom
        }
        width: 200
        height: parent.height
    }
}
