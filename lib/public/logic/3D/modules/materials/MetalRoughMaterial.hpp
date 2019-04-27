#pragma once

#include "Material.hpp"

namespace ART {
namespace Logic {
namespace Modules {

class MetalRoughMaterial : public Material<Qt3DExtras::QMetalRoughMaterial> {
  Q_OBJECT
  Q_DISABLE_COPY(MetalRoughMaterial)

public:
  MetalRoughMaterial(Shape3D &parent, std::string id,
                     Qt3DExtras::QMetalRoughMaterial *material = new Qt3DExtras::QMetalRoughMaterial);
  ~MetalRoughMaterial() override;

public Q_SLOTS:

  void setBaseColor(const QUrl &path) {
    Qt3DRender::QTextureLoader *baseColorLoader = new Qt3DRender::QTextureLoader(getShape().getQEntity());
    baseColorLoader->setSource(QUrl::fromLocalFile(path.path()));
    baseColorLoader->setFormat(Qt3DRender::QAbstractTexture::SRGB8_Alpha8);
    get()->setBaseColor(QVariant::fromValue(baseColorLoader));
  }
  void setBaseColor(const QColor &color) { get()->setBaseColor(color); }

  void setMetalnessTexture(const QUrl &path) {
    Qt3DRender::QTextureLoader *metalnessLoader = new Qt3DRender::QTextureLoader(getShape().getQEntity());
    metalnessLoader->setSource(QUrl::fromLocalFile(path.path()));
    get()->setMetalness(QVariant::fromValue(metalnessLoader));
  }

  void setRoughnessTexture(const QUrl &path) {
    Qt3DRender::QTextureLoader *roughnessLoader = new Qt3DRender::QTextureLoader(getShape().getQEntity());
    roughnessLoader->setSource(QUrl::fromLocalFile(path.path()));
    get()->setRoughness(QVariant::fromValue(roughnessLoader));
  }

  void setNormalTexture(const QUrl &path) {
    Qt3DRender::QTextureLoader *normalLoader = new Qt3DRender::QTextureLoader(getShape().getQEntity());
    normalLoader->setSource(QUrl::fromLocalFile(path.path()));
    get()->setNormal(QVariant::fromValue(normalLoader));
  }

  void setAmbientOcclusionTexture(const QUrl &path) {
    Qt3DRender::QTextureLoader *ambientOcclusionLoader = new Qt3DRender::QTextureLoader(getShape().getQEntity());
    ambientOcclusionLoader->setSource(QUrl::fromLocalFile(path.path()));
    get()->setAmbientOcclusion(QVariant::fromValue(ambientOcclusionLoader));
  }

  void setMetalness(const float value) { get()->setMetalness(value); }

  void setRoughness(const float value) { get()->setRoughness(value); }

  QVariant metalness() { return get()->metalness(); }

  QVariant roughness() { return get()->roughness(); }

  QVariant baseColor() {
    QVariant color = get()->baseColor();
    if (color.type() == QVariant::Color) {
      return color;
    } else {
      return "Not Color";
    }
  }
};

} // namespace Modules
} // namespace Logic
} // namespace ART