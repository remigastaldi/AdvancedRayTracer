import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.0
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
                text: qsTr("Import image")
				onTriggered: importImgDialog.open()
			}
            MenuItem {
                text: qsTr("&Save")
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

	FileDialog {
		id: importImgDialog
		title: "Please choose a file"
		folder: shortcuts.home
		nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
		onAccepted: {
			// User choice : importImgDialog.fileUrls
			Qt.quit()
		}
		onRejected: {
			Qt.quit()
		}
	}

    header: ToolbarComponent {
        id: menu
    }

    RowLayout {
        id: appContent

        anchors.fill: parent

        LeftSidebarComponent {
            id: leftSidebar
            Layout.margins: 10
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }

        FbItemComponent {            
            id: engine
            Layout.margins: 8

            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.minimumWidth: 700
            Layout.preferredWidth: 700
            Layout.maximumWidth: 1920
            
            Layout.minimumHeight: 700
            Layout.preferredHeight: 700
            Layout.maximumHeight: 1920
        }

        RightSidebarComponent {
            id: rightSidebar
            Layout.margins: 10
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }
    }
}
