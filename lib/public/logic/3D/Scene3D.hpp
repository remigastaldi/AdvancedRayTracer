#pragma once

#include "globals.h"

#include "Scene.hpp"
#include "Sphere.hpp"

#include <QPointLight>
#include <QRenderSettings>
#include <Qt3DExtras>
#include <Qt3DRender>

#include <unordered_map>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene3D : public Scene {
  Q_OBJECT
  Q_DISABLE_COPY(Scene3D)

public:
  explicit Scene3D(Qt3DCore::QEntity *root = 0);

public Q_SLOTS:
  void createSphere() noexcept;
  void removeSphere() noexcept;

  const std::unordered_map<std::string, std::unique_ptr<Entity>> &entities() const noexcept;
  Entity *selectedEntity() const noexcept override { return nullptr;}

private:
  std::unordered_map<std::string, std::unique_ptr<Entity>> _entities;
  // Qt3DRender::QSceneLoader *sceneLoader;
  Qt3DCore::QEntity *_root;
};
} // namespace Logic
} // namespace ART