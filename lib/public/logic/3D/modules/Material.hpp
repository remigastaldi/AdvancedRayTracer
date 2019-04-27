#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <QEntity>
#include <QRect>
#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

template <typename T> class Material : public Entity {
public:
  Material(Shape3D &parent, std::string id, T *material = new T)
      : Entity{std::move(id)}, _material{material}, _parent{parent} {
    _material->setParent(parent.getQEntity());
    _parent.getQEntity()->addComponent(_material);
    _parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  }

  virtual ~Material() {
    _parent.getQEntity()->removeComponent(_material);
    delete _material;
  }
  // void setBaseColor(const QUrl &path) override {
  //   Qt3DRender::QTextureLoader *baseColorLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  //   baseColorLoader->setSource(QUrl::fromLocalFile(path.path()));
  //   baseColorLoader->setFormat(Qt3DRender::QAbstractTexture::SRGB8_Alpha8);
  //   _material->setBaseColor(QVariant::fromValue(baseColorLoader));
  // }
  // void setBaseColor(const QColor &color) override { _material->setBaseColor(color); }

  // void setMetalnessTexture(const QUrl &path) override {
  //   Qt3DRender::QTextureLoader *metalnessLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  //   metalnessLoader->setSource(QUrl::fromLocalFile(path.path()));
  //   _material->setMetalness(QVariant::fromValue(metalnessLoader));
  // }

  // void setRoughnessTexture(const QUrl &path) override {
  //   Qt3DRender::QTextureLoader *roughnessLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  //   roughnessLoader->setSource(QUrl::fromLocalFile(path.path()));
  //   _material->setRoughness(QVariant::fromValue(roughnessLoader));
  // }

  // void setNormalTexture(const QUrl &path) override {
  //   Qt3DRender::QTextureLoader *normalLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  //   normalLoader->setSource(QUrl::fromLocalFile(path.path()));
  //   _material->setNormal(QVariant::fromValue(normalLoader));
  // }

  // void setAmbientOcclusionTexture(const QUrl &path) override {
  //   Qt3DRender::QTextureLoader *ambientOcclusionLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  //   ambientOcclusionLoader->setSource(QUrl::fromLocalFile(path.path()));
  //   _material->setAmbientOcclusion(QVariant::fromValue(ambientOcclusionLoader));
  // }

  // void setMetalness(const float value) override { _material->setMetalness(value); }

  // void setRoughness(const float value) override { _material->setRoughness(value); }

  // QVariant metalness() const override { return _material->metalness(); }

  // QVariant roughness() const override { return _material->roughness(); }

  // QVariant baseColor() const override {
  //   QVariant color = _material->baseColor();
  //   if (color.type() == QVariant::Color) {
  //     return color;
  //   } else {
  //     return "Not Color";
  //   }
  // }

  T *get() noexcept { return _material; }

  Shape3D &getShape() noexcept { return _parent; }

private:
  Shape3D &_parent;
  T *_material;
};

} // namespace Modules
} // namespace Logic
} // namespace ART