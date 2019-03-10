#pragma once

#include "globals.h"

#include "Scene.hpp"
#include "Sphere.hpp"
#include "RootEntity.hpp"

#include <QPointLight>
#include <QRenderSettings>
#include <Qt3DExtras>
#include <Qt3DRender>
#include <QVector3D>
#include <unordered_map>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene3D : public Scene {
  Q_OBJECT
  Q_DISABLE_COPY(Scene3D)

public:
  explicit Scene3D(RootEntity *root = 0);

public Q_SLOTS:
  void createSphere() noexcept;
  void createSquare() noexcept;
  void removeSphere() noexcept;
  void import3DModel(const QUrl &);
  void import3DScene(const QUrl &);

  const std::unordered_map<std::string, std::unique_ptr<Entity>> &entities() const noexcept override;
  Entity *selectedEntity() const noexcept override;
  void selectEntity(const std::string & id) noexcept override;

  void updateSkyboxPosition(QVector3D pos) noexcept {
    // pos.setX(pos.x() *-1);
    // _skyboxPos->setTranslation(pos);
  }
  void keyPressedEvent(Qt::Key event) override;

private:
  std::unordered_map<std::string, std::unique_ptr<Entity>> _entities;
  RootEntity *_root;
  std::string _selectedEntity;
  Qt3DCore::QTransform *_skyboxPos;
};

} // namespace Logic
} // namespace ART