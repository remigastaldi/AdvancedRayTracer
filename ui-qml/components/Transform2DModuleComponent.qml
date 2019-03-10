import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("Transform2D")
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
        text: "x: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform2DModel.x

        onEditingFinished: {
          Transform2DModel.setX(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
      CustomText {
        text: "y: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform2DModel.y

        onEditingFinished: {
          Transform2DModel.setY(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
    }
    RowLayout {
      Layout.fillWidth: true
      Layout.fillHeight: true
      // spacing: 4
    
      CustomText {
        text: "width: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform2DModel.width

        onEditingFinished: {
          Transform2DModel.setWidth(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }

      CustomText {
        text: "height: "
        Layout.leftMargin: 5
      }    
      CustomDoubleInput {
        text: Transform2DModel.height

        onEditingFinished: {
          Transform2DModel.setHeight(parseFloat(text))
          mainController.updateCurrentScene();
        }    
      }
	}
	RowLayout {
	  CustomText {
        text: "angle: "
        Layout.leftMargin: 5
      }    
      CustomDoubleInput {
        text: Transform2DModel.angle

        onEditingFinished: {
          Transform2DModel.setAngle(parseInt(text))
          mainController.updateCurrentScene();
        }    
      }
    }
  }        
}
