#include "Material.hpp"

namespace ART {
namespace Logic {
namespace Modules {

// Material::Material(std::string id) : Entity{std::move(id)} {}

// template<typename T>
// Material<T>::Material(std::string id, T *material) : Entity{std::move(id)}, _material{material} {};
template <typename T> void Material<T>::setBaseColorTexture(const QUrl &path) {
  Qt3DRender::QTextureLoader *baseColorLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  baseColorLoader->setSource(QUrl::fromLocalFile(path.path()));
  baseColorLoader->setFormat(Qt3DRender::QAbstractTexture::SRGB8_Alpha8);
  _material->setBaseColor(QVariant::fromValue(baseColorLoader));
}

template <typename T> void Material<T>::setMetalnessTexture(const QUrl &path) {
  Qt3DRender::QTextureLoader *metalnessLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  metalnessLoader->setSource(QUrl::fromLocalFile(path.path()));
  _material->setMetalness(QVariant::fromValue(metalnessLoader));
}

template <typename T> void Material<T>::setRoughnessTexture(const QUrl &path) {
  Qt3DRender::QTextureLoader *roughnessLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  roughnessLoader->setSource(QUrl::fromLocalFile(path.path()));
  _material->setRoughness(QVariant::fromValue(roughnessLoader));
}

template <typename T> void Material<T>::setNormalTexture(const QUrl &path) {
  Qt3DRender::QTextureLoader *normalLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  normalLoader->setSource(QUrl::fromLocalFile(path.path()));
  _material->setNormal(QVariant::fromValue(normalLoader));
}

template <typename T> void Material<T>::setAmbientOcclusionTexture(const QUrl &path) {
  Qt3DRender::QTextureLoader *ambientOcclusionLoader = new Qt3DRender::QTextureLoader(_parent.getQEntity());
  ambientOcclusionLoader->setSource(QUrl::fromLocalFile(path.path()));
  _material->setAmbientOcclusion(QVariant::fromValue(ambientOcclusionLoader));
}

} // namespace Modules
} // namespace Logic
} // namespace ART