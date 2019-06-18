#pragma once

#include "Light.hpp"
#include "PhongMaterial.hpp"
#include "Shape3D.hpp"

#include <Qt3DCore>

namespace ART::Logic::Modules::Lights {

class SpotLight : public Light<Qt3DRender::QSpotLight> {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color NOTIFY dataUpdate)
  Q_PROPERTY(float intensity READ intensity NOTIFY dataUpdate)
  Q_PROPERTY(float constantAttenuation READ constantAttenuation NOTIFY dataUpdate)
  Q_PROPERTY(float linearAttenuation READ linearAttenuation NOTIFY dataUpdate)
  Q_PROPERTY(float quadraticAttenuation READ quadraticAttenuation NOTIFY dataUpdate)
  Q_PROPERTY(float cutOffAngle READ cutOffAngle NOTIFY dataUpdate)
  Q_DISABLE_COPY(SpotLight)
public:
  SpotLight(Shape3D &parent, std::string id);

  virtual ~SpotLight();

  const QColor color();
  const float intensity();

  const float constantAttenuation();
  const float linearAttenuation();
  const float quadraticAttenuation();

  const float cutOffAngle();

public Q_SLOTS:

  void setColor(const QColor &color);
  void setIntensity(float intensity);

  void setConstantAttenuation(float attenuation);
  void setLinearAttenuation(float attenuation);
  void setQuadraticAttenuation(float attenuation);

  void setCutOffAngle(float angle);

Q_SIGNALS:
  void dataUpdate();

private:
  PhongMaterial *_material;
};

} // namespace ART::Logic::Modules::Lights