#pragma once

#include "Light.hpp"
#include "PhongMaterial.hpp"
#include "Shape3D.hpp"
#include "SphereMesh.hpp"

namespace ART::Logic::Modules::Lights {

class PointLight : public Light<Qt3DRender::QPointLight> {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color NOTIFY dataUpdate)
  Q_DISABLE_COPY(PointLight)
public:
  PointLight(Shape3D &parent, std::string id);

  virtual ~PointLight();

  QColor color();

public Q_SLOTS:

  void setColor(const QColor &color);

Q_SIGNALS:
  void dataUpdate();

private:
  Modules::PhongMaterial *_material;
};

} // namespace ART::Logic::Modules::Lights