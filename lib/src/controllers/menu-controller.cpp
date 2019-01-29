#include "menu-controller.hpp"
#include "menu-model.hpp"

namespace ART {
namespace Controllers {

MenuController::MenuController(QObject* parent)
  : QObject{parent}
{}

void MenuController::setModel(ART::Models::MenuModel* model) {
  model_ = model;
  if (!model_) {
    return;
  }
  model_->setParent(this);
}

} // namespace Controllers
} // namespace ART
