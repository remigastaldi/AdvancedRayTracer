#include "MainController.hpp"
#include "LeftSidebarController.hpp"
#include "ToolbarController.hpp"
#include "RightSidebarController.hpp"
#include "RendererController.hpp"

#include <iostream>
namespace ART {
namespace Controllers {

MainController::MainController(QObject* parent) :
  QObject{parent},
  _toolbarController{new ToolbarController{this}},
  _leftSidebarController{new LeftSidebarController{this}},
  _rightSidebarController{new RightSidebarController{this}},
  _rendererController{nullptr}
{
  connect(_toolbarController, &ToolbarController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_toolbarController, &ToolbarController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_toolbarController, &ToolbarController::newFileClicked, this, &MainController::handleNewFileClicked);
}

void  MainController::setRendererController(RendererController *rendererController) noexcept {
  _rendererController = rendererController;
  connect(_rightSidebarController, &RightSidebarController::renderUpdate, _rendererController, &RendererController::update);
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

RendererController  *MainController::rendererController() const noexcept {
  return _rendererController;
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
