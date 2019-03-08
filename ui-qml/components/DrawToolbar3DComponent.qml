import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

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

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Sphere"
        onClicked: mainController.drawToolbar3DController.createSphere()
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Not bind"
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Not bind"
      }
    }
  }
}