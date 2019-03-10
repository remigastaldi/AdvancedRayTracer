#include "MainController.hpp"
#include "ToolbarController.hpp"
#include "RightSidebarController.hpp"
#include "DrawToolbar3DController.hpp"
#include "DrawToolbar2DController.hpp"
#include "Scene3D.hpp"
#include "Scene2D.hpp"
#include "Outliner.hpp"
// #include "Entity.hpp"
// #include "Mesh.hpp"

#include "ZIndex.hpp"

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
  _outliner{nullptr},
  _currentScene{nullptr},
  _engine{nullptr}
{
  connect(_toolbarController, &ToolbarController::saveFileClicked, this, &MainController::handleSaveFileClicked);
  connect(_toolbarController, &ToolbarController::saveAsFileClicked, this, &MainController::handleSaveAsFileClicked);
  connect(_toolbarController, &ToolbarController::newFileClicked, this, &MainController::handleNewFileClicked);
  connect(_toolbarController, &ToolbarController::importImageClicked, this, &MainController::handleimportImageClicked);
}

void  MainController::setScene3D(Logic::Scene3D *scene) noexcept {
  _scene3D = scene;
  _currentScene = scene;
  connect(_scene3D, &Logic::Scene::sceneUpdate, this, &MainController::sceneUpdate);
  connect(_scene3D, &Logic::Scene::selectedShapeUpdate, this, &MainController::selectedShapeUpdate);
  connect(_drawToolbar3DController, &DrawToolbar3DController::createSphere, _scene3D, &Logic::Scene3D::createSphere);
  connect(_drawToolbar3DController, &DrawToolbar3DController::import3DModel, _scene3D, &Logic::Scene3D::import3DModel);
  connect(_drawToolbar3DController, &DrawToolbar3DController::import3DScene, _scene3D, &Logic::Scene3D::import3DScene);
}

void  MainController::setScene2D(Logic::Scene2D *scene) noexcept {
  _scene2D = scene;
  connect(_scene2D, &Logic::Scene::sceneUpdate, this, &MainController::sceneUpdate);
  connect(_scene2D, &Logic::Scene::selectedShapeUpdate, this, &MainController::selectedShapeUpdate);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createLine, _scene2D, &Logic::Scene2D::createLine);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createRectangle, _scene2D, &Logic::Scene2D::createRectangle);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createCircle, _scene2D, &Logic::Scene2D::createCircle);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createTriangle, _scene2D, &Logic::Scene2D::createTriangle);
  connect(_drawToolbar2DController, &DrawToolbar2DController::createPolygon, _scene2D, &Logic::Scene2D::createPolygon);
  connect(_drawToolbar2DController, &DrawToolbar2DController::cutImage, _scene2D, &Logic::Scene2D::cutImage);
  connect(_drawToolbar2DController, &DrawToolbar2DController::importImg, _scene2D, &Logic::Scene2D::importImg);
  connect(_drawToolbar2DController, &DrawToolbar2DController::saveScene, _scene2D, &Logic::Scene2D::saveScene);
}

ART::Models::Outliner *MainController::outliner() const noexcept {
  return _outliner;
}

void  MainController::setOutliner(ART::Models::Outliner *outliner) noexcept {
  _outliner = outliner;
}

void MainController::setEngine(QQmlApplicationEngine *engine) noexcept {
  _engine = engine;
}

void MainController::sceneUpdate() noexcept {
  _outliner->setEntities(_currentScene->entities());
  _outliner->dataUpdate();
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

void MainController::selectScene3D() {
  _currentScene = _scene3D;
  sceneUpdate();
  Q_EMIT updateUiModules();
}

void MainController::selectScene2D() {
  _currentScene = _scene2D;
  sceneUpdate();
  Q_EMIT updateUiModules();
}

QVariantList MainController::loadTree() {
  QVariantList list;
  if (_currentScene->selectedEntity() != nullptr) {
    for (const auto &shape : _currentScene->selectedEntity()->childrens()) {
      list.push_back(QString::fromStdString(shape.second->id()));
    }
  }
  return list;
}

// Init modules of entity to qml
void MainController::initEntityModulesModels() {
  if (_currentScene->selectedEntity() == nullptr)
    return;
  for (auto &module : _currentScene->selectedEntity()->childrens()) {
    _engine->rootContext()->setContextProperty(QString::fromStdString(module.first + "Model"), module.second.get());
  }
}

void MainController::updateCurrentScene() {
  if (_currentScene != nullptr) {
    _currentScene->update();
  }
}

void MainController::selectedShapeUpdate() {
  if (_currentScene != nullptr && _currentScene->selectedEntity() != nullptr) {
    _outliner->setSelectionEntity(_currentScene->selectedEntity()->id());
  }

  Q_EMIT updateUiModules();
}

// TODO: Remove this crappy function, bad dataflow
void MainController::selectEntityByIndex(int index) {
  if (_currentScene != nullptr) {
    _currentScene->selectEntity(_outliner->entitiesHierarchy()[static_cast<size_t>(index)]);
  }
}

} // namespace Controllers
} // namespace ART
