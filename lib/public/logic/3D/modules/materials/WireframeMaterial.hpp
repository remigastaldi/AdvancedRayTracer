#pragma once

#include "Material.hpp"

namespace ART::Logic::Modules {

class WireframeMaterial : public Material<Qt3DRender::QMaterial> {
  Q_OBJECT
  // Q_PROPERTY(QColor diffuse READ diffuse NOTIFY dataUpdate)
  // Q_PROPERTY(QColor specular READ specular NOTIFY dataUpdate)
  // Q_PROPERTY(QColor ambient READ ambient NOTIFY dataUpdate)
  Q_PROPERTY(bool alphaCoverage READ alphaCoverage NOTIFY dataUpdate)
  Q_DISABLE_COPY(WireframeMaterial)
public:
  WireframeMaterial(Shape3D &parent, std::string id, Qt3DRender::QMaterial *material = new Qt3DRender::QMaterial);
  ~WireframeMaterial() override;

  void makeMaterial() noexcept;
  // QColor diffuse();
  // QColor specular();
  // QColor ambient();
  bool alphaCoverage() const noexcept;

public Q_SLOTS:
  // void setDiffuse(const QColor &color) noexcept;
  // void setAmbient(const QColor &color) noexcept;
  // void setSpecular(const QColor &color) noexcept;
  void enableAlphaCoverage(bool enable) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
  bool _alphaCoverage;
   Qt3DRender::QRenderPass *_renderPass;
   Qt3DRender::QAlphaCoverage *_qAlphaCoverage;
   Qt3DRender::QMultiSampleAntiAliasing *_qMultisample;
};

} // namespace ART::Logic::Modules