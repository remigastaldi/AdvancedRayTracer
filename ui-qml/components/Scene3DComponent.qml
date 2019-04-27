import AdvancedRayTracer 1.0
import "../styles"

import Qt3D.Render 2.12
import Qt3D.Input 2.12
import Qt3D.Extras 2.12
import Qt3D.Core 2.12
import QtQuick 2.12
import QtQuick.Scene2D 2.12
import QtQuick.Scene3D 2.12
import QtQuick.Controls 2.12

Item {
  id: root
  property alias currentRender: renderSettings.activeFrameGraph

  Scene3D {
    id: scene3D
    anchors.fill: parent
    hoverEnabled: true
    aspects: ["render", "input", "logic"]

    entity: RootEntity {
      id: sceneRoot
      objectName: "rootEntity"

      SingleViewCamera {
        id: singleViewCamera
        enabled: true
        onCameraChanged: (newCamera) => {
          cameraController.camera = newCamera
          projectionControl.currentIndex = newCamera.projectionType
        }
      }
      MultiViewCamera {
        id: multiViewCamera
        enabled: false
        onCameraChanged: (newCamera) => {
          cameraController.camera = newCamera
          projectionControl.currentIndex = newCamera.projectionType
        }
      }
      Loader {
        id: loader
      }
      
      components: [
        RenderSettings {
          id: renderSettings
          activeFrameGraph: singleViewCamera
          pickingSettings.pickMethod: PickingSettings.TrianglePicking
        },
        InputSettings { }
      ]

      KeyboardDevice {
        id: keyboardDevice
      }

      KeyboardHandler {
        sourceDevice : keyboardDevice
        focus: true
        onPressed : {
          // sceneRoot.cameraMoveEvent(camera1.position)
          sceneRoot.keyPressedEvent(event.key)
        }
      }

      MouseDevice {
        id:mouse
      }

      MouseHandler {
        sourceDevice: mouse
        onPressed: {
          scene3D.focus = true
          currentRender.pressed(mouse.x, mouse.y)
        }
      }

      FirstPersonCameraController {
        id: cameraController
        // camera: singleViewCamera.currentcamera
        linearSpeed: 50
        // linearSpeed: 300
        lookSpeed: 100
        // lookSpeed: 3000
      }

      SkyboxEntity {
        baseName: "qrc:/skybox/output_skybox"
        extension: ".dds"
        // gammaCorrect: true
        // Transform {
        //   translation: camera1.position
        // }
      }
    }
  }

  Switch {
    anchors.right: root.right
    onClicked: {
      if (checked) {
        singleViewCamera.enabled = false
        multiViewCamera.enabled = true
        currentRender = multiViewCamera
        currentRender.pressed(0,0);
      } else {
        multiViewCamera.enabled = false
        singleViewCamera.enabled =  true
        currentRender = singleViewCamera
        currentRender.pressed(0,0);
      }
    }
  }

  ComboBox {
    id: projectionControl
    width: 100
    height:25
    font.pointSize: 10
    model: [ "Orthographic", "Perspective", "Frustum" ]

    delegate: ItemDelegate {
      width: projectionControl.width
      height: projectionControl.height
      contentItem: Text {
          text: modelData
          color: Style.likeWhite
          font: projectionControl.font
          elide: Text.ElideRight
          verticalAlignment: Text.AlignVCenter
      }
      highlighted: projectionControl.highlightedIndex === index
    }

    popup: Popup {
      y: projectionControl.height - 1
      width: projectionControl.width
      implicitHeight: contentItem.implicitHeight
      padding: 1

      contentItem: ListView {
          clip: true
          implicitHeight: contentHeight
          model: projectionControl.popup.visible ? projectionControl.delegateModel : null
          currentIndex: projectionControl.highlightedIndex

          ScrollIndicator.vertical: ScrollIndicator { }
      }

      background: Rectangle {
          border.color: Style.likeWhite
          border.width: 2
          color: "black"
          opacity: 0.5
      }
    }

    onActivated: (index) => {
      switch (index) {
        case 0:
          currentRender.currentCamera.projectionType = CameraLens.OrthographicProjection
          break;
        case 1:
          currentRender.currentCamera.projectionType = CameraLens.PerspectiveProjection
          break;
        case 2:
          currentRender.currentCamera.projectionType = CameraLens.FrustumProjection
          break;
      }
    }
    Component.onCompleted: {
      currentIndex = singleViewCamera.camera.projectionType
    }
  }
}