#include "RendererModel.hpp"
#include "RendererController.hpp"

namespace ART {
namespace Controllers {

RendererController::RendererController() {
}

QQuickFramebufferObject::Renderer *RendererController::createRenderer() const noexcept
{
  std::cout << "Create Renderer" << std::endl;

  return new Models::RendererModel();
}

} //namespace Models
} //namespace ART