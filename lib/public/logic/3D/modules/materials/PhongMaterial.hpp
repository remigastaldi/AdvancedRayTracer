#pragma once

#include "Material.hpp"

namespace ART {
namespace Logic {
namespace Modules {

class PhongMaterial : public Material<Qt3DExtras::QPhongMaterial> {
  Q_OBJECT
  Q_PROPERTY(QColor diffuse READ diffuse NOTIFY dataUpdate)
  Q_PROPERTY(QColor specular READ specular NOTIFY dataUpdate)
  Q_PROPERTY(QColor ambient READ ambient NOTIFY dataUpdate)
  Q_DISABLE_COPY(PhongMaterial)
public:
  PhongMaterial(Shape3D &parent, std::string id, Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial);
  ~PhongMaterial() override;

  QColor diffuse();
  QColor specular();
  QColor ambient();

public Q_SLOTS:
  void setDiffuse(const QColor &color) noexcept;
  void setAmbient(const QColor &color) noexcept;
  void setSpecular(const QColor &color) noexcept;

Q_SIGNALS:
  void dataUpdate();
};

} // namespace Modules
} // namespace Logic
} // namespace ART