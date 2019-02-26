#include "Scene3D.hpp"

namespace ART {
namespace Logic {

Scene3D::Scene3D(Qt3DCore::QEntity *parent) : Qt3DCore::QEntity{parent} {

  // Torus
  Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(this);
  Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh(torusEntity);
  Qt3DRender::QMaterial *materialw = new Qt3DExtras::QDiffuseSpecularMaterial(torusEntity);
  torusMesh->setRadius(8);
  torusMesh->setMinorRadius(1);
  torusMesh->setRings(100);
  torusMesh->setSlices(100);
  torusEntity->addComponent(torusMesh);
  torusEntity->addComponent(materialw);

  Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(this);
  Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(this);
  light->setColor("red");
  light->setIntensity(1.0);
  lightEntity->addComponent(light);
  Qt3DCore::QTransform *tr = new Qt3DCore::QTransform();
  tr->setTranslation({20, -10, 9});
  lightEntity->addComponent(tr);

  Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(this);
  Qt3DRender::QPointLight *light2 = new Qt3DRender::QPointLight(this);
  light2->setColor("yellow");
  light2->setIntensity(1.0);
  lightEntity2->addComponent(light2);
  Qt3DCore::QTransform *tr2 = new Qt3DCore::QTransform();
  tr2->setTranslation({-20, 10, 9});
  lightEntity2->addComponent(tr2);
}

void Scene3D::createSphere() noexcept {
  qInfo() << "Add sphere";
  std::unique_ptr<Sphere> sphere{std::make_unique<Sphere>(this)};

  auto mesh = sphere->mesh<Qt3DExtras::QSphereMesh>();
  mesh->setRadius(5);
  mesh->setSlices(100);

  _entities.emplace("Sphere[0]", std::move(sphere));
}

void Scene3D::removeSphere() noexcept {
  qInfo() << "Remove sphere";

  _entities.erase("Sphere[0]");
}

} // namespace Logic
} // namespace ART