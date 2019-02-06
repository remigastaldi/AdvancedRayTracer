import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQml 2.12
import AdvancedRayTracer 1.0
import "../components"

ApplicationWindow {
    id: root
    visible: true
    title: qsTr("AdvancedRayTracer")

    width: appContent.implicitWidth
    height: appContent.implicitHeight

    property int topOffset: menuBar.implicitHeight + header.implicitHeight
    minimumWidth: appContent.Layout.minimumWidth
    maximumWidth: appContent.Layout.maximumWidth
    minimumHeight: appContent.Layout.minimumHeight + topOffset
    maximumHeight: appContent.Layout.maximumHeight + topOffset

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

    header: ToolbarComponent {
        id: menu
    }

    RowLayout {
        id: appContent

        anchors.fill: parent

        SidebarComponent {
            id: sidebar
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }


        RendererComponent {
            Layout.margins: 20
            
            id: engine

            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.minimumWidth: 700
            Layout.preferredWidth: 700
            Layout.maximumWidth: 1920
            
            Layout.minimumHeight: 700
            Layout.preferredHeight: 700
            Layout.maximumHeight: 1920
        }

        Rectangle {
            id: rect
            color: "#FFFFFF"

            Layout.alignment: Qt.AlignRight | Qt.AlignTop

            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.minimumWidth: 200
            Layout.preferredWidth: 200
            Layout.maximumWidth: 250
            
            Layout.minimumHeight: 150
            Layout.preferredHeight: 700
            Layout.maximumHeight: 1000
        }

    }
}
