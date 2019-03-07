import "../components"
import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.0
import QtQuick.Controls 2.12
import QtQml 2.12

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
    title: "Please choose an image"
    folder: shortcuts.home
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      mainController.toolbarController.importImageClicked(importImgDialog.fileUrl);
    }
  }

  header: ToolbarComponent {
    id: menu
  }

  
  RowLayout {
    id: appContent

    anchors.fill: parent

    StackLayout {
      currentIndex: tabBar.currentIndex
      Layout.fillWidth: true
      Layout.fillHeight: true

      Layout.minimumWidth: 150
      Layout.preferredWidth: 150
      Layout.maximumWidth: 200

      Layout.minimumHeight: 150
      Layout.preferredHeight: 700
      Layout.maximumHeight: 1000

      Layout.margins: 10
    
      DrawToolbar3DComponent {}
      DrawToolbar2DComponent {}
    }

    ColumnLayout {
      Layout.fillWidth: true
      Layout.fillHeight: true

      Layout.minimumWidth: 700
      Layout.preferredWidth: 700
      Layout.maximumWidth: 1920

      Layout.minimumHeight: 700
      Layout.preferredHeight: 700
      Layout.maximumHeight: 1920

      Layout.margins: 10

      TabBar {
        id: tabBar
        TabButton {
          text: qsTr("3D")
          onPressed: checked != true ? mainController.scene3DSelected() : 0
        }
        TabButton {
          text: qsTr("2D")
          onPressed: checked != true ? mainController.scene2DSelected() : 0
        }
      }

      StackLayout {
        id: stackView
        currentIndex: tabBar.currentIndex
        Scene3DComponent {}
        Scene2DComponent {}
      }
    }

    RightSidebarComponent {
      id: rightSidebar
      Layout.margins: 10
      // Layout.alignment: Qt.AlignLeft | Qt.AlignTop
      Layout.fillWidth: true
      Layout.fillHeight: true

      Layout.minimumWidth: 250
      Layout.preferredWidth: 250
      Layout.maximumWidth: 300

      Layout.minimumHeight: 150
      Layout.preferredHeight: 700
      Layout.maximumHeight: 1000
    }
  }
}
