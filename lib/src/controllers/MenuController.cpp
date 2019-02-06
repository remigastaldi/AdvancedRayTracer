#include "MenuController.hpp"
#include "MenuModel.hpp"

namespace ART {
namespace Controllers {

MenuController::MenuController(QObject* parent)
  : QObject{parent}
{}

void MenuController::setModel(ART::Models::MenuModel* model) {
  _model = model;
  if (_model == nullptr) {
    return;
  }
  _model->setParent(this);
}

} // namespace Controllers
} // namespace ART
