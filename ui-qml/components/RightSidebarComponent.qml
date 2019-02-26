import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0

UiMainBorder {
  id: root

  // Layout.fillWidth: true
  // Layout.fillHeight: true

  // Layout.minimumWidth: 250
  // Layout.preferredWidth: 250
  // Layout.maximumWidth: 300

  // Layout.maximumHeight: column.implicitHeight

  GroupBox {
    title: qsTr("Outliner")
      anchors.top: root.top
      anchors.left: root.left
      anchors.right: root.right
      anchors.margins: 10
      height: 200
      Outliner {
        anchors.fill: parent
      }
  }
 
  ColumnLayout {
    id: column
    anchors.fill: parent
    spacing: 10

    Button {
      Layout.topMargin: 10
      Layout.alignment: Qt.AlignHCenter
      text: "Nothin"
      onClicked: outliner.add()
    }

    // Button {
    //   Layout.alignment: Qt.AlignHCenter
    //   text: "Add cube"
    //   onClicked: mainController.rightSidebarController.createCube();
    // }

    // Button {
    //   Layout.alignment: Qt.AlignHCenter
    //   text: "Delete cube"
    //   onClicked: mainController.rightSidebarController .deleteShape()
    // }

    // RowLayout {
    //   Layout.bottomMargin: 10
    //   Layout.leftMargin: 10
    //   spacing: 10

    //   Text {
    //     text: "Render per second"
    //   }
    //   TextInput {
    //     Layout.preferredWidth: 70
    //     Layout.alignment: Qt.AlignHCenter
    //     text: "0"
    //     renderType: TextInput.NativeRendering
    //     validator: IntValidator{bottom: 0; top: 2000000;}
    //     onTextEdited: mainController.rightSidebarController.setAutoRenderRate(parseInt(text))
    //   }
    // }
  }
}