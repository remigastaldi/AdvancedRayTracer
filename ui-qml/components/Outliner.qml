import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0

ScrollView {
  clip: true
  ListView {
    id: listView
    model: qmlOutliner
    anchors.fill: parent
    anchors.topMargin: 8
    // anchors.bottomMargin: 10

    delegate: Rectangle {
      id: wrapper
      anchors.right: parent.right
      anchors.left: parent.left
      height: 20

      color : lineColor

      Text {
        text: id
        anchors.verticalCenter: wrapper.verticalCenter
        color: wrapper.ListView.isCurrentItem ? Style.mainColor : Style.likeWhite
        font.pointSize: 10
      }

      MouseArea {
        anchors.fill: parent
        onClicked: {
          mainController.selectEntityByIndex(index)
          listView.currentIndex = index
          listView.focus = true
          
        }
      }
    }
    Component.onCompleted: {
      qmlOutliner.selectionIndexChanged.connect(selectionIndexChanged);
      function selectionIndexChanged() {
        listView.currentIndex = qmlOutliner.selectionIndex()
      }
    }
  }
}