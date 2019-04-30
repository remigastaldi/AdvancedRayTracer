#include "PlaneMesh.hpp"

namespace ART::Logic::Modules {

PlaneMesh::PlaneMesh(Shape3D &parent, std::string id, Qt3DExtras::QPlaneMesh *mesh)
    : Mesh<Qt3DExtras::QPlaneMesh>{parent, id, mesh} {
  mesh->setWidth(100);
  mesh->setHeight(100);
  mesh->setMeshResolution(QSize{100,100});
}

float PlaneMesh::width() noexcept {
  return get()->width();
}

float PlaneMesh::height() noexcept {
  return get()->height();
}

void PlaneMesh::setWidth(float width) noexcept {
  get()->setWidth(width);
}

void PlaneMesh::setHeight(float height) noexcept {
  get()->setHeight(height);
}

} // namespace ART::Logic::Modules
