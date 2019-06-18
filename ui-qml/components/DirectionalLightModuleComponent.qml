import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  title: qsTr("Spot")
  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    // spacing: 10

    CustomText {
      color: Style.likeWhite
      text: "Color: " + DirectionalLightModel.color
      Layout.leftMargin: 5
      MouseArea {
        anchors.fill: parent
          onClicked: {
            spotLightColor.open() 
        }
      }
      ColorDialog {
        id: spotLightColor
        title: "Please choose a color"
        onAccepted: {
          DirectionalLightModel.setColor(color)
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Intensity: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: DirectionalLightModel.intensity

        onEditingFinished: {
          DirectionalLightModel.setIntensity(parseFloat(text))
        }
      }
    }
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
        text: DirectionalLightModel.worldDirection.x

        onEditingFinished: {
          DirectionalLightModel.setWorldDirectionX(parseFloat(text))
        }
      }
      
      CustomText {
        text: "y: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: DirectionalLightModel.worldDirection.y

        onEditingFinished: {
          DirectionalLightModel.setWorldDirectionY(parseFloat(text))
        }    
      }
    
      CustomText {
        text: "z: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: DirectionalLightModel.worldDirection.z

        onEditingFinished: {
          DirectionalLightModel.setWorldDirectionZ(parseFloat(text))
        }    
      }
    }
  }
}
