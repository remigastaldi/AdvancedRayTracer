#include "QmlOutliner.hpp"
#include <iostream>

namespace ART {
namespace UI {

QmlOutliner::QmlOutliner(QObject *parent) : QAbstractListModel{parent} {}

QHash<int, QByteArray> QmlOutliner::roleNames() const {
  QHash<int, QByteArray> rez;
  // rez[RoleType::ENT_TYPE] = "entityType";
  rez[RoleType::ID] = "id";
  return rez;
}

QVariant QmlOutliner::data(const QModelIndex &index, int role) const {
  switch (role) {
    // case RoleType::ENT_TYPE:
    //   return QVariant::fromValue(QString("Cube"));
    case RoleType::ID:
      return QVariant::fromValue(QString("Cube"));
    default:
      break;
  }

  return QVariant();
}

int QmlOutliner::rowCount(const QModelIndex &parent) const 
{ 
  Q_UNUSED(parent);
  return _test;
}

} // namespace UI
} // namespace ART