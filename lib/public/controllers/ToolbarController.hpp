#pragma once

#include <QObject>

#include "globals.h"

namespace ART {
namespace Models {
  class ToolbarModel;
} // nameSpace Models

namespace Logic {
} // nameSpace Logic

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT ToolbarController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(ToolbarController)

public:
  explicit ToolbarController(QObject* parent = nullptr);
  ~ToolbarController() = default;
  ToolbarController(ToolbarController&& other) = delete;
  ToolbarController& operator=(ToolbarController&& other) = delete;

  //Takes ownership of model
  void setModel(ART::Models::ToolbarModel* model);

private:
  ART::Models::ToolbarModel *_model{nullptr};


Q_SIGNALS:
  void newFileClicked();
  void openFileClicked(const QUrl& file_url);
  void saveFileClicked();
  void saveAsFileClicked(const QUrl& file_url);
};

} // namespace Controllers
} // namespace ART
