#include <QMessageLogger>

#include "FbItemRenderer.hpp"
#include "FbItem.hpp"

namespace ART {
namespace Logic {

FbItem::FbItem() {
}

QQuickFramebufferObject::Renderer *FbItem::createRenderer() const noexcept
{
  qInfo() << "Creating FbItemRenderer";
  return new Logic::FbItemRenderer();
}

} //namespace Logic
} //namespace ART