#pragma once

#include <QObject>

#include "globals.h"

namespace ART {
namespace Models {
  class MenuModel;
} // nameSpace Models

namespace Logic {
} // nameSpace Logic

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT MenuController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MenuController)

public:
  explicit MenuController(QObject* parent = nullptr);

  //Takes ownership of model
  void setModel(ART::Models::MenuModel* model);

private:
  ART::Models::MenuModel *_model{nullptr};

Q_SIGNALS:
  void newFileClicked();
  void openFileClicked(const QUrl& file_url);
  void saveFileClicked();
  void saveAsFileClicked(const QUrl& file_url);
};

} // namespace Controllers
} // namespace ART
