import AdvancedRayTracer 1.0
import "../styles"

import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

UiMainBorder {
  GroupBox {
    font.pointSize: 10
    title: qsTr("3D Tools")
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.top: parent.top
    anchors.margins: 5

    ColumnLayout {
      id: column
      anchors.fill: parent
      spacing: 10

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Sphere"
        onClicked: mainController.drawToolbar3DController.createSphere()
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Cube"
        onClicked: mainController.drawToolbar3DController.createCube()
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Torus"
        onClicked: mainController.drawToolbar3DController.createTorus()
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Plane"
        onClicked: mainController.drawToolbar3DController.createPlane()
      }

	    CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Ray intersection"
        onClicked: mainController.drawToolbar3DController.castRay()
      }

	  CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Ray reflection"
        onClicked: mainController.drawToolbar3DController.raytracingReflection()
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Light"
        onClicked: mainController.drawToolbar3DController.createLight()
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Import 3D Model"
        onClicked: open3dModelFileDialog.open()
      }

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Import 3D Scene"
        onClicked: open3dSceneFileDialog.open()
      }
    }
  }

  FileDialog {
    id: open3dModelFileDialog
    title: "Choose your 3D Model file"
    nameFilters: ["3D Model files (*.obj *.fbx *.stl *.ply)"]
    onAccepted: {
      mainController.drawToolbar3DController.import3DModel(fileUrl)
    }
  }

  FileDialog {
    id: open3dSceneFileDialog
    title: "Choose your 3D Scene file"
    nameFilters: ["3D Scene files (*.obj *.3ds *.dae *.md5)", "All Files (*)"]
    onAccepted: {
      mainController.drawToolbar3DController.import3DScene(fileUrl)
    }
  }
}

