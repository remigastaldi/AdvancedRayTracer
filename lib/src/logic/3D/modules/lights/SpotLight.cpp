#include "SpotLight.hpp"

#include "ConeMesh.hpp"

namespace ART::Logic::Modules::Lights {
SpotLight::SpotLight(Shape3D &parent, std::string id) : Light<Qt3DRender::QSpotLight>{parent, id} {
  getShape().removeChildren("Material");
  getShape().removeChildren("Mesh");

  auto *mesh = new Modules::ConeMesh(parent, "Mesh");
  mesh->setLength(2);
  mesh->setBottomRadius(0.5);
  mesh->setTopRadius(1.5);
  mesh->setSlices(4);

  _material = new Modules::PhongMaterial(parent, "Material");

  get()->setIntensity(1);
  get()->setLocalDirection({0, 1, 0});

  setColor("green");
}

SpotLight::~SpotLight() {}

const QColor SpotLight::color() { return get()->color(); }
const float SpotLight::intensity() { return get()->intensity(); }

const float SpotLight::constantAttenuation() { return get()->constantAttenuation(); }
const float SpotLight::linearAttenuation() { return get()->linearAttenuation(); }
const float SpotLight::quadraticAttenuation() { return get()->quadraticAttenuation(); }
const float SpotLight::cutOffAngle() { return get()->cutOffAngle(); }

void SpotLight::setColor(const QColor &color) {
  _material->setDiffuse(color);
  _material->setAmbient(color);
  _material->setSpecular(color);
  get()->setColor(color);

  Q_EMIT dataUpdate();
}

void SpotLight::setIntensity(float intensity) {
  get()->setIntensity(intensity);

  Q_EMIT dataUpdate();
}

void SpotLight::setConstantAttenuation(float attenuation) { get()->setConstantAttenuation(attenuation); }
void SpotLight::setLinearAttenuation(float attenuation) { get()->setLinearAttenuation(attenuation); }
void SpotLight::setQuadraticAttenuation(float attenuation) { get()->setQuadraticAttenuation(attenuation); }
void SpotLight::setCutOffAngle(float angle) { get()->setCutOffAngle(angle); }

} // namespace ART::Logic::Modules::Lights
