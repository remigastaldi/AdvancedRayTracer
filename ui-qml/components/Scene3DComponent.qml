import AdvancedRayTracer 1.0

import Qt3D.Render 2.12
import Qt3D.Extras 2.12
import Qt3D.Core 2.12
import QtQuick.Scene3D 2.12
import Qt3D.Render 2.12
import Qt3D.Input 2.12
import QtQuick 2.12

Scene3D {
  id: scene3D
  hoverEnabled: true
  aspects: ["input", "logic"]
  cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

  RootEntity {
    id: sceneRoot
    objectName: "rootEntity"

    components: [
      RenderSettings {
        activeFrameGraph: ForwardRenderer {
        clearColor: Qt.rgba(0, 0, 0, 0)
        camera: mainCamera
        }
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
        // sceneRoot.cameraMoveEvent(mainCamera.position)
        sceneRoot.keyPressedEvent(event.key)
      }
    }

    MouseDevice {
      id:mouse
    }
    
    MouseHandler {
      sourceDevice: mouse
      onPressed: scene3D.focus = true
    }

    Camera {
      id: mainCamera
      projectionType: CameraLens.PerspectiveProjection
      fieldOfView: 60
      nearPlane : 0.1
      farPlane : 1000.0
      position: CameraModel.position;
      // upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
      viewCenter: Qt.vector3d( 0.0, 0.0, 1000.0 )
    }
    
    FirstPersonCameraController {
      camera: mainCamera 
      linearSpeed: 50
      lookSpeed: 100
    }
  }
}
