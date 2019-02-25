#include "MainController.hpp"
#include "LeftSidebarController.hpp"
#include "ToolbarController.hpp"
#include "RightSidebarController.hpp"
#include "Scene3D.hpp"
#include "Scene2D.hpp"

namespace ART {
namespace Controllers {

MainController::MainController(QObject* parent) :
  QObject{parent},
  _toolbarController{new ToolbarController{this}},
  _rightSidebarController{new RightSidebarController{this}},
  _leftSidebarController{new LeftSidebarController{this}},
  _scene3D{nullptr},
  _scene2D{nullptr}
{
  // connect a sender which sends signals to a receiver (sender, sender signal name, receiver, receiver action)
  connect(_toolbarController, &ToolbarController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_toolbarController, &ToolbarController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_toolbarController, &ToolbarController::newFileClicked, this, &MainController::handleNewFileClicked);
  connect(_toolbarController, &ToolbarController::importImageClicked, this, &MainController::handleimportImageClicked);
}

void  MainController::setScene3D(Logic::Scene3D *scene) noexcept {
  _scene3D = scene;
  connect(_rightSidebarController, &RightSidebarController::createCubeEvent, _scene3D, &Logic::Scene3D::createSphere);
  connect(_rightSidebarController, &RightSidebarController::deleteShapeUpdate, _scene3D, &Logic::Scene3D::removeSphere);
}

void  MainController::setScene2D(Logic::Scene2D *scene) noexcept {
  _scene2D = scene;
}

ToolbarController* MainController::toolbarController() const noexcept {
  return _toolbarController;
}

RightSidebarController *MainController::rightSidebarController() const noexcept {
  return _rightSidebarController;
}

LeftSidebarController *MainController::leftSidebarController() const noexcept {
  return _leftSidebarController;
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
