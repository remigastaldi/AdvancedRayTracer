#include "DrawToolbar2DController.hpp"

namespace ART {
namespace Controllers {

DrawToolbar2DController::DrawToolbar2DController(QObject *parent)
  : QObject{parent}
{}

// void DrawToolbar2DController::setModel(ART::Models::LeftSidebarModel *model) {
//   _model = model;
//   if (_model == nullptr) {
//     return;
//   }
//   _model->setParent(this);
// }

} // namespace Controllers
} // namespace ART
