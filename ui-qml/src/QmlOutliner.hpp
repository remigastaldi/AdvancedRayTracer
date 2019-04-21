#pragma once

// #include "globals.h"
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
  explicit QmlOutliner(QObject *parent = nullptr);

  [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
  [[nodiscard]] int rowCount(const QModelIndex &parent) const override;
  [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

  void dataUpdate() noexcept override;
  void selectionIndexUpdate() noexcept override;

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