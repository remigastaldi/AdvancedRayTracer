import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0
import "../styles"

Rectangle {
  id: root

  Layout.fillWidth: true
  Layout.fillHeight: true

  Layout.minimumWidth: 200
  Layout.preferredWidth: 200
  Layout.maximumWidth: 250

  Layout.maximumHeight: column.implicitHeight

  color: "transparent"

  border.color: Style.mainColor
  border.width: 1

  radius: 5

  ColumnLayout {
    id: column
    anchors.fill: parent
    spacing: 10

    Button {
      Layout.topMargin: 10
      Layout.alignment: Qt.AlignHCenter
      text: "Render"
      onClicked: mainController.rightSidebarController.render()
    }

    Button {
      Layout.bottomMargin: 10
      Layout.alignment: Qt.AlignHCenter
      text: "Do nothing"
    }
  }
}