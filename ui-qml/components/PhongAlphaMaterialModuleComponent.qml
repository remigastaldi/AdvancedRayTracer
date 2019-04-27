import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  title: qsTr("Metal Rough Material")
  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    // spacing: 10

    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Alpha: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: PhongAlphaMaterialModel.alpha

        onEditingFinished: {
          PhongAlphaMaterialModel.setAlpha(parseFloat(text))
        }
      }
    }

    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Shininess: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: PhongAlphaMaterialModel.shininess

        onEditingFinished: {
          PhongAlphaMaterialModel.setShininess(parseFloat(text))
        }
      }
    }
    CustomText {
      color: Style.likeWhite
      text: "Diffuse: " + PhongAlphaMaterialModel.diffuse
      Layout.leftMargin: 5
      MouseArea {
        anchors.fill: parent
          onClicked: {
            diffuseColorDialog.open() 
        }
      }
      ColorDialog {
        id: diffuseColorDialog
        title: "Please choose a color"
        onAccepted: {
          PhongAlphaMaterialModel.setDiffuse(color)
        }
      }
    }
    CustomText {
      color: Style.likeWhite
      text: "Specular: " + PhongAlphaMaterialModel.specular
      Layout.leftMargin: 5
      MouseArea {
        anchors.fill: parent
          onClicked: {
            specularColorPicker.open() 
        }
      }
      ColorDialog {
        id: specularColorPicker
        title: "Please choose a color"
        onAccepted: {
          PhongAlphaMaterialModel.setSpecular(color)
        }
      }
    }
    CustomText {
      color: Style.likeWhite
      text: "Ambient: " + PhongAlphaMaterialModel.ambient
      Layout.leftMargin: 5
      MouseArea {
        anchors.fill: parent
          onClicked: {
            ambientColorDialog.open() 
        }
      }
      ColorDialog {
        id: ambientColorDialog
        title: "Please choose a color"
        onAccepted: {
          PhongAlphaMaterialModel.setAmbient(color)
        }
      }
    }
  }
}
