#include "Scene3D.hpp"
#include "Material.hpp"
#include "Mesh.hpp"
#include "Transform.hpp"

#include <Qt3DExtras/QSkyboxEntity>

namespace ART {
namespace Logic {

Scene3D::Scene3D(Qt3DCore::QEntity *parent) : Qt3DCore::QEntity{parent} {

  // QString resPath{"../../ui-qml/mesh/powerup/"};

  // Qt3DCore::QEntity * powerUp = new Qt3DCore::QEntity(this);
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

  // Qt3DRender::QTextureLoader *ambientOcclusionLoader = new Qt3DRender::QTextureLoader(this);
  // ambientOcclusionLoader->setSource(QUrl::fromLocalFile(resPath + "ambientocclusion.png"));

  // Qt3DExtras::QMetalRoughMaterial *material = new Qt3DExtras::QMetalRoughMaterial();

  // material->setBaseColor(QVariant::fromValue(loader));
  // material->setMetalness(QVariant::fromValue(metalnessLoader));
  // material->setRoughness(QVariant::fromValue(roughnessLoader));
  // material->setNormal(QVariant::fromValue(normalLoader));
  // material->setAmbientOcclusion(QVariant::fromValue(ambientOcclusionLoader));

  // powerUp->addComponent(modelMesh);
  // powerUp->addComponent(material);

  Qt3DExtras::QSkyboxEntity * skybox = new Qt3DExtras::QSkyboxEntity(this);
  skybox->setBaseName("qrc:/skybox/wobbly_bridge_4k_cube_radiance");
  skybox->setExtension(".dds");
  skybox->setGammaCorrectEnabled(true);

  Qt3DCore::QEntity * envLightEntity = new Qt3DCore::QEntity(this);
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

  Qt3DRender::QEnvironmentLight * envLight = new Qt3DRender::QEnvironmentLight(envLightEntity);
  envLight->setIrradiance(envIrradiance);
  envLight->setSpecular(envSpecular);
  envLightEntity->addComponent(envLight);

  Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(this);
  Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(this);
  light->setColor("red");
  light->setIntensity(2.0);
  lightEntity->addComponent(light);
  Qt3DCore::QTransform *tr = new Qt3DCore::QTransform(lightEntity);
  tr->setTranslation({20, -10, 9});
  lightEntity->addComponent(tr);

  Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(this);
  Qt3DRender::QPointLight *light2 = new Qt3DRender::QPointLight(this);
  light2->setColor("white");
  light2->setIntensity(2.0);
  lightEntity2->addComponent(light2);
  Qt3DCore::QTransform *tr2 = new Qt3DCore::QTransform(lightEntity2);
  tr2->setTranslation({-20, 10, 9});
  lightEntity2->addComponent(tr2);
}

void Scene3D::createSphere() noexcept {
  // Qt3DCore::QEntity *sceneLoaderEntity = new Qt3DCore::QEntity(this);
  // sceneLoader = new Qt3DRender::QSceneLoader(sceneLoaderEntity);
  // // SceneWalker sceneWalker(sceneLoader);
  // QObject::connect(sceneLoader, &Qt3DRender::QSceneLoader::statusChanged, this, &Scene3D::status);
  // sceneLoaderEntity->addComponent(sceneLoader);

  // sceneLoader->setSource(QUrl::fromLocalFile(":/mesh/earth/Earth 2K.fbx"));

  std::unique_ptr<Sphere> sphere{std::make_unique<Sphere>("Sphere[0]", this)};
  auto &mesh = sphere->module<Modules::Mesh<Qt3DExtras::QSphereMesh>>("Mesh");
  mesh->setRadius(5);
  mesh->setSlices(100);
  mesh->setRings(100);

  auto *material = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*sphere, "MetalMaterial");
  auto *metal = material->get();
  metal->setBaseColor(QColor(125, 125, 125));
  metal->setRoughness(0.10);
  metal->setMetalness(0.95);

  // auto &transform = sphere->module<Modules::Transform>("Transform");
  // transform->setTranslation({0.0, 0.0, 0.0});
  

  // std::unique_ptr<Sphere> sphere2{std::make_unique<Sphere>("Sphere[1]", sphere.get())};
  // auto &mesh2 = sphere2->module<Modules::Mesh<Qt3DExtras::QSphereMesh>>("Mesh");
  // mesh2->setRadius(5);
  // mesh2->setSlices(100);
  // mesh2->setRings(100);

  // auto *material2 = new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*sphere2, "MetalMaterial");
  // auto *metal2 = material2->get();
  // metal2->setBaseColor(QColor(125, 125, 125));
  // metal2->setRoughness(0.10);
  // metal2->setMetalness(0.95);

  // auto &transform = sphere2->module<Modules::Transform>("Transform");
  // transform->setTranslation({15.0, 0.0, 0.0});
  // sphere->addChildren("Sphere[1]", std::move(sphere2));
  _entities.emplace("Sphere[0]", std::move(sphere));

  Q_EMIT sceneUpdate();
}

void Scene3D::removeSphere() noexcept {
  qInfo() << "Remove sphere";

  _entities.erase("Sphere[0]");
}

const std::unordered_map<std::string, std::unique_ptr<Entity>> &Scene3D::shapes() const noexcept {
  return _entities;
}

} // namespace Logic
} // namespace ART