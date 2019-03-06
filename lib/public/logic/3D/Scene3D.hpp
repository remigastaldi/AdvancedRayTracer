#pragma once

#include "globals.h"

#include "Sphere.hpp"

#include <QEntity>
#include <QPointLight>
#include <QRenderSettings>
#include <Qt3DExtras>
#include <Qt3DRender>

#include <unordered_map>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene3D : public Qt3DCore::QEntity {
  Q_OBJECT
  Q_DISABLE_COPY(Scene3D)

public:
  explicit Scene3D(Qt3DCore::QEntity *parent = 0);

public Q_SLOTS:
  void createSphere() noexcept;
  void removeSphere() noexcept;

  // void status(Qt3DRender::QSceneLoader::Status status) {
  //   qInfo() << status;
  //   qInfo() << sceneLoader->entityNames();
  //   // qInfo() << sceneLoader->component("Earth", ;
  // }

private:
  std::unordered_map<std::string, std::unique_ptr<Qt3DCore::QEntity>> _entities;
  // Qt3DRender::QSceneLoader *sceneLoader;
};
} // namespace Logic
} // namespace ART