#include "PointLight.hpp"

namespace ART::Logic::Modules::Lights {
PointLight::PointLight(Shape3D &parent, std::string id) : Light<Qt3DRender::QPointLight>{parent, id} {
  getShape().removeChildren("Material");
  getShape().removeChildren("Mesh");

  auto *mesh = new Modules::SphereMesh(parent, "Mesh");
  mesh->setRadius(0.5);

  _material = new Modules::PhongMaterial(parent, "Material");

  get()->setIntensity(1);
  setColor("green");
}

PointLight::~PointLight() {}

QColor PointLight::color() { return get()->color(); }

float PointLight::intensity() { return get()->intensity(); }

void PointLight::setColor(const QColor &color) {
  _material->setDiffuse(color);
  _material->setAmbient(color);
  _material->setSpecular(color);
  get()->setColor(color);
  Q_EMIT dataUpdate();
}

void PointLight::setIntensity(float intensity) {
  get()->setIntensity(intensity);

  Q_EMIT dataUpdate();
}

} // namespace ART::Logic::Modules::Lights