#include "SidebarController.hpp"
#include "SidebarModel.hpp"

namespace ART {
namespace Controllers {

SidebarController::SidebarController(QObject *parent)
  : QObject{parent}
{}

void SidebarController::setModel(ART::Models::SidebarModel *model) {
  _model = model;
  if (_model == nullptr) {
    return;
  }
  _model->setParent(this);
}

} // namespace Controllers
} // namespace ART
