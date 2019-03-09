#pragma once

#include "globals.h"

#include <QObject>
#include <QString>

#include <Qt3DCore/QAspectEngine>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>

#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DRender/QRenderAspect>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class QQmlApplicationEngine;

// #include "Outliner.hpp"
// #include "Scene3D.hpp"
namespace ART {
namespace Logic {
class Scene3D;
class Scene2D;
class Scene;
class Entity;
namespace Modules {
class ZIndex;
}
} // namespace Logic
namespace Models {
class Outliner;
} // namespace Models

namespace Controllers {

class ToolbarController;
class DrawToolbar3DController;
class DrawToolbar2DController;
class RightSidebarController;

class ADVANCED_RAY_TRACER_EXPORT MainController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MainController)

  Q_PROPERTY(ART::Controllers::ToolbarController *toolbarController READ toolbarController CONSTANT)
  Q_PROPERTY(ART::Controllers::RightSidebarController *rightSidebarController READ rightSidebarController CONSTANT)
  Q_PROPERTY(ART::Controllers::DrawToolbar3DController *drawToolbar3DController READ drawToolbar3DController CONSTANT)
  Q_PROPERTY(ART::Controllers::DrawToolbar2DController *drawToolbar2DController READ drawToolbar2DController CONSTANT)
  Q_PROPERTY(ART::Logic::Scene3D *scene3D READ scene3D CONSTANT)
  Q_PROPERTY(ART::Logic::Scene2D *scene2D READ scene2D CONSTANT)
  Q_PROPERTY(ART::Models::Outliner *outliner READ outliner CONSTANT)

public:
  explicit MainController(QObject *parent = nullptr);
  ~MainController() = default;
  MainController(MainController &&other) = delete;
  MainController &operator=(MainController &&other) = delete;

  void setScene3D(Logic::Scene3D *scene) noexcept;
  void setScene2D(Logic::Scene2D *scene) noexcept;
  void setOutliner(ART::Models::Outliner *outliner) noexcept;
  void setEngine(QQmlApplicationEngine *engine) noexcept;

  ToolbarController *toolbarController() const noexcept;
  DrawToolbar3DController *drawToolbar3DController() const noexcept;
  DrawToolbar2DController *drawToolbar2DController() const noexcept;
  RightSidebarController *rightSidebarController() const noexcept;
  Logic::Scene3D *scene3D() const noexcept;
  Logic::Scene2D *scene2D() const noexcept;
  ART::Models::Outliner *outliner() const noexcept;

public Q_SLOTS:
  void sceneUpdate() noexcept;
  QVariantList loadTree();

  void initEntityModulesModels();
  void updateCurrentScene();
  void selectedShapeUpdate();

  // DELETE THIS
  void selectEntityByIndex(int index);

private:
  DrawToolbar3DController *_drawToolbar3DController;
  DrawToolbar2DController *_drawToolbar2DController;
  ToolbarController *_toolbarController;
  RightSidebarController *_rightSidebarController;
  Logic::Scene3D *_scene3D;
  Logic::Scene2D *_scene2D;
  ART::Models::Outliner *_outliner;
  Logic::Scene *_currentScene;
  QQmlApplicationEngine *_engine;

public Q_SLOTS:
  void handleSaveFileClicked();
  void handleSaveAsFileClicked(const QUrl &url);
  void handleNewFileClicked();
  void handleimportImageClicked(const QUrl &url);
  void selectScene3D();
  void selectScene2D();

Q_SIGNALS:
  // void scene3DSelected();
  // void scene2DSelected();
  void updateUiModules();
};

} // namespace Controllers
} // namespace ART
