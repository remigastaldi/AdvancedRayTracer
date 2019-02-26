import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0

ScrollView {
  ListView {
    id: listview
    model: outliner
    anchors.fill: parent

    delegate: Rectangle {
      id: wrapper
      anchors.left: parent.left
      anchors.right: parent.right
      height: 25

      color: ListView.isCurrentItem ? "black" : "red"

      Text {
        text: entityType
        color: wrapper.ListView.isCurrentItem ? "red" : "black"
        font.pointSize: 12
      }

      MouseArea {
        anchors.fill: parent
        onClicked:  {
          listview.focus = true
          wrapper.ListView.view.currentIndex = index
        }
      }
    }
  }
}