#include "CuboidMesh.hpp"

namespace ART {
namespace Logic {
namespace Modules {

CuboidMesh::CuboidMesh(Shape3D &parent, std::string id, Qt3DExtras::QCuboidMesh *mesh)
    : Mesh<Qt3DExtras::QCuboidMesh>{parent, id, mesh} {};

CuboidMesh::~CuboidMesh() {}

float CuboidMesh::xExtent() { return get()->xExtent(); }
float CuboidMesh::yExtent() { return get()->yExtent(); }
float CuboidMesh::zExtent() { return get()->zExtent(); }
QSize CuboidMesh::xyMeshResolution() { return get()->xyMeshResolution(); }
QSize CuboidMesh::xzMeshResolution() { return get()->xzMeshResolution(); }
QSize CuboidMesh::yzMeshResolution() { return get()->yzMeshResolution(); }

void CuboidMesh::setXExtent(float xExtent) noexcept { get()->setXExtent(xExtent); }
void CuboidMesh::setYExtent(float yExtent) noexcept { get()->setYExtent(yExtent); }
void CuboidMesh::setZExtent(float zExtent) noexcept { get()->setZExtent(zExtent); }
void CuboidMesh::setXYMeshResolution(const QSize &resolution) noexcept { get()->setXYMeshResolution(resolution); }
void CuboidMesh::setXZMeshResolution(const QSize &resolution) noexcept { get()->setXZMeshResolution(resolution); }
void CuboidMesh::setYZMeshResolution(const QSize &resolution) noexcept { get()->setYZMeshResolution(resolution); }

} // namespace Modules
} // namespace Logic
} // namespace ART