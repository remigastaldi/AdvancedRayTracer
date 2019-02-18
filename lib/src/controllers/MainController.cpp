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
  connect(_toolbarController, &ToolbarController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_toolbarController, &ToolbarController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_toolbarController, &ToolbarController::newFileClicked, this, &MainController::handleNewFileClicked);
}

void  MainController::setFbItem(Logic::FbItem *_fbItem) noexcept {
  _fbItem = _fbItem;
  connect(_rightSidebarController, &RightSidebarController::renderUpdate, _fbItem, &Logic::FbItem::test);
  connect(_rightSidebarController, &RightSidebarController::renderUpdate, _fbItem, &Logic::FbItem::update);
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

} // namespace Controllers
} // namespace ART
