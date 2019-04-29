import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  title: qsTr("Wireframe Material")
  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    // spacing: 10

  //   CustomText {
  //     color: Style.likeWhite
  //     text: "Diffuse: " + PhongMaterialModel.diffuse
  //     Layout.leftMargin: 5
  //     MouseArea {
  //       anchors.fill: parent
  //         onClicked: {
  //           diffuseColorDialog.open() 
  //       }
  //     }
  //     ColorDialog {
  //       id: diffuseColorDialog
  //       title: "Please choose a color"
  //       onAccepted: {
  //         PhongMaterialModel.setDiffuse(color)
  //       }
  //     }
  //   }
  //   CustomText {
  //     color: Style.likeWhite
  //     text: "Specular: " + PhongMaterialModel.specular
  //     Layout.leftMargin: 5
  //     MouseArea {
  //       anchors.fill: parent
  //         onClicked: {
  //           specularColorPicker.open() 
  //       }
  //     }
  //     ColorDialog {
  //       id: specularColorPicker
  //       title: "Please choose a color"
  //       onAccepted: {
  //         PhongMaterialModel.setSpecular(color)
  //       }
  //     }
  //   }
  //   CustomText {
  //     color: Style.likeWhite
  //     text: "Ambient: " + PhongMaterialModel.ambient
  //     Layout.leftMargin: 5
  //     MouseArea {
  //       anchors.fill: parent
  //         onClicked: {
  //           ambientColorDialog.open() 
  //       }
  //     }
  //     ColorDialog {
  //       id: ambientColorDialog
  //       title: "Please choose a color"
  //       onAccepted: {
  //         PhongMaterialModel.setAmbient(color)
  //       }
  //     }
  //   }
  // }
}
