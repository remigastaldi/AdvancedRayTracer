#include "TorusMesh.hpp"

namespace ART {
namespace Logic {
namespace Modules {

TorusMesh::TorusMesh(Shape3D &parent, std::string id, Qt3DExtras::QTorusMesh *mesh)
    : Mesh<Qt3DExtras::QTorusMesh>{parent, id, mesh} {};

TorusMesh::~TorusMesh() {}

float TorusMesh::minorRadius() { return get()->minorRadius(); };
float TorusMesh::radius() { return get()->radius(); };
int TorusMesh::rings() { return get()->rings(); };
int TorusMesh::slices() { return get()->slices(); };

void TorusMesh::setMinorRadius(float minorRadius) noexcept { get()->setMinorRadius(minorRadius); };
void TorusMesh::setRadius(float radius) noexcept { get()->setRadius(radius); };
void TorusMesh::setRings(int rings) noexcept { get()->setRings(rings); };
void TorusMesh::setSlices(int slices) noexcept { get()->setSlices(slices); };

} // namespace Modules
} // namespace Logic
} // namespace ART