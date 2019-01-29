#include "menu-model.hpp"


namespace ART {
namespace Models {

MenuModel::MenuModel(QObject* parent) : QObject{parent} {
}

bool MenuModel::isNewFile() const {
  return true;
}


} //namespace Models
} //namespace ART
