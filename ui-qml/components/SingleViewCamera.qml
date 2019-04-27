import AdvancedRayTracer 1.0

import Qt3D.Render 2.12
import Qt3D.Extras 2.12
import Qt3D.Core 2.12
import QtQuick.Scene3D 2.12
import Qt3D.Render 2.12
import Qt3D.Input 2.12
import QtQuick 2.12

ForwardRenderer {
  clearColor: Qt.rgba(0, 0, 0, 0)
  camera: camera1
  frustumCulling: false

  property var currentCamera
  signal cameraChanged(Camera newCamera);
  
  Camera {
    id: camera1
    projectionType: projection
    fieldOfView: 60
    nearPlane : 0.1
    farPlane : 1000.0
    aspectRatio: scene3D.width / scene3D.height
    position: Qt.vector3d(-10.0, 0.0, 10.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
  Component.onCompleted: {
    currentCamera = camera1
    cameraChanged(camera1)
    // console.log("COMPLEDED")
  }
  }

  FirstPersonCameraController {
    id: firstPersonCameraController
    camera: currentCamera
    linearSpeed: 50
    // linearSpeed: 300
    lookSpeed: 100
    // lookSpeed: 3000
  }

}

