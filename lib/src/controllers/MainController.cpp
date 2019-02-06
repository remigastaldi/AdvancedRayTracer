#include "MainController.hpp"
#include "ToolbarController.hpp"
#include "SidebarController.hpp"

namespace ART {
namespace Controllers {

MainController::MainController(QObject* parent) :
  QObject{parent},
  _menuController{new ToolbarController{this}},
  _sidebarController{new SidebarController{this}}
{
  connect(_menuController, &ToolbarController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_menuController, &ToolbarController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_menuController, &ToolbarController::newFileClicked, this, &MainController::handleNewFileClicked);
}

ToolbarController* MainController::menuController() const noexcept {
  return _menuController;
}

SidebarController *MainController::sidebarController() const noexcept {
  return _sidebarController;
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
