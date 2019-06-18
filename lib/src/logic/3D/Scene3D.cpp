
#include "Scene3D.hpp"
#include "Cuboid.hpp"
#include "CuboidMesh.hpp"
#include "LightEntity.hpp"
#include "Material.hpp"
#include "Mesh.hpp"
#include "MetalRoughMaterial.hpp"
#include "Object3D.hpp"
#include "Plane.hpp"
#include "PlaneMesh.hpp"
#include "RenderItem.hpp"
#include "SceneLoader.hpp"
#include "SphereMesh.hpp"
#include "Torus.hpp"
#include "TorusMesh.hpp"
#include "Transform3D.hpp"

#include "SpotLight.hpp"

#include <QGraphicsApiFilter>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <Qt3DExtras/QSkyboxEntity>
#include <QtConcurrent>

#include "Render.hpp"
#include <QQuickView>

namespace ART::Logic {

Scene3D::Scene3D(RootEntity *root)
    : _root{root}, _cameraController{new Controllers::CameraController{root}}, _urrId{0}, _paintedItem{nullptr} {
  connect(root, &RootEntity::keyPressedEvent, this, &Scene3D::keyPressedEvent);
  // connect(root, &RootEntity::cameraMoveEvent, this, &Scene3D::updateSkyboxPosition);

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

// _renderView{std::make_unique<QQuickView>()}

  // envLightEntity->addComponent(envLight);

  // Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(_root);
  // Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(_root);
  // light->setColor("red");
  // light->setIntensity(0.8);
  // lightEntity->addComponent(light);
  // Qt3DCore::QTransform *tr = new Qt3DCore::QTransform(lightEntity);
  // tr->setTranslation({0, 0, 100});
  // lightEntity->addComponent(tr);

  // // Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(_root);
  // // Qt3DRender::QSpotLight *light2 = new Qt3DRender::QSpotLight(_root);
  // // light2->setColor("blue");
  // // light2->setIntensity(1);
  // // light2->setLocalDirection({0, 0, 1});
  // // lightEntity2->addComponent(light2);
  // // Qt3DCore::QTransform *tr2 = new Qt3DCore::QTransform(lightEntity2);
  // // tr2->setTranslation({0, 0, -20});
  // // lightEntity2->addComponent(tr2);
}

Scene3D::~Scene3D() {
  if (_renderView != nullptr) {
    _renderView->close();
    _renderView->destroy();
    _renderView->deleteLater();
  }
};

void Scene3D::createLight() noexcept {
  std::string id = "Light [" + std::to_string(_urrId++) + "]";

  std::unique_ptr<LightEntity> lightEntity{std::make_unique<LightEntity>(id, _root)};
  auto *lightMesh = lightEntity->getChildren<Modules::SphereMesh>("Mesh").get();

  connect(lightEntity.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);
  _entities.emplace(id, std::move(lightEntity));

  Q_EMIT sceneUpdate();
}

void Scene3D::createSphere() noexcept {
  std::string id = "Sphere [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Sphere> sphere{std::make_unique<Sphere>(id, _root)};

  connect(sphere.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(sphere));

  Q_EMIT sceneUpdate();
}

void Scene3D::createTorus() noexcept {
  std::string id = "Torus [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Torus> torus{std::make_unique<Torus>(id, _root)};

  connect(torus.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(torus));

  Q_EMIT sceneUpdate();
}

void Scene3D::castRay() noexcept {


  // if (_cameraController->model() != nullptr) {
    // render.startRendering(_entities, _cameraController->model()->position());
  // } else {
  // }
  return;

  // render.startRendering(_entities, _cameraController->model()->position());
  // QImage image{":/skybox/skybox.jpg"};
  // int n = -1;
  // std::vector<Vec3f> envmap(image.width() * image.height());
  // envmap.reserve(image.width() * image.height());
  // envmap_width = image.width();
  // envmap_height = image.height();

  // uchar *pixmap = image.bits();
  // for (int j = image.height() - 1; j >= 0; j--) {
  //   for (int i = 0; i < image.width(); i++) {
  //     envmap[i + j * image.width()] =
  //         Vec3f(pixmap[(i + j * image.width()) * 3 + 0], pixmap[(i + j * image.width()) * 3 + 1],
  //               pixmap[(i + j * image.width()) * 3 + 2]) *
  //         (1 / 255.);
  //   }
  // }

  // CustomMaterial ivory(1.0, Vec4f(0.6, 0.3, 0.1, 0.0), Vec3f(0.4, 0.4, 0.3), 50.);
  // CustomMaterial glass(1.5, Vec4f(0.0, 0.5, 0.1, 0.8), Vec3f(0.6, 0.7, 0.8), 125.);
  // CustomMaterial red_rubber(1.0, Vec4f(0.9, 0.1, 0.0, 0.0), Vec3f(0.3, 0.1, 0.1), 10.);
  // CustomMaterial mirror(1.0, Vec4f(0.0, 10.0, 0.8, 0.0), Vec3f(1.0, 1.0, 1.0), 1425.);

  // std::vector<CustomSphere> spheres{{Vec3f(-3, 0, -16), 2, ivory},
  //                                   {Vec3f(-1.0, -1.5, -12), 2, glass},
  //                                   {Vec3f(1.5, -0.5, -18), 3, red_rubber},
  //                                   {Vec3f(7, 5, -18), 4, mirror}};

  // std::vector<CustomLight> lights{{Vec3f(-20, 20, 20), 1.5}, {Vec3f(30, 50, -25), 1.8}, {Vec3f(30, 20, 30), 1.7}};

  // render(spheres, lights);
  // float sphere_dist = std::numeric_limits<float>::max();
  // int i = 0;
  // std::string message = "The ray did not intersect with a shape.";
  // for (auto& it : _entities) {
  // 	QVector3D center(it.second.get()->getChildren<Modules::Transform3D>("Transform3D").x(),
  // it.second.get()->getChildren<Modules::Transform3D>("Transform3D").y(),
  // it.second.get()->getChildren<Modules::Transform3D>("Transform3D").z()); 	float radius =
  // it.second.get()->getChildren<Modules::SphereMesh>("SphereMesh").radius(); 	QVector3D direction; 	QVector3D
  // origin;

  // 	if (_cameraController->model() == nullptr) {
  // 		direction = QVector3D(0.707107, 0.0, -0.707107);
  // 		origin = QVector3D(-20.0, 0.0, 20.0);
  // 	} else {
  // 		direction = _cameraController->model()->viewVector().normalized();
  // 		origin = (_cameraController->model()->position());
  // 	}

  // 	if (rayIntersect(origin, direction, center, radius, sphere_dist)) {
  // 		message = "The ray intersected with the Sphere [" + std::to_string(i) + "].";
  // 		break;
  // 	}

  // 	i++;
  // }

  // const char *cmessage = message.c_str();
  // QMessageBox::information(
  // 	nullptr,
  // 	tr("Ray intersection result"),
  // 	tr(cmessage));

  // Q_EMIT sceneUpdate();
}

void Scene3D::raytracingReflection() noexcept { qInfo() << "ok"; }

bool Scene3D::rayIntersect(const QVector3D origin, const QVector3D direction, QVector3D center, float radius,
                           float &t0) {
  QVector3D L = center - origin;
  float tca = QVector3D::dotProduct(L, direction);
  float d2 = QVector3D::dotProduct(L, L) - (tca * tca);

  if (d2 > (radius * radius)) {
    qInfo() << "false";
    return false;
  }

  float thc = sqrtf((radius * radius) - d2);
  t0 = tca - thc;
  float t1 = tca + thc;

  if (t0 < 0) {
    t0 = t1;
  }

  if (t0 < 0) {
    qInfo() << "false";
    return false;
  }
  qInfo() << "true";
  return true;
}

void Scene3D::createCube() noexcept {
  std::string id = "Cuboid [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Cuboid> square{std::make_unique<Cuboid>(id, _root)};

  connect(square.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(square));

  Q_EMIT sceneUpdate();
}

void Scene3D::createPlane() noexcept {
  std::string id = "Plane [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Plane> plane{std::make_unique<Plane>(id, _root)};

  connect(plane.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(plane));

  Q_EMIT sceneUpdate();
}

void Scene3D::import3DModel(const QUrl &url) {
  std::string id = "Model [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<Object3D> object3D{std::make_unique<Object3D>(id, _root)};
  auto mesh = object3D->getChildren<Modules::Mesh<Qt3DRender::QMesh>>("Mesh").get();
  // Qt3DCore::QEntity *model3D = new Qt3DCore::QEntity(_root);
  // Qt3DRender::QMesh *modelMesh = new Qt3DRender::QMesh();
  mesh->setSource(QUrl::fromLocalFile(url.path()));

  connect(object3D.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  _entities.emplace(id, std::move(object3D));
  Q_EMIT sceneUpdate();
}

void Scene3D::import3DScene(const QUrl &url) {
  std::string id = "Scene3D [" + std::to_string(_urrId++) + "]";
  std::unique_ptr<SceneLoader> sceneLoader{std::make_unique<SceneLoader>(id, _root)};
  // QObject::connect(sceneLoader, &Qt3DRender::QSceneLoader::statusChanged, _root, &Scene3D::status);
  auto scene = sceneLoader->getChildren<Modules::Mesh<Qt3DRender::QSceneLoader>>("Mesh").get();
  scene->setSource(QUrl::fromLocalFile(url.path()));
  _entities.emplace(id, std::move(sceneLoader));

  connect(sceneLoader.get(), &Shape3D::entitySelectedChanged, this, &Scene3D::selectEntity);

  Q_EMIT sceneUpdate();
}

void Scene3D::render() noexcept {
  Render render;
  render.startRendering(_entities,  QVector3D{0,0,0});
  // _renderView->show();
  // _paintedItem = _engine->rootObjects().first()->findChild<RenderItem *>("renderPainter");
  // if (_paintedItem != nullptr) {
    // _paintedItem->startRendering(_entities, QVector3D{0,0,0});
    // _paintedItem->QQuickItem::update();
  // } else {
    qInfo() << "NULL";
  // }
}

void Scene3D::setEngine(QQmlApplicationEngine *engine) {
  _engine = engine;
  _renderView = std::make_unique<QQuickView>(_engine, nullptr);
  _renderView->setSource(QUrl(QStringLiteral("qrc:/views/RenderView.qml")));
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