#include "SceneLoader.hpp"
#include "Material.hpp"
#include "Mesh.hpp"

namespace ART {
namespace Logic {

SceneLoader::SceneLoader(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*this, "Material");
  new Modules::Mesh<Qt3DRender::QSceneLoader>(*this, "Mesh");
}

} // namespace Logic
} // namespace ART