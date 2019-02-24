#include "MainController.hpp"
#include "LeftSidebarController.hpp"
#include "ToolbarController.hpp"
#include "RightSidebarController.hpp"
#include "FbItem.hpp"

namespace ART {
namespace Controllers {

MainController::MainController(QObject* parent) :
  QObject{parent},
  _toolbarController{new ToolbarController{this}},
  _leftSidebarController{new LeftSidebarController{this}},
  _rightSidebarController{new RightSidebarController{this}},
  _fbItem{nullptr}
{
  // connect a sender which sends signals to a receiver (sender, sender signal name, receiver, receiver action)
  connect(_toolbarController, &ToolbarController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_toolbarController, &ToolbarController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_toolbarController, &ToolbarController::newFileClicked, this, &MainController::handleNewFileClicked);
  connect(_toolbarController, &ToolbarController::importImageClicked, this, &MainController::handleimportImageClicked);
}

void  MainController::setFbItem(Logic::FbItem *_fbItem) noexcept {
  _fbItem = _fbItem;
  connect(_rightSidebarController, &RightSidebarController::renderUpdate, _fbItem, &Logic::FbItem::update);
  connect(_rightSidebarController, &RightSidebarController::renderRateUpdate, _fbItem, &Logic::FbItem::setAutoRenderRate);
  connect(_rightSidebarController, &RightSidebarController::deleteShapeUpdate, _fbItem, &Logic::FbItem::deleteShape);
  connect(_rightSidebarController, &RightSidebarController::createCubeEvent, _fbItem, &Logic::FbItem::createCube);
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

Logic::FbItem  *MainController::fbItem() const noexcept {
  return _fbItem;
}

void MainController::handleSaveFileClicked() {
}

void MainController::handleSaveAsFileClicked(const QUrl& url) {
  (void) url;
}

void MainController::handleNewFileClicked() {
}

void MainController::handleimportImageClicked(const QUrl& url) {
	qInfo() << url.path();
}

} // namespace Controllers
} // namespace ART
