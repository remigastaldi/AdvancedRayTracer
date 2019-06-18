import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("Transform3D")

  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true

    RowLayout {
      // title: qsTr("Position")
      Layout.fillWidth: true
      Layout.fillHeight: true
      // spacing: 4

      CustomText {
        color: Style.likeWhite
        text: "x: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform3DModel.x

        onEditingFinished: {
          Transform3DModel.setX(parseFloat(text))
        }
      }
      
      CustomText {
        text: "y: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform3DModel.y

        onEditingFinished: {
          Transform3DModel.setY(parseFloat(text))
        }    
      }
    
      CustomText {
        text: "z: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform3DModel.z

        onEditingFinished: {
          Transform3DModel.setZ(parseFloat(text))
        }    
      }
    }
    CustomText {
      text: "Rotation: "
      Layout.leftMargin: 5
    }
    RowLayout {
      // title: qsTr("Rotation")
      Layout.fillWidth: true
      Layout.fillHeight: true
      // spacing: 4

      CustomText {
        color: Style.likeWhite
        text: "x: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform3DModel.rotationX

        onEditingFinished: {
          Transform3DModel.setRotationX(parseFloat(text))
        }
      }
      
      CustomText {
        text: "y: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform3DModel.rotationY

        onEditingFinished: {
          Transform3DModel.setRotationY(parseFloat(text))
        }    
      }
    
      CustomText {
        text: "z: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: Transform3DModel.rotationZ

        onEditingFinished: {
          Transform3DModel.setRotationZ(parseFloat(text))
        }    
      }
    }
  }        
}
