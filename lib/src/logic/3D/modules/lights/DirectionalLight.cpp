#include "DirectionalLight.hpp"

#include "ConeMesh.hpp"

namespace ART::Logic::Modules::Lights {
DirectionalLight::DirectionalLight(Shape3D &parent, std::string id) : Light<Qt3DRender::QDirectionalLight>{parent, id} {
  getShape().removeChildren("Material");
  getShape().removeChildren("Mesh");

  get()->setIntensity(1);
  // get()->setWorldDirection({0, 1, 0});
  QVector3D test = get()->worldDirection();
  test.setY(1);
  setWorldDirection(test);

  setColor("green");
}

DirectionalLight::~DirectionalLight() {}

const QColor DirectionalLight::color() { return get()->color(); }
const float DirectionalLight::intensity() { return get()->intensity(); }

const QVector3D DirectionalLight::worldDirection() { return get()->worldDirection(); }

void DirectionalLight::setColor(const QColor &color) {
  get()->setColor(color);

  Q_EMIT dataUpdate();
}

void DirectionalLight::setIntensity(float intensity) {
  get()->setIntensity(intensity);

  Q_EMIT dataUpdate();
}

void DirectionalLight::setWorldDirection(QVector3D worldDirection) {
  get()->setWorldDirection(worldDirection);

  Q_EMIT dataUpdate();
}

void DirectionalLight::setWorldDirectionX(float x) {
  QVector3D worldDirection = get()->worldDirection();
  worldDirection.setX(x);
  setWorldDirection(worldDirection);

  Q_EMIT dataUpdate();
}
void DirectionalLight::setWorldDirectionY(float y) {
  QVector3D worldDirection = get()->worldDirection();
  worldDirection.setY(y);
  setWorldDirection(worldDirection);

  Q_EMIT dataUpdate();
}

void DirectionalLight::setWorldDirectionZ(float z) {
  QVector3D worldDirection = get()->worldDirection();
  worldDirection.setZ(z);
  setWorldDirection(worldDirection);

  Q_EMIT dataUpdate();
}

} // namespace ART::Logic::Modules::Lights
