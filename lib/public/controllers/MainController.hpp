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

namespace ART {
namespace Logic {
class Scene3D;
class Scene2D;
} // namespace Logic

namespace Controllers {

class ToolbarController;
class RightSidebarController;
class LeftSidebarController;

class ADVANCED_RAY_TRACER_EXPORT MainController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MainController)

  Q_PROPERTY(ART::Controllers::ToolbarController *toolbarController READ toolbarController CONSTANT)
  Q_PROPERTY(ART::Controllers::RightSidebarController *rightSidebarController READ rightSidebarController CONSTANT)
  Q_PROPERTY(ART::Controllers::LeftSidebarController *leftSidebarController READ leftSidebarController CONSTANT)
  Q_PROPERTY(ART::Logic::Scene3D *scene3D READ scene3D CONSTANT)
  Q_PROPERTY(ART::Logic::Scene2D *scene2D READ scene2D CONSTANT)

public:
  explicit MainController(QObject *parent = nullptr);
  ~MainController() = default;
  MainController(MainController &&other) = delete;
  MainController &operator=(MainController &&other) = delete;

  void setScene3D(Logic::Scene3D *scene) noexcept;
  void setScene2D(Logic::Scene2D *scene) noexcept;

public Q_SLOTS:
  ToolbarController *toolbarController() const noexcept;
  RightSidebarController *rightSidebarController() const noexcept;
  LeftSidebarController *leftSidebarController() const noexcept;
  Logic::Scene3D *scene3D() const noexcept;
  Logic::Scene2D *scene2D() const noexcept;

private:
  ToolbarController *_toolbarController{nullptr};
  RightSidebarController *_rightSidebarController{nullptr};
  LeftSidebarController *_leftSidebarController{nullptr};
  Logic::Scene3D *_scene3D{nullptr};
  Logic::Scene2D *_scene2D{nullptr};

private Q_SLOTS:
  void handleSaveFileClicked();
  void handleSaveAsFileClicked(const QUrl &url);
  void handleNewFileClicked();
  void handleimportImageClicked(const QUrl &url);
};

} // namespace Controllers
} // namespace ART
