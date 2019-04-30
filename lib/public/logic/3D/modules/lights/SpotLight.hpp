#pragma once

#include "Light.hpp"
#include "Shape3D.hpp"

#include "ConeMesh.hpp"
#include "PhongAlphaMaterial.hpp"

#include <Qt3DCore>

namespace ART::Logic::Modules::Lights {

class SpotLight : public Light<Qt3DRender::QSpotLight> {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color NOTIFY dataUpdate)
  Q_DISABLE_COPY(SpotLight)
public:
  SpotLight(Shape3D &parent, std::string id);

  virtual ~SpotLight();

  QColor color();

public Q_SLOTS:

  void setColor(const QColor &color);

Q_SIGNALS:
  void dataUpdate();

private:
  PhongAlphaMaterial *_material;
};

} // namespace ART::Logic::Modules::Lights