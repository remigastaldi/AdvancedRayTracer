import AdvancedRayTracer 1.0

import Qt3D.Render 2.12
import Qt3D.Input 2.12
import Qt3D.Extras 2.12
import Qt3D.Core 2.12
import QtQuick 2.12
import QtQuick.Scene3D 2.12

RenderSurfaceSelector {
  signal pressed(int posx, int posy);

  onPressed: (posx, posy) => {
    if (posx < width / 2) {
      if (posy < height / 2) {
        firstPersonCameraController.camera = camera1
      } else {
        firstPersonCameraController.camera = camera3
      }
    } else {
      if (posy < height / 2) {
        firstPersonCameraController.camera = camera2
      } else {
        firstPersonCameraController.camera = camera4
      }
    }
  }

  Viewport {
    id: mainViewport
    normalizedRect: Qt.rect(0.0, 0, 1, 1)

    ClearBuffers {
      buffers: ClearBuffers.ColorDepthBuffer
      clearColor: "black"
      NoDraw {}
    }

    Viewport {
      normalizedRect: Qt.rect(0, 0, 0.5, 0.5)
      CameraSelector { camera: camera1 }
    }

    Viewport {
      normalizedRect: Qt.rect(0.5, 0, 0.5, 0.5)
      CameraSelector { camera: camera2 }
    }

    Viewport {
      normalizedRect: Qt.rect(0, 0.5, 0.5, 0.5)
      CameraSelector { camera: camera3 }
    }

    Viewport {
      normalizedRect: Qt.rect(0.5, 0.5, 0.5, 0.5)
      CameraSelector { camera: camera4 }
    }
  }

  Camera {
    id: camera1
    projectionType: CameraLens.PerspectiveProjection
    fieldOfView: 60
    nearPlane : 0.1
    farPlane : 1000.0
    aspectRatio: scene3D.width / scene3D.height
    position: Qt.vector3d(-10.0, 0.0, 10.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
  }

  Camera {
    id: camera2
    projectionType: CameraLens.FrustumProjection
    fieldOfView: 60
    nearPlane : 0.1
    farPlane : 1000.0
    aspectRatio: scene3D.width / scene3D.height

    position: Qt.vector3d(10.0, 0.0, 10.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
  }
  
  Camera {
    id: camera3
    projectionType: CameraLens.OrthographicProjection
    fieldOfView: 60
    nearPlane : 0.1
    farPlane : 1000.0
    aspectRatio: scene3D.width / scene3D.height

    position: Qt.vector3d(0.0, -10.0, 10.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
  }

  Camera {
    id: camera4
    projectionType: CameraLens.PerspectiveProjection
    fieldOfView: 60
    nearPlane : 0.1
    farPlane : 1000.0
    aspectRatio: scene3D.width / scene3D.height

    position: Qt.vector3d(0.0, 40.0, 1.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
  }
  
  FirstPersonCameraController {
    id: firstPersonCameraController
    camera: camera1
    linearSpeed: 50
    // linearSpeed: 300
    lookSpeed: 100
    // lookSpeed: 3000
  }
}

