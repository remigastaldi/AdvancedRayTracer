#include "LeftSidebarController.hpp"
#include "LeftSidebarModel.hpp"

namespace ART {
namespace Controllers {

LeftSidebarController::LeftSidebarController(QObject *parent)
  : QObject{parent}
{}

void LeftSidebarController::setModel(ART::Models::LeftSidebarModel *model) {
  _model = model;
  if (_model == nullptr) {
    return;
  }
  _model->setParent(this);
}

} // namespace Controllers
} // namespace ART
