import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    // spacing: 10

    CustomText {
      color: Style.likeWhite
      text: "Metalness"
      Layout.bottomMargin: 5
    }
    Slider {  
      Layout.maximumWidth: parent.width
      from: 0
      value: MaterialModel.metalness()
      to: 1
      onMoved: {
        MaterialModel.setMetalness(value)
      }
    }
    CustomText {
      color: Style.likeWhite
      text: "Roughness"
      Layout.bottomMargin: 5
    }

    Slider {
      Layout.maximumWidth: parent.width
      from: 0
      value: MaterialModel.roughness()
      to: 1
      onMoved: {
        MaterialModel.setRoughness(value)
      }
    }

    CustomText {
      color: Style.likeWhite
      text: "Color: " + MaterialModel.baseColor()
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
          MaterialModel.setBaseColor(color)
        }
      }
    }

    CustomButton {
      Layout.alignment: Qt.AlignHCenter
      text: "Set BaseColor Texture"
      onClicked: baseColorDialog.open()
    }

    CustomButton {
      Layout.alignment: Qt.AlignHCenter
      text: "Set Metalness Texture"
      onClicked: metalnessDialog.open()
    }

    CustomButton {
      Layout.alignment: Qt.AlignHCenter
      text: "Set Roughness Texture"
      onClicked: roughnessDialog.open()
    }

    CustomButton {
      Layout.alignment: Qt.AlignHCenter
      text: "Set Normal Texture"
      onClicked: normalDialog.open()
    }

    CustomButton {
      Layout.alignment: Qt.AlignHCenter
      text: "Set AmbientOcclusion Texture"
      onClicked: ambientOcclusionDialog.open()
    }
  }
  FileDialog {
    id: baseColorDialog
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MaterialModel.setBaseColor(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: metalnessDialog
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MaterialModel.setMetalnessTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: roughnessDialog
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MaterialModel.setRoughnessTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: normalDialog
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MaterialModel.setNormalTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: ambientOcclusionDialog
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MaterialModel.setAmbientOcclusionTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }
}
