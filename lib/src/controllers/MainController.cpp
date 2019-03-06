#include "MainController.hpp"
#include "ToolbarController.hpp"
#include "RightSidebarController.hpp"
#include "DrawToolbar3DController.hpp"
#include "DrawToolbar2DController.hpp"
#include "Scene3D.hpp"
#include "Scene2D.hpp"
// #include "Outliner.hpp"

namespace ART {
namespace Controllers {

MainController::MainController(QObject* parent) :
  QObject{parent},
  _drawToolbar3DController{new DrawToolbar3DController{this}},
  _drawToolbar2DController{new DrawToolbar2DController{this}},
  _toolbarController{new ToolbarController{this}},
  _rightSidebarController{new RightSidebarController{this}},
  _scene3D{nullptr},
  _scene2D{nullptr},
  _outliner{nullptr}
{
  connect(_toolbarController, &ToolbarController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_toolbarController, &ToolbarController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_toolbarController, &ToolbarController::newFileClicked, this, &MainController::handleNewFileClicked);
  connect(_toolbarController, &ToolbarController::importImageClicked, this, &MainController::handleimportImageClicked);
}

void  MainController::setScene3D(Logic::Scene3D *scene) noexcept {
  _scene3D = scene;
  connect(_drawToolbar3DController, &DrawToolbar3DController::createSphere, _scene3D, &Logic::Scene3D::createSphere);
  connect(_scene3D, &Logic::Scene3D::sceneUpdate, this, &MainController::sceneUpdate);
  // connect(_rightSidebarController, &RightSidebarController::test, _scene3D, &Logic::Scene3D::test);
}

void  MainController::setScene2D(Logic::Scene2D *scene) noexcept {
  _scene2D = scene;
  connect(_drawToolbar2DController, &DrawToolbar2DController::createLine, _scene2D, &Logic::Scene2D::createLine);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createRectangle, _scene2D, &Logic::Scene2D::createRectangle);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createCircle, _scene2D, &Logic::Scene2D::createCircle);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createTriangle, _scene2D, &Logic::Scene2D::createTriangle);
  connect(_drawToolbar2DController, &DrawToolbar2DController::importImg, _scene2D, &Logic::Scene2D::importImg);
  connect(_drawToolbar2DController, &DrawToolbar2DController::saveScene, _scene2D, &Logic::Scene2D::saveScene);
}

void  MainController::setOutliner(ART::Models::Outliner *outliner) noexcept {
  _outliner = outliner;
}

void MainController::sceneUpdate() noexcept {
  _outliner->setEntities(_scene3D->entities());
}

ToolbarController* MainController::toolbarController() const noexcept {
  return _toolbarController;
}

RightSidebarController *MainController::rightSidebarController() const noexcept {
  return _rightSidebarController;
}

DrawToolbar3DController *MainController::drawToolbar3DController() const noexcept {
  return _drawToolbar3DController;
}

DrawToolbar2DController *MainController::drawToolbar2DController() const noexcept {
  return _drawToolbar2DController;
}

Logic::Scene3D  *MainController::scene3D() const noexcept {
  return _scene3D;
}

Logic::Scene2D  *MainController::scene2D() const noexcept {
  return _scene2D;
}

void MainController::handleSaveFileClicked() {
}

void MainController::handleSaveAsFileClicked(const QUrl& url) {
  (void) url;
}

void MainController::handleNewFileClicked() {
}

void MainController::handleimportImageClicked(const QUrl& url) {
	// qInfo() << url.path();
}

} // namespace Controllers
} // namespace ART
