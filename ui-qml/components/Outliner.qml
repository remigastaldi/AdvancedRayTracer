import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0

ScrollView {
  ListView {
    id: listview
    model: qmlOutliner
    anchors.fill: parent

    delegate: Rectangle {
      id: wrapper
      anchors.left: parent.left
      anchors.right: parent.right
      height: 20

      // color: ListView.isCurrentItem ? "#2F343F" : Style.mainContainerColor
      color : lineColor

      Text {
        text: id
        anchors.verticalCenter: wrapper.verticalCenter
        color: wrapper.ListView.isCurrentItem ? Style.mainColor : "white"
        font.pointSize: 12
      }

      MouseArea {
        anchors.fill: parent
        onClicked:  {
          wrapper.ListView.view.currentIndex = index
          listview.focus = true
        }
      }
    }
  }
}