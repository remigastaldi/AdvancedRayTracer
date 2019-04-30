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

const QColor PointLight::color() { return get()->color(); }

const float PointLight::intensity() { return get()->intensity(); }

const float PointLight::constantAttenuation() { return get()->constantAttenuation(); }
const float PointLight::linearAttenuation() { return get()->linearAttenuation(); }
const float PointLight::quadraticAttenuation() { return get()->quadraticAttenuation(); }

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

void PointLight::setConstantAttenuation(float attenuation) { get()->setConstantAttenuation(attenuation); }
void PointLight::setLinearAttenuation(float attenuation) { get()->setLinearAttenuation(attenuation); }
void PointLight::setQuadraticAttenuation(float attenuation) { get()->setQuadraticAttenuation(attenuation); }

} // namespace ART::Logic::Modules::Lights