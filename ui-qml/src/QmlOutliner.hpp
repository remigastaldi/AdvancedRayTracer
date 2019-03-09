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

  virtual QVariant data(const QModelIndex &index, int role) const override;
  virtual int rowCount(const QModelIndex &parent) const override;
  virtual QHash<int, QByteArray> roleNames() const override;

  virtual void dataUpdate() noexcept override;
  virtual void selectionIndexUpdate() noexcept override;

public Q_SLOTS:
  // void setSelectionIndex(int index);
  int selectionIndex();

Q_SIGNALS:
  void selectionIndexChanged();

private:
  QVariantList _entityId;
};

} // namespace UI
} // namespace ART