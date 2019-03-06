#include "QmlOutliner.hpp"
#include "Outliner.hpp"

#include <QColor>

#include <iostream>

namespace ART {
namespace UI {

QmlOutliner::QmlOutliner(QObject *parent) : QAbstractListModel{parent} {
  // connect(static_cast<Models::Outliner*>(this), &Models::Outliner::outlinerDataChanged, this, &UI::QmlOutliner::updateData);
}

QHash<int, QByteArray> QmlOutliner::roleNames() const {
  QHash<int, QByteArray> rez;
  // rez[RoleType::ENT_TYPE] = "entityType";
  rez[RoleType::ID] = "id";
  rez[RoleType::LINE_COLOR] = "lineColor";
  return rez;
}

QVariant QmlOutliner::data(const QModelIndex &index, int role) const {
  switch (role) {
    // case RoleType::ENT_TYPE:
    //   return QVariant::fromValue(QString("Cube"));
    case RoleType::ID:
      return _shapesId[index.row()];
    case RoleType::LINE_COLOR:
      return QColor((index.row() + 1) % 2 == 0 ? "#292D3E" : "#1B1E2B");
    default:
      break;
  }

  return QVariant();
}

int QmlOutliner::rowCount(const QModelIndex &parent) const 
{ 
  Q_UNUSED(parent);
  return _shapesId.size();
}

} // namespace UI
} // namespace ART