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
      }
      MultiViewCamera {
        id: multiViewCamera
        enabled: false
      }
      
      components: [
        // RenderSettings {
        //   activeFrameGraph: ForwardRenderer {
        //     clearColor: Qt.rgba(0, 0, 0, 0)
        //     camera: camera1
        //     frustumCulling: false
        //   }
        // },
        RenderSettings {
          id: renderSettings
          activeFrameGraph: singleViewCamera
            // Loader {
              // sourceComponent: multiViewCamera
              // source: "MultiViewCamera.qml"

            // }

          // }
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
          console.log(mouse.x)
          console.log(mouse.y)
        }
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
        renderSettings.activeFrameGraph = multiViewCamera
      } else {
        singleViewCamera.enabled = false
        multiViewCamera.enabled = true
        renderSettings.activeFrameGraph = singleViewCamera
      }
    }
  }
}