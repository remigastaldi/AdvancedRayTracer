#pragma once

#include "Entity.hpp"
#include <QObject>
#include <QVariant>
#include <QColor>

namespace ART {
namespace Logic {
namespace Modules {

class MaterialModel : public Entity {
  Q_OBJECT

public:
  MaterialModel(std::string name) : Entity{std::move(name)} {}


public Q_SLOTS:
  virtual QVariant metalness() const { return 0;}
  virtual QVariant roughness() const { return 0;}
  virtual QVariant baseColor() const { return "#FFFFFF";}
  virtual void setBaseColor(const QUrl &) {}
  virtual void setBaseColor(const QColor &) {}
  virtual void setMetalnessTexture(const QUrl &) {}
  virtual void setRoughnessTexture(const QUrl &) {}
  virtual void setNormalTexture(const QUrl &) {}
  virtual void setAmbientOcclusionTexture(const QUrl &) {}
  virtual void setMetalness(float) {}
  virtual void setRoughness(float) {}
};

} // namespace Modules
} // namespace Logic
} // namespace ART