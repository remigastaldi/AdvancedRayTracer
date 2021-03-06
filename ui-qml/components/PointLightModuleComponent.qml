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
      text: "Color: " + PointLightModel.color
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
          PointLightModel.setColor(color)
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
        text: PointLightModel.intensity

        onEditingFinished: {
          PointLightModel.setIntensity(parseFloat(text))
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Constant Attenation: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: PointLightModel.constantAttenuation

        onEditingFinished: {
          PointLightModel.setConstantAttenuation(parseFloat(text))
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Linear Attenuation: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: PointLightModel.linearAttenuation

        onEditingFinished: {
          PointLightModel.setLinearAttenuation(parseFloat(text))
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Quadratic Attenuation: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: PointLightModel.quadraticAttenuation

        onEditingFinished: {
          PointLightModel.setQuadraticAttenuation(parseFloat(text))
        }
      }
    }
  }
}
