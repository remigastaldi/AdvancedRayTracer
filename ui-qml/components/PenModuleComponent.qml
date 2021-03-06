import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  title: qsTr("Pen")
  // ColumnLayout {
  //   Layout.fillWidth: true
  //   Layout.fillHeight: true
    // spacing: 10

  RowLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    // spacing: 4

    CustomText {
      text: "Pen: "
      Layout.leftMargin: 5
    }
    CustomText {
      text: PenModel.color
      Layout.leftMargin: 5
      MouseArea {
        anchors.fill: parent
          onClicked: {
            colorDialog.open()
          }
        }
      ColorDialog {
        id: colorDialog
        title: "Please choose a color"
        onAccepted: {
          PenModel.setColor(color)
        }
      }
    }
    CustomText {
      text: "Width: "
      Layout.leftMargin: 5
    }
    CustomDoubleInput {
      text: PenModel.width()

      onEditingFinished: {
        PenModel.setWidth(parseFloat(text))
        mainController.updateCurrentScene();
      }    
    }
  }
}
