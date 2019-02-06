#include "RendererController.hpp"
#include "RendererModel.hpp"

namespace ART {
namespace Controllers {

RendererController::RendererController() {
}

QQuickFramebufferObject::Renderer *RendererController::createRenderer() const
{
  std::cout << "======" << std::endl;

   return new Models::RendererModel();
}

} //namespace Models
} //namespace ART
