#include <QMessageLogger>

#include "FbItemRenderer.hpp"
#include "FbItem.hpp"

namespace ART {
namespace Logic {

FbItem::FbItem() : _shapes(), _currentId{0} {
  _shapes.reserve(25);
}

QQuickFramebufferObject::Renderer *FbItem::createRenderer() const noexcept
{
  return new Logic::FbItemRenderer();
}

const std::unordered_map<size_t, FbItem::Data> &FbItem::shapes() const noexcept {
  return _shapes;
}

void  FbItem::setAutoRenderFps(int fps) noexcept {
  _renderFps = fps;
  update();
}

void FbItem::createCube() noexcept {
  Transform3D cube;

  cube.translate({-2.0 + _currentId, 0.0, -5.0});
  
  _shapes.emplace(_currentId++, Data{FbItem::Type::CUBE, cube});
}

void FbItem::test()  {
  createCube();
};

} //namespace Logic
} //namespace ART