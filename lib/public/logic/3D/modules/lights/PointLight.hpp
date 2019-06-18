#pragma once

#include "Light.hpp"
#include "PhongMaterial.hpp"
#include "Shape3D.hpp"
#include "SphereMesh.hpp"

namespace ART::Logic::Modules::Lights {

class PointLight : public Light<Qt3DRender::QPointLight> {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color NOTIFY dataUpdate)
  Q_PROPERTY(float intensity READ intensity NOTIFY dataUpdate)
  Q_PROPERTY(float constantAttenuation READ constantAttenuation NOTIFY dataUpdate)
  Q_PROPERTY(float linearAttenuation READ linearAttenuation NOTIFY dataUpdate)
  Q_PROPERTY(float quadraticAttenuation READ quadraticAttenuation NOTIFY dataUpdate)

  Q_DISABLE_COPY(PointLight)
public:
  PointLight(Shape3D &parent, std::string id);

  virtual ~PointLight();

  const QColor color();

  const float intensity();

  const float constantAttenuation();
  const float linearAttenuation();
  const float quadraticAttenuation();

public Q_SLOTS:

  void setColor(const QColor &color);
  void setIntensity(float intensity);
  void setConstantAttenuation(float attenuation);
  void setLinearAttenuation(float attenuation);
  void setQuadraticAttenuation(float attenuation);

Q_SIGNALS:
  void dataUpdate();

private:
  Modules::PhongMaterial *_material;
};

} // namespace ART::Logic::Modules::Lights