#pragma once

#include "globals.h"
#include "Outliner.hpp"

#include <QAbstractListModel>
#include <iostream>

namespace ART {
namespace UI {

class QmlOutliner : public QAbstractListModel, public Models::Outliner {
  Q_OBJECT
  Q_DISABLE_COPY(QmlOutliner)

private:

enum RoleType {
  // ENT_TYPE = Qt::UserRole + 1,
  ID,
  LINE_COLOR
};

public:
  QmlOutliner(QObject *parent = 0);

public Q_SLOTS:
  // void add() {
    // beginInsertRows(QModelIndex(), _shapesId.size(), _shapesId.size());
    // // ++_test;
    // endInsertRows();
  // }


  virtual QVariant data(const QModelIndex &index, int role) const override;
  virtual int rowCount(const QModelIndex &parent) const override;

  virtual QHash<int, QByteArray> roleNames() const override;

  void updateData() noexcept override;

private:
  QVariantList _entityId;
};

} // namespace UI
} // namespace ART