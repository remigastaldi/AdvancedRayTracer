#pragma once

#include "Light.hpp"
#include "Shape3D.hpp"
#include "PhongMaterial.hpp"

namespace ART::Logic::Modules::Lights {

class PointLight : public Light<Qt3DRender::QPointLight> {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color NOTIFY dataUpdate)
  Q_DISABLE_COPY(PointLight)
public:
  PointLight(Shape3D &parent, std::string id) : Light<Qt3DRender::QPointLight>{parent, id} {
    _material = new Modules::PhongMaterial(parent, "Material");
    get()->setIntensity(1);
    setColor("green");
  }

  virtual ~PointLight()  {
    getShape().removeChildren("Material");
  }

  QColor color() { return get()->color(); }

public Q_SLOTS:

  void setColor(const QColor &color) {
    _material->setDiffuse(color);
    _material->setAmbient(color);
    _material->setSpecular(color);
    get()->setColor(color);
    Q_EMIT dataUpdate();
  }

Q_SIGNALS:
  void dataUpdate();

private:
  Modules::PhongMaterial *_material;
};

} // namespace ART::Logic::Modules::Lights