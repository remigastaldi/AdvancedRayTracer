#include "ConeMesh.hpp"

namespace ART {
namespace Logic {
namespace Modules {

ConeMesh::ConeMesh(Shape3D &parent, std::string id)
    : Mesh<Qt3DExtras::QConeMesh>{parent, id} {
  get()->setTopRadius(6);
  get()->setTopRadius(3);
  get()->setLength(5);
  get()->setSlices(50);
  get()->setRings(100);
};

ConeMesh::~ConeMesh() {}

float ConeMesh::length() { return get()->length(); };
float ConeMesh::topRadius() { return get()->topRadius(); };
float ConeMesh::bottomRadius() { return get()->bottomRadius(); };
int ConeMesh::rings() { return get()->rings(); };
int ConeMesh::slices() { return get()->slices(); };

void ConeMesh::setLength(float length) noexcept { get()->setLength(length); };
void ConeMesh::setTopRadius(float radius) noexcept { get()->setTopRadius(radius); };
void ConeMesh::setBottomRadius(float radius) noexcept { get()->setBottomRadius(radius); };
void ConeMesh::setRings(int rings) noexcept { get()->setRings(rings); };
void ConeMesh::setSlices(int slices) noexcept { get()->setSlices(slices); };

} // namespace Modules
} // namespace Logic
} // namespace ART