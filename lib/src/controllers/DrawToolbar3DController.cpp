#include "DrawToolbar3DController.hpp"

namespace ART {
namespace Controllers {

DrawToolbar3DController::DrawToolbar3DController(QObject *parent)
  : QObject{parent}
{}

// void DrawToolbar3DController::setModel(ART::Models::LeftSidebarModel *model) {
//   _model = model;
//   if (_model == nullptr) {
//     return;
//   }
//   _model->setParent(this);
// }

} // namespace Controllers
} // namespace ART
