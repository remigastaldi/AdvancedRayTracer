#pragma once

#include "Material.hpp"

namespace ART::Logic::Modules {

class WireframeMaterial : public Material<Qt3DRender::QMaterial> {
  Q_OBJECT
  // Q_PROPERTY(QColor diffuse READ diffuse NOTIFY dataUpdate)
  // Q_PROPERTY(QColor specular READ specular NOTIFY dataUpdate)
  // Q_PROPERTY(QColor ambient READ ambient NOTIFY dataUpdate)
  Q_DISABLE_COPY(WireframeMaterial)
public:
  WireframeMaterial(Shape3D &parent, std::string id, Qt3DRender::QMaterial *material = new Qt3DRender::QMaterial);
  ~WireframeMaterial() override;

  // QColor diffuse();
  // QColor specular();
  // QColor ambient();

public Q_SLOTS:
  // void setDiffuse(const QColor &color) noexcept;
  // void setAmbient(const QColor &color) noexcept;
  // void setSpecular(const QColor &color) noexcept;

Q_SIGNALS:
  void dataUpdate();
};

} // namespace ART::Logic::Modules