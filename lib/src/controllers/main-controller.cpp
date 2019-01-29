#include "main-controller.hpp"
#include "menu-controller.hpp"

namespace ART {
namespace Controllers {

MainController::MainController(QObject* parent) :
  QObject{parent},
  menu_controller_{new MenuController{this}}
{
  connect(menu_controller_, &MenuController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(menu_controller_, &MenuController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(menu_controller_, &MenuController::newFileClicked, this, &MainController::handleNewFileClicked);
}

MenuController* MainController::menuController() const {
  return menu_controller_;
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
