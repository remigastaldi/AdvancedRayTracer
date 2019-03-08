#include "QmlOutliner.hpp"
#include "Outliner.hpp"

#include <QColor>

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
      return _entityId[index.row()];
    case RoleType::LINE_COLOR:
      return QColor((index.row() + 1) % 2 == 0 ? QString("#1A1C20") : QString("#1F1F1F"));
    default:
      break;
  }

  return QVariant();
}

int QmlOutliner::rowCount(const QModelIndex &parent) const 
{ 
  Q_UNUSED(parent);
  return _entityId.size();
}

void QmlOutliner::updateData() noexcept {
  // if (entitiesHierarchy().empty() && !_entityId.empty()) {
  if (!_entityId.empty()) {
    beginRemoveRows(QModelIndex(), 0, _entityId.size() - 1);
    _entityId.clear();
    endRemoveRows();
  }

  if (!entitiesHierarchy().empty()) {
    beginInsertRows(QModelIndex(), 0, entitiesHierarchy().size() - 1);
    for (const auto &val : entitiesHierarchy()) {
      _entityId.push_back(QString::fromStdString(val));
    }
    endInsertRows();
  }


  // if (_entityId.size() > entitiesHierarchy().size()) {
  //   beginRemoveRows(QModelIndex(), entitiesHierarchy().size(), _entityId.size());
  //   endRemoveRows();
  //   _entityId.reserve(_entityId.size());
  //   for (int i = static_cast<int>(entitiesHierarchy().size()); i < _entityId.size(); ++i) {
  //     _entityId.removeAt(i);
  //   }
  // }
  // int i{0};
  // for (const auto &shapeId : entitiesHierarchy()) {
  //   QString qshapeId{QString::fromStdString(shapeId)};
  //   if (_entityId.size() > i && _entityId[i] != qshapeId) {
  //     beginRemoveRows(QModelIndex(), i, i);
  //     endRemoveRows();
  //     beginInsertRows(QModelIndex(), i, i);
  //     _entityId[i] = qshapeId;
  //     endInsertRows();
  //   } else if (_entityId.empty()) {
  //     beginInsertRows(QModelIndex(), 0, 0);
  //     _entityId.push_back(qshapeId);
  //     endInsertRows();
  //   } else {
  //     beginInsertRows(QModelIndex(), _entityId.size(), _entityId.size());
  //     _entityId.push_back(qshapeId);
  //     endInsertRows();
  //   }
  //   ++i;
  // }
}

} // namespace UI
} // namespace ART