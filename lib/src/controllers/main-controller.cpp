#include "main-controller.hpp"
#include "menu-controller.hpp"
#include "SidebarController.hpp"

namespace ART {
namespace Controllers {

MainController::MainController(QObject* parent) :
  QObject{parent},
  _menuController{new MenuController{this}},
  _sidebarController{new SidebarController{this}}
{
  connect(_menuController, &MenuController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_menuController, &MenuController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_menuController, &MenuController::newFileClicked, this, &MainController::handleNewFileClicked);
}

MenuController* MainController::menuController() const noexcept {
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
