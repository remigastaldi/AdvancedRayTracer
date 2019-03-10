
#include "Scene3D.hpp"
#include "Material.hpp"
#include "Mesh.hpp"
#include "Object3D.hpp"
#include "SceneLoader.hpp"
#include "Square.hpp"
#include "Transform3D.hpp"

#include <Qt3DExtras/QSkyboxEntity>

namespace ART {
namespace Logic {

Scene3D::Scene3D(RootEntity *root) : _root{root} {
  connect(root, &RootEntity::keyPressedEvent, this, &Scene3D::keyPressedEvent);
  // QString resPath{"../../ui-qml/mesh/powerup/"};

  // Qt3DCore::QEntity * powerUp = new Qt3DCore::QEntity(_root);
  // Qt3DRender::QMesh * modelMesh = new Qt3DRender::QMesh();
  // modelMesh->setSource(QUrl::fromLocalFile(resPath + "powerup.obj"));

  // Qt3DRender::QTextureLoader *loader = new Qt3DRender::QTextureLoader(powerUp);
  // loader->setSource(QUrl::fromLocalFile(resPath + "basecolor.png"));
  // loader->setFormat(Qt3DRender::QAbstractTexture::SRGB8_Alpha8);

  // Qt3DRender::QTextureLoader *metalnessLoader = new Qt3DRender::QTextureLoader(powerUp);
  // metalnessLoader->setSource(QUrl::fromLocalFile(resPath + "metalness.png"));

  // Qt3DRender::QTextureLoader *roughnessLoader = new Qt3DRender::QTextureLoader(powerUp);
  // roughnessLoader->setSource(QUrl::fromLocalFile(resPath + "roughness.png"));

  // Qt3DRender::QTextureLoader *normalLoader = new Qt3DRender::QTextureLoader(powerUp);
  // normalLoader->setSource(QUrl::fromLocalFile(resPath + "normal.png"));

  // Qt3DRender::QTextureLoader *ambientOcclusionLoader = new Qt3DRender::QTextureLoader(_root);
  // ambientOcclusionLoader->setSource(QUrl::fromLocalFile(resPath + "ambientocclusion.png"));

  // Qt3DExtras::QMetalRoughMaterial *material = new Qt3DExtras::QMetalRoughMaterial();

  // material->setBaseColor(QVariant::fromValue(loader));
  // material->setMetalness(QVariant::fromValue(metalnessLoader));
  // material->setRoughness(QVariant::fromValue(roughnessLoader));
  // material->setNormal(QVariant::fromValue(normalLoader));
  // material->setAmbientOcclusion(QVariant::fromValue(ambientOcclusionLoader));

  // powerUp->addComponent(modelMesh);
  // powerUp->addComponent(material);

  Qt3DExtras::QSkyboxEntity *skybox = new Qt3DExtras::QSkyboxEntity(_root);
  skybox->setBaseName("qrc:/skybox/wobbly_bridge_4k_cube_radiance");
  skybox->setExtension(".dds");
  skybox->setGammaCorrectEnabled(true);

  Qt3DCore::QEntity *envLightEntity = new Qt3DCore::QEntity(_root);
  Qt3DRender::QTextureLoader *envIrradiance = new Qt3DRender::QTextureLoader(envLightEntity);
  envIrradiance->setSource(QUrl::fromLocalFile(":/skybox/wobbly_bridge_4k_cube_irradiance.dds"));
  envIrradiance->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
  envIrradiance->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
  Qt3DRender::QTextureWrapMode wrap(Qt3DRender::QTextureWrapMode::ClampToEdge, envIrradiance);
  envIrradiance->setWrapMode(wrap);
  envIrradiance->setGenerateMipMaps(false);

  Qt3DRender::QTextureLoader *envSpecular = new Qt3DRender::QTextureLoader(envLightEntity);
  envSpecular->setSource(QUrl::fromLocalFile(":/skybox/wobbly_bridge_4k_cube_specular.dds"));
  envSpecular->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
  envSpecular->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
  Qt3DRender::QTextureWrapMode wrapSpecular(Qt3DRender::QTextureWrapMode::ClampToEdge, envIrradiance);
  envSpecular->setWrapMode(wrap);
  envSpecular->setGenerateMipMaps(false);

  Qt3DRender::QEnvironmentLight *envLight = new Qt3DRender::QEnvironmentLight(envLightEntity);
  envLight->setIrradiance(envIrradiance);
  envLight->setSpecular(envSpecular);
  envLightEntity->addComponent(envLight);

  Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(_root);
  Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(_root);
  light->setColor("red");
  light->setIntensity(2);
  lightEntity->addComponent(light);
  Qt3DCore::QTransform *tr = new Qt3DCore::QTransform(lightEntity);
  tr->setTranslation({20, -10, 9});
  lightEntity->addComponent(tr);

  Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(_root);
  Qt3DRender::QPointLight *light2 = new Qt3DRender::QPointLight(_root);
  light2->setColor("white");
  light2->setIntensity(2);
  lightEntity2->addComponent(light2);
  Qt3DCore::QTransform *tr2 = new Qt3DCore::QTransform(lightEntity2);
  tr2->setTranslation({-20, 10, 9});
  lightEntity2->addComponent(tr2);
}

void Scene3D::createSphere() noexcept {
  // Qt3DCore::QEntity *sceneLoaderEntity = new Qt3DCore::QEntity(_root);
  // sceneLoader = new Qt3DRender::QSceneLoader(sceneLoaderEntity);
  // // SceneWalker sceneWalker(sceneLoader);
  // QObject::connect(sceneLoader, &Qt3DRender::QSceneLoader::statusChanged, _root, &Scene3D::status);
  // sceneLoaderEntity->addComponent(sceneLoader);

  // sceneLoader->setSource(QUrl::fromLocalFile(":/mesh/earth/Earth 2K.fbx"));

  std::unique_ptr<Sphere> sphere{std::make_unique<Sphere>("Sphere[0]", _root)};
  auto &mesh = sphere->getChildren<Modules::Mesh<Qt3DExtras::QSphereMesh>>("Mesh");
  mesh->setRadius(5);
  mesh->setSlices(100);
  mesh->setRings(100);

  sphere->removeChildren("Material");
  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*sphere, "MetalMaterial");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  connect(sphere.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace("Sphere[0]", std::move(sphere));

  // std::unique_ptr<Sphere> sphere2{std::make_unique<Sphere>("Sphere[1]",
  // static_cast<Qt3DCore::QEntity*>(sphere->getQEntity()))}; auto &mesh2 =
  // sphere2->getChildren<Modules::Mesh<Qt3DExtras::QSphereMesh>>("Mesh"); mesh2->setRadius(5); mesh2->setSlices(100);
  // mesh2->setRings(100);

  // auto *material2 = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*sphere2, "MetalMaterial");
  // auto *metal2 = material2->get();
  // metal2->setBaseColor(QColor(125, 125, 125));
  // metal2->setRoughness(0.10);
  // metal2->setMetalness(0.95);

  // auto &transform2 = sphere2->getChildren<Modules::Transform3D>("Transform3D");
  // transform2->setTranslation({15, 0, 0});
  // sphere->addChildren("Sphere[1]", std::move(sphere2));

  Q_EMIT sceneUpdate();
}

void Scene3D::removeSphere() noexcept {
  qInfo() << "Remove sphere";

  _entities.erase("Sphere[0]");
}

void Scene3D::createSquare() noexcept {
  std::unique_ptr<Square> square{std::make_unique<Square>("Square[0]", _root)};
  auto &mesh = square->getChildren<Modules::Mesh<Qt3DExtras::QCuboidMesh>>("Mesh");
  mesh->setXExtent(2);
  mesh->setYExtent(2);
  mesh->setZExtent(2);


  square->removeChildren("Material");
  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*square, "MetalMaterial");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  connect(square.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace("Square[0]", std::move(square));

  Q_EMIT sceneUpdate();
}

void Scene3D::import3DModel(const QUrl &url) {

  std::unique_ptr<Object3D> object3D{std::make_unique<Object3D>("Object3D[0]", _root)};
  auto &mesh = object3D->getChildren<Modules::Mesh<Qt3DRender::QMesh>>("Mesh");
  // Qt3DCore::QEntity *model3D = new Qt3DCore::QEntity(_root);
  // Qt3DRender::QMesh *modelMesh = new Qt3DRender::QMesh();
  mesh->setSource(QUrl::fromLocalFile(url.path()));

  object3D->removeChildren("Material");
  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*object3D, "MetalMaterial");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  _entities.emplace("Object3D[0]", std::move(object3D));
  Q_EMIT sceneUpdate();
}

void Scene3D::import3DScene(const QUrl &url) {
  qInfo() << url;
  std::unique_ptr<SceneLoader> sceneLoader{std::make_unique<SceneLoader>("Scene3D[0]", _root)};
  // QObject::connect(sceneLoader, &Qt3DRender::QSceneLoader::statusChanged, _root, &Scene3D::status);
  auto &scene = sceneLoader->getChildren<Modules::Mesh<Qt3DRender::QSceneLoader>>("Mesh");
  scene->setSource(QUrl::fromLocalFile(url.path()));
  _entities.emplace("Scene3D[0]", std::move(sceneLoader));

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
  default:
    break;
  }
}

} // namespace Logic
} // namespace ART