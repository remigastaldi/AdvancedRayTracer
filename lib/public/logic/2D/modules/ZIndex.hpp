#pragma once

#include "globals.h"

#include "Entity.hpp"

#include <QObject>

namespace ART {
namespace Logic {
  class Scene2D;
  class Shape2D;

namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT ZIndex : public Entity {
  Q_OBJECT
  Q_PROPERTY(int zIndex READ zIndex NOTIFY zIndexUpdate)

public:
  ZIndex(Scene2D &scene, Shape2D &parent, std::string id);

  virtual ~ZIndex();
  int zIndex() const noexcept;
public Q_SLOTS:
  void setIndex(int zIndex) noexcept;

private:
  int _zIndex;
  Scene2D &_scene;
  Shape2D &_parent;

Q_SIGNALS:
  void zIndexUpdate(int zIndex, const std::string &id);
  void zIndexDelete(int zIndex, const std::string &id);
};

} // namespace Modules
} // namespace Logic
} // namespace ART