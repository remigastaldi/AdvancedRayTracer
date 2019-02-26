#include "Outliner.hpp"
#include <iostream>
namespace ART {
namespace UI {

Outliner::Outliner(QObject *parent) : QAbstractListModel{parent} {}

QHash<int, QByteArray> Outliner::roleNames() const {
  QHash<int, QByteArray> rez;
  rez[RoleType::ENT_TYPE] = "entityType";
  rez[RoleType::ID] = "id";
  return rez;
}

QVariant Outliner::data(const QModelIndex &index, int role) const {
  switch (role) {
    case RoleType::ENT_TYPE:
      return QVariant::fromValue(QString("Cube"));
    case RoleType::ID:
      return QVariant::fromValue(QString("Test"));
    default:
      break;
  }

  return QVariant();
}

int Outliner::rowCount(const QModelIndex &parent) const 
{ 
  Q_UNUSED(parent);
  return _test;
}

} // namespace UI
} // namespace ART