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
  camera: camera
  frustumCulling: false

  property var currentCamera : camera
  signal cameraChanged(Camera newCamera);

  signal pressed(int posx, int posy);
  onPressed: (posx, posy) => {
    cameraChanged(camera)
  }
  
  Camera {
    id: camera
    projectionType: CameraLens.PerspectiveProjection
    fieldOfView: 60
    nearPlane : 0.1
    farPlane : 1000.0
    aspectRatio: scene3D.width / scene3D.height
    position: Qt.vector3d(-10.0, 0.0, 10.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
  }
}

