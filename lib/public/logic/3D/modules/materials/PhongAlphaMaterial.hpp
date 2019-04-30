#pragma once

#include "Material.hpp"

namespace ART {
namespace Logic {
namespace Modules {

class PhongAlphaMaterial : public Material<Qt3DExtras::QPhongAlphaMaterial> {
  Q_OBJECT
  Q_PROPERTY(float alpha READ alpha NOTIFY dataUpdate)
  Q_PROPERTY(float shininess READ shininess NOTIFY dataUpdate)
  Q_PROPERTY(QColor diffuse READ diffuse NOTIFY dataUpdate)
  Q_PROPERTY(QColor specular READ specular NOTIFY dataUpdate)
  Q_PROPERTY(QColor ambient READ ambient NOTIFY dataUpdate)
  Q_DISABLE_COPY(PhongAlphaMaterial)
public:
  PhongAlphaMaterial(Shape3D &parent, std::string id);
  ~PhongAlphaMaterial() override;

  float alpha();
  float shininess();
  QColor diffuse();
  QColor specular();
  QColor ambient();

public Q_SLOTS:
  void setAlpha(float alpha) noexcept;
  void setShininess(float shininess) noexcept;
  void setDiffuse(const QColor &color) noexcept;
  void setAmbient(const QColor &color) noexcept;
  void setSpecular(const QColor &color) noexcept;

Q_SIGNALS:
  void dataUpdate();
};

} // namespace Modules
} // namespace Logic
} // namespace ART