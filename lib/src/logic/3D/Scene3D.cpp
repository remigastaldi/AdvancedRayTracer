
#include "Scene3D.hpp"
#include "Material.hpp"
#include "Mesh.hpp"
#include "Object3D.hpp"
#include "SceneLoader.hpp"
#include "Square.hpp"
#include "Torus.hpp"
#include "Transform3D.hpp"

#include <QPropertyAnimation>
#include <Qt3DExtras/QSkyboxEntity>
#include <QtConcurrent>

namespace ART::Logic {

Scene3D::Scene3D(RootEntity *root) : _root{root}, _urrId{0} {
  connect(root, &RootEntity::keyPressedEvent, this, &Scene3D::keyPressedEvent);
  connect(root, &RootEntity::cameraMoveEvent, this, &Scene3D::updateSkyboxPosition);


  // camera

  // Qt3DCore::QEntity *test = new Qt3DCore::QEntity{_root};
  // Qt3DExtras::QSkyboxEntity *skybox = new Qt3DExtras::QSkyboxEntity(_root);
  // skybox->setBaseName("qrc:/skybox/wobbly_bridge_4k_cube_radiance");
  // skybox->setExtension(".dds");
  // skybox->setGammaCorrectEnabled(true);
  // _skyboxPos = new Qt3DCore::QTransform{test};
  // _skyboxPos->setTranslation({0,0,0});
  // test->addComponent(_skyboxPos);

  // Qt3DCore::QEntity *envLightEntity = new Qt3DCore::QEntity(_root);
  Qt3DRender::QTextureLoader *envIrradiance = new Qt3DRender::QTextureLoader(_root);
  envIrradiance->setSource(QUrl::fromLocalFile(":/skybox/output_iem.dds"));
  envIrradiance->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
  envIrradiance->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
  Qt3DRender::QTextureWrapMode wrap(Qt3DRender::QTextureWrapMode::ClampToEdge, envIrradiance);
  envIrradiance->setWrapMode(wrap);
  envIrradiance->setGenerateMipMaps(false);

  Qt3DRender::QTextureLoader *envSpecular = new Qt3DRender::QTextureLoader(_root);
  envSpecular->setSource(QUrl::fromLocalFile(":/skybox/output_pmrem.dds"));
  envSpecular->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
  envSpecular->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
  Qt3DRender::QTextureWrapMode wrapSpecular(Qt3DRender::QTextureWrapMode::ClampToEdge, envSpecular);
  envSpecular->setWrapMode(wrapSpecular);
  envSpecular->setGenerateMipMaps(false);

  Qt3DRender::QEnvironmentLight *envLight = new Qt3DRender::QEnvironmentLight(_root);
  envLight->setIrradiance(envIrradiance);
  envLight->setSpecular(envSpecular);
  _root->addComponent(envLight);
  // envLightEntity->addComponent(envLight);

  Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(_root);
  Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(_root);
  light->setColor("red");
  light->setIntensity(0.8);
  lightEntity->addComponent(light);
  Qt3DCore::QTransform *tr = new Qt3DCore::QTransform(lightEntity);
  tr->setTranslation({0, 0, 100});
  lightEntity->addComponent(tr);

  Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(_root);
  Qt3DRender::QSpotLight *light2 = new Qt3DRender::QSpotLight(_root);
  light2->setColor("blue");
  light2->setIntensity(1);
  light2->setLocalDirection({0, 0, 1});
  lightEntity2->addComponent(light2);
  Qt3DCore::QTransform *tr2 = new Qt3DCore::QTransform(lightEntity2);
  tr2->setTranslation({0, 0, -20});
  lightEntity2->addComponent(tr2);
}

void Scene3D::createSphere() noexcept {
  std::string id = "Sphere [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Sphere> sphere{std::make_unique<Sphere>(id, _root)};
  auto &mesh = sphere->getChildren<Modules::Mesh<Qt3DExtras::QSphereMesh>>("Mesh");
  mesh->setRadius(2);
  mesh->setSlices(100);
  mesh->setRings(100);

  sphere->removeChildren("Material");
  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*sphere, "Material");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  connect(sphere.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(sphere));

  Q_EMIT sceneUpdate();
}

void Scene3D::createTorus() noexcept {
  std::string id = "Torus [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Torus> torus{std::make_unique<Torus>(id, _root)};
  auto &mesh = torus->getChildren<Modules::Mesh<Qt3DExtras::QTorusMesh>>("Mesh");
  mesh->setRadius(5);
  mesh->setSlices(100);
  mesh->setRings(100);

  torus->removeChildren("Material");
  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*torus, "Material");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  connect(torus.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(torus));

  Q_EMIT sceneUpdate();
}

void Scene3D::createSquare() noexcept {
  std::string id = "Square [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Square> square{std::make_unique<Square>(id, _root)};
  auto &mesh = square->getChildren<Modules::Mesh<Qt3DExtras::QCuboidMesh>>("Mesh");
  mesh->setXExtent(2);
  mesh->setYExtent(2);
  mesh->setZExtent(2);

  square->removeChildren("Material");
  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*square, "Material");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  connect(square.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(square));

  Q_EMIT sceneUpdate();
}

void Scene3D::import3DModel(const QUrl &url) {
  std::string id = "Model [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Object3D> object3D{std::make_unique<Object3D>(id, _root)};
  auto &mesh = object3D->getChildren<Modules::Mesh<Qt3DRender::QMesh>>("Mesh");
  // Qt3DCore::QEntity *model3D = new Qt3DCore::QEntity(_root);
  // Qt3DRender::QMesh *modelMesh = new Qt3DRender::QMesh();
  mesh->setSource(QUrl::fromLocalFile(url.path()));

  object3D->removeChildren("Material");
  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*object3D, "Material");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  connect(object3D.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(object3D));
  Q_EMIT sceneUpdate();
}

void Scene3D::import3DScene(const QUrl &url) {
  std::string id = "Scene3D [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<SceneLoader> sceneLoader{std::make_unique<SceneLoader>(id, _root)};
  // QObject::connect(sceneLoader, &Qt3DRender::QSceneLoader::statusChanged, _root, &Scene3D::status);
  auto &scene = sceneLoader->getChildren<Modules::Mesh<Qt3DRender::QSceneLoader>>("Mesh");
  scene->setSource(QUrl::fromLocalFile(url.path()));
  _entities.emplace(id, std::move(sceneLoader));

  connect(sceneLoader.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  Q_EMIT sceneUpdate();
}

const std::unordered_map<std::string, std::unique_ptr<Entity>> &Scene3D::entities() const noexcept { return _entities; }

Entity *Scene3D::selectedEntity() const noexcept {
  if (_selectedEntity.empty()) {
    return nullptr;
  }
  return _entities.at(_selectedEntity).get();
}

void Scene3D::selectEntity(const std::string &id) noexcept {
  _selectedEntity = id;
  Q_EMIT selectedShapeUpdate();
}

void Scene3D::keyPressedEvent(Qt::Key event) {
  switch (event) {
  case Qt::Key_W:
    if (selectedEntity() != nullptr) {
      auto &transform = selectedEntity()->getChildren<Modules::Transform3D>("Transform3D");
      transform.setZ(transform.z() + 1);
    }
    break;
  case Qt::Key_A:
    if (selectedEntity() != nullptr) {
      auto &transform = selectedEntity()->getChildren<Modules::Transform3D>("Transform3D");
      transform.setX(transform.x() - 1);
    }
    break;
  case Qt::Key_S:
    if (selectedEntity() != nullptr) {
      auto &transform = selectedEntity()->getChildren<Modules::Transform3D>("Transform3D");
      transform.setZ(transform.z() - 1);
    }
    break;
  case Qt::Key_D:
    if (selectedEntity() != nullptr) {
      auto &transform = selectedEntity()->getChildren<Modules::Transform3D>("Transform3D");
      transform.setX(transform.x() + 1);
    }
    break;
  case Qt::Key_E:
    if (selectedEntity() != nullptr) {
      auto &transform = selectedEntity()->getChildren<Modules::Transform3D>("Transform3D");
      transform.setY(transform.y() + 1);
    }
    break;
  case Qt::Key_R:
    if (selectedEntity() != nullptr) {
      auto &transform = selectedEntity()->getChildren<Modules::Transform3D>("Transform3D");
      transform.setY(transform.y() - 1);
    }
    break;
  case Qt::Key_Delete:
    if (selectedEntity() != nullptr) {
      _entities.erase(_selectedEntity);
      _selectedEntity = "";
      Q_EMIT sceneUpdate();
      Q_EMIT selectedShapeUpdate();
    }
    break;
  default:
    break;
  }
}

} // namespace ART::Logic