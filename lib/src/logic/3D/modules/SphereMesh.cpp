#include "SphereMesh.hpp"

namespace ART {
namespace Logic {
namespace Modules {

SphereMesh::SphereMesh(Shape3D &parent, std::string id, Qt3DExtras::QSphereMesh *mesh)
    : Mesh<Qt3DExtras::QSphereMesh>{parent, id, mesh} {};

SphereMesh::~SphereMesh() {}

bool SphereMesh::generateTangents() { return get()->generateTangents(); };
float SphereMesh::radius() { return get()->radius(); };
int SphereMesh::rings() { return get()->rings(); };
int SphereMesh::slices() { return get()->slices(); };

void SphereMesh::setGenerateTangents(bool gen) noexcept { get()->setGenerateTangents(gen); };
void SphereMesh::setRadius(float radius) noexcept { get()->setRadius(radius); };
void SphereMesh::setRings(int rings) noexcept { get()->setRings(rings); };
void SphereMesh::setSlices(int slices) noexcept { get()->setSlices(slices); };

} // namespace Modules
} // namespace Logic
} // namespace ART