import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("TorusMesh")

  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true

    RowLayout {
      Layout.fillWidth: true
      Layout.fillHeight: true
      // spacing: 4

      CustomText {
        color: Style.likeWhite
        text: "x: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: TorusMeshModel.x

        onEditingFinished: {
          TorusMeshModel.setX(parseFloat(text))
          mainController.updateCurrentScene();
        }
      }
      CustomText {
        text: "y: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: TorusMeshModel.y

        onEditingFinished: {
          TorusMeshModel.setY(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
    
      CustomText {
        text: "z: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: TorusMeshModel.z

        onEditingFinished: {
          TorusMeshModel.setZ(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
    }
  }        
}
