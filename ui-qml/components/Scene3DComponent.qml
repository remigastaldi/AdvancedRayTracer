import AdvancedRayTracer 1.0

import Qt3D.Render 2.12
import Qt3D.Extras 2.12
import Qt3D.Core 2.12
import QtQuick.Scene3D 2.12
import Qt3D.Render 2.12

Scene3D {
    id: scene3d
    focus: true
    enabled: true
    cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

    Entity {
        id: sceneRoot

        Camera {
            id: mainCamera
            projectionType: CameraLens.PerspectiveProjection
            fieldOfView: 45
            nearPlane : 0.1
            farPlane : 1000.0
            position: Qt.vector3d( 0.0, -20.0, 10.0 )
            upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
            viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
        }

        components: [
            RenderSettings {
                activeFrameGraph: ForwardRenderer {
                    clearColor: Qt.rgba(0, 0, 0, 0)
                    camera: mainCamera
                }
            }
        ]

      CustomScene3D {
          objectName: "customScene3D"
      }
    }
}
