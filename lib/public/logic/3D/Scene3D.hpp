#pragma once

#include "globals.h"

#include "RootEntity.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "CameraController.hpp"

#include <QPointLight>
#include <QRenderSettings>
#include <QVector3D>
#include <Qt3DExtras>
#include <Qt3DRender>
#include <unordered_map>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene3D : public Scene {
  Q_OBJECT
  Q_DISABLE_COPY(Scene3D)
  DISABLE_MOVE(Scene3D)

  Q_PROPERTY(ART::Controllers::CameraController *cameraController READ cameraController CONSTANT)

public:
  explicit Scene3D(RootEntity *root = nullptr);
  ~Scene3D() override = default;

public Q_SLOTS:
  void createSphere() noexcept;
  void createSquare() noexcept;
  void createTorus() noexcept;
  void import3DModel(const QUrl &);
  void import3DScene(const QUrl &);

  const std::unordered_map<std::string, std::unique_ptr<Entity>> &entities() const noexcept override;
  Entity *selectedEntity() const noexcept override;
  void selectEntity(const std::string &id) noexcept override;

  void keyPressedEvent(Qt::Key event) override;

  Controllers::CameraController * cameraController() const noexcept {
    return _cameraController;
  }

private:
  std::unordered_map<std::string, std::unique_ptr<Entity>> _entities;
  RootEntity *_root;
  Controllers::CameraController *_cameraController;
  std::string _selectedEntity;
  size_t _urrId;
};

} // namespace Logic
} // namespace ART