#include <QMessageLogger>

#include "RendererModel.hpp"
#include "RendererController.hpp"

namespace ART {
namespace Controllers {

RendererController::RendererController() {
}

QQuickFramebufferObject::Renderer *RendererController::createRenderer() const noexcept
{

  qInfo() << "Creating RendererModel";
  return new Models::RendererModel();
}

} //namespace Models
} //namespace ART