#include "TorusMesh.hpp"

namespace ART {
namespace Logic {
namespace Modules {

TorusMesh::TorusMesh(Shape3D &parent, std::string id, Qt3DExtras::QTorusMesh *mesh)
    : Mesh<Qt3DExtras::QTorusMesh>{parent, id, mesh} {};

TorusMesh::~TorusMesh() {}

float TorusMesh::minorRadius() { return 0; };
float TorusMesh::radius() { return 0; };
int TorusMesh::rings() { return 0; };
int TorusMesh::slices() { return 0; };

void TorusMesh::setMinorRadius(float minorRadius) noexcept{

};
void TorusMesh::setRadius(float radius) noexcept{

};
void TorusMesh::setRings(int rings) noexcept{

};
void TorusMesh::setSlices(int slices) noexcept{

};

} // namespace Modules
} // namespace Logic
} // namespace ART