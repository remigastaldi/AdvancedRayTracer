import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0

UiMainBorder {
  GroupBox {
    title: qsTr("Mesh")
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.top: parent.top
    anchors.margins: 10

    ColumnLayout {
      id: column
      anchors.fill: parent
      spacing: 10

      Button {
        Layout.alignment: Qt.AlignHCenter
        text: "Sphere"
        onClicked: mainController.drawToolbar3DController.createSphere()
      }

      Button {
        Layout.alignment: Qt.AlignHCenter
        text: "Not bind"
      }

      Button {
        Layout.alignment: Qt.AlignHCenter
        text: "Not bind"
      }
    }
  }
}