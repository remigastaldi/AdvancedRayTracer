import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("ZIndex")
    RowLayout {
      anchors.fill: parent
      Layout.fillWidth: true
      Layout.fillHeight: true
    
      CustomText {
        color: Style.likeWhite
        text: "zIndex: "
        Layout.leftMargin: 5
      }

// Connections {
    // target: qmlNote
    // onNoteChanged: console.info(qmlNote.title)
// }
      CustomIntInput {
        id: inpuText
        text: ZIndexModel.zIndex

        onEditingFinished: {
          ZIndexModel.setIndex(parseInt(text))
        }
      }
    }
  }        
// }
