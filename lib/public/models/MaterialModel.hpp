#pragma once

#include "Entity.hpp"
#include <QObject>

namespace ART {
namespace Logic {
namespace Modules {

class MaterialModel : public Entity {
  Q_OBJECT

public:
  MaterialModel(std::string name) : Entity{std::move(name)} {}

public Q_SLOTS:
  virtual void setBaseColorTexture(const QUrl &) {}
  virtual void setMetalnessTexture(const QUrl &) {}
  virtual void setRoughnessTexture(const QUrl &) {}
  virtual void setNormalTexture(const QUrl &) {}
  virtual void setAmbientOcclusionTexture(const QUrl &) {}
};

} // namespace Modules
} // namespace Logic
} // namespace ART