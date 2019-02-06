#pragma once

#include <QObject>
#include <QString>

#include "globals.h"

namespace ART {
namespace Models {
} // namespace Models

namespace Controllers {

class ToolbarController;
class SidebarController;

class ADVANCED_RAY_TRACER_EXPORT MainController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MainController)

  Q_PROPERTY(ART::Controllers::ToolbarController* menuController READ menuController CONSTANT)

public:
  explicit MainController(QObject* parent = nullptr);

  ToolbarController* menuController() const noexcept;
  SidebarController *sidebarController() const noexcept;

private:
  ToolbarController* _menuController{nullptr};
  SidebarController* _sidebarController{nullptr};

private Q_SLOTS:
  void handleSaveFileClicked();
  void handleSaveAsFileClicked(const QUrl& url);
  void handleNewFileClicked();
};

} // namespace Controllers
} // namespace ART
