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

    CustomText {
      color: Style.likeWhite
      text: "Metalness"
      Layout.bottomMargin: 5
    }
    Slider {  
      Layout.maximumWidth: parent.width
      from: 0
      value: MetalRoughMaterialModel.metalness()
      to: 1
      onMoved: {
        MetalRoughMaterialModel.setMetalness(value)
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
      value: MetalRoughMaterialModel.roughness()
      to: 1
      onMoved: {
        MetalRoughMaterialModel.setRoughness(value)
      }
    }

    CustomText {
      color: Style.likeWhite
      text: "Color: " + MetalRoughMaterialModel.baseColor()
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
          MetalRoughMaterialModel.setBaseColor(color)
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
    folder: shortcuts.desktop
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MetalRoughMaterialModel.setBaseColor(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: metalnessDialog
    folder: shortcuts.desktop
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MetalRoughMaterialModel.setMetalnessTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: roughnessDialog
    folder: shortcuts.desktop
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MetalRoughMaterialModel.setRoughnessTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: normalDialog
    folder: shortcuts.desktop
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MetalRoughMaterialModel.setNormalTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }

  FileDialog {
    id: ambientOcclusionDialog
    folder: shortcuts.desktop
    title: "Please choose an image"
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
    onAccepted: {
      MetalRoughMaterialModel.setAmbientOcclusionTexture(fileUrl)
      mainController.updateCurrentScene()
    }
  }
}
