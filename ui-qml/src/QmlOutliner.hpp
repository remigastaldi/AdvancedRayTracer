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
  ID
};

public:
  QmlOutliner(QObject *parent = 0);

  // void AddEntry(QString aMessage, QColor aColor);

public Q_SLOTS:
  void add() {
    beginInsertRows(QModelIndex(), _test, _test);
    ++_test;
    endInsertRows();
  }


  virtual QVariant data(const QModelIndex &index, int role) const override;
  virtual int rowCount(const QModelIndex &parent) const override;

  virtual QHash<int, QByteArray> roleNames() const override;

private:
int _test{0};
};

} // namespace UI
} // namespace ART