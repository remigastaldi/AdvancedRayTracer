import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  title: qsTr("Brush")
  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    // spacing: 10

    RowLayout {
      Layout.fillWidth: true
      Layout.fillHeight: true
      // spacing: 4

      CustomText {
        color: Style.likeWhite
        text: "Brush: "
        Layout.leftMargin: 5
      }
      CustomText {
        color: Style.likeWhite
        text: BrushModel.color
        Layout.leftMargin: 5
        MouseArea {
          anchors.fill: parent
            onClicked: {
              colorDialog.open()
              // colorDialog.visible = true
            }
          }
        ColorDialog {
          id: colorDialog
          title: "Please choose a color"
          onAccepted: {
            BrushModel.setColor(color)
            // console.log("You chose: " + colorDialog.color)
          }
          // Component.onCompleted: visible = true
        }
    //   CustomText {
    //     text: "y: "
    //     Layout.leftMargin: 5
    //   }
    //   CustomDoubleInput {
    //     text: BrushModel.y

    //     onEditingFinished: {
    //       BrushModel.setY(parseFloat(text))
    //       mainController.updateCurrentScene();
    //     }    
    //   }
    // }
    // RowLayout {
    //   Layout.fillWidth: true
    //   Layout.fillHeight: true
    //   // spacing: 4
    
    //   CustomText {
    //     text: "width: "
    //     Layout.leftMargin: 5
    //   }
    //   CustomDoubleInput {
    //     text: BrushModel.width

    //     onEditingFinished: {
    //       BrushModel.setWidth(parseFloat(text))
    //       mainController.updateCurrentScene();
    //     }    
    //   }

    //   CustomText {
    //     text: "height: "
    //     Layout.leftMargin: 5
    //   }    
    //   CustomDoubleInput {
    //     text: BrushModel.height

    //     onEditingFinished: {
    //       BrushModel.setHeight(parseFloat(text))
    //       mainController.updateCurrentScene();
    //     }    
    //   }
      }
    }
  }
}
