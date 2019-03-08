import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ColumnLayout {
  GroupBox {
    Layout.fillWidth: true
    Layout.fillHeight: true

    RowLayout {
      anchors.fill: parent.fill
      Layout.fillWidth: true
      Layout.fillHeight: true
    
      Text {
        color: Style.likeWhite
        text: "x: "
        Layout.leftMargin: 5
      }
    
      CustomDoubleInput {
        text: TransformModel.x()

        onEditingFinished: {
          TransformModel.setX(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
  
      Text {
        text: "y: "
        Layout.leftMargin: 5
      }
    
      CustomDoubleInput {
        text: TransformModel.y()

        onEditingFinished: {
          TransformModel.setY(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
    }
    RowLayout {
      anchors.fill: parent.fill
      Layout.fillWidth: true
      Layout.fillHeight: true
    
      Text {
        text: "width: "
        Layout.leftMargin: 5
      }
    
      CustomDoubleInput {
        text: TransformModel.width()

        onEditingFinished: {
          TransformModel.setWidth(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
      Text {
        text: "height: "
        Layout.leftMargin: 5
      }
    
      CustomDoubleInput {
        text: TransformModel.height()

        onEditingFinished: {
          TransformModel.setHeight(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
    }
  }        
}
