#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include "MaterialModel.hpp"
#include <QEntity>
#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

template <typename T = Qt3DExtras::QMetalRoughMaterial> class Material : public MaterialModel {
public:
  Material(Shape3D &parent, std::string id, T *material = new T)
      : MaterialModel{std::move(id)}, _material{material}, _parent{parent} {
    _material->setParent(parent.getQEntity());
    _parent.getQEntity()->addComponent(_material);
    _parent.addChildren(Entity::id(), std::unique_ptr<Entity>(dynamic_cast<MaterialModel *>(this)));
  };

  virtual ~Material() {
    _parent.getQEntity()->removeComponent(_material);
    delete _material;
  }
  void setBaseColorTexture(const QUrl &path) override {
    qInfo() << path;
    Qt3DRender::QTextureLoader *baseColorLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
    baseColorLoader->setSource(QUrl::fromLocalFile(path.path()));
    baseColorLoader->setFormat(Qt3DRender::QAbstractTexture::SRGB8_Alpha8);
    _material->setBaseColor(QVariant::fromValue(baseColorLoader));
  }

  void setMetalnessTexture(const QUrl &path) override {
    Qt3DRender::QTextureLoader *metalnessLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
    metalnessLoader->setSource(QUrl::fromLocalFile(path.path()));
    _material->setMetalness(QVariant::fromValue(metalnessLoader));
  }

  void setRoughnessTexture(const QUrl &path) override {
    Qt3DRender::QTextureLoader *roughnessLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
    roughnessLoader->setSource(QUrl::fromLocalFile(path.path()));
    _material->setRoughness(QVariant::fromValue(roughnessLoader));
  }

  void setNormalTexture(const QUrl &path) override {
    Qt3DRender::QTextureLoader *normalLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
    normalLoader->setSource(QUrl::fromLocalFile(path.path()));
    _material->setNormal(QVariant::fromValue(normalLoader));
  }

  void setAmbientOcclusionTexture(const QUrl &path) override {
    Qt3DRender::QTextureLoader *ambientOcclusionLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
    ambientOcclusionLoader->setSource(QUrl::fromLocalFile(path.path()));
    _material->setAmbientOcclusion(QVariant::fromValue(ambientOcclusionLoader));
  }

  void setMetalness(const float value) override { _material->setMetalness(value); }

  void setRoughness(const float value) override { _material->setRoughness(value); }

  QVariant metalness() const override { return _material->metalness(); }

  QVariant roughness() const override { return _material->roughness(); }

  T *get() noexcept { return _material; }
  T *operator->();

private:
  Shape3D &_parent;
  T *_material;
};

template <typename T> T *Material<T>::operator->() { return _material; }

} // namespace Modules
} // namespace Logic
} // namespace ART