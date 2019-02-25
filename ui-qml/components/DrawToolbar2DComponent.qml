import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0

UiMainBorder {
  ColumnLayout {
    id: column
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.topMargin: 10
    spacing: 10

    Button {
      Layout.topMargin: 10
      Layout.alignment: Qt.AlignHCenter
      text: "Rectangle"
      onClicked: mainController.drawToolbar2DController.createSphere()
    }

    Button {
      Layout.alignment: Qt.AlignHCenter
      text: "Not bind"
    }
  }
}