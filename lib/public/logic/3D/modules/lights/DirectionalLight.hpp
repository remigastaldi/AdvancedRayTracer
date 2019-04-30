#pragma once

#include "Light.hpp"
#include "PhongMaterial.hpp"
#include "Shape3D.hpp"

#include <Qt3DCore>

namespace ART::Logic::Modules::Lights {

class DirectionalLight : public Light<Qt3DRender::QDirectionalLight> {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color NOTIFY dataUpdate)
  Q_PROPERTY(QVector3D worldDirection READ worldDirection NOTIFY dataUpdate)
  Q_PROPERTY(float intensity READ intensity NOTIFY dataUpdate)
  Q_DISABLE_COPY(DirectionalLight)
public:
  DirectionalLight(Shape3D &parent, std::string id);

  virtual ~DirectionalLight();

  const QColor color();
  const float intensity();

  const QVector3D worldDirection();


public Q_SLOTS:

  void setColor(const QColor &color);
  void setIntensity(float intensity);
  void setWorldDirection(QVector3D worldDirection);


  void setWorldDirectionX(float x);
  void setWorldDirectionY(float y);
  void setWorldDirectionZ(float z);

Q_SIGNALS:
  void dataUpdate();
};

} // namespace ART::Logic::Modules::Lights