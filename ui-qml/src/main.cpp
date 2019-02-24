#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>

#include "MainController.hpp"
#include "ToolbarController.hpp"
#include "RightSidebarController.hpp"
#include "LeftSidebarController.hpp"
#include "FbItem.hpp"

#include "ToolbarModel.hpp"
#include "RightSidebarModel.hpp"
#include "LeftSidebarModel.hpp"
#include "FbItemRenderer.hpp"

int main(int argc, char *argv[])
{
  QApplication::setApplicationName("AdvancedRayTracer");
  QCoreApplication::setOrganizationName("Team 5");
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);
  
  QStringList fonts = QStringList{} << ":/fonts/Hack-Regular.ttf" << ":/fonts/Hack-Bold.ttf"
                                    << ":/fonts/Hack-BoldItalic.ttf" << ":/fonts/Hack-Italic.ttf"
                                    << ":/fonts/fontello.ttf";

  for (const auto& font : fonts) {
    if (QFontDatabase::addApplicationFont(font) == -1) {
        qWarning() << "Failed to load font: " << font;
    }
  }

  qmlRegisterType<ART::Controllers::MainController>("AdvancedRayTracer", 1, 0, "MainController");
  qmlRegisterType<ART::Controllers::ToolbarController>("AdvancedRayTracer", 1, 0, "ToolbarController");
  qmlRegisterType<ART::Controllers::RightSidebarController>("AdvancedRayTracer", 1, 0, "RightSidebarController");
  qmlRegisterType<ART::Controllers::LeftSidebarController>("AdvancedRayTracer", 1, 0, "LeftSidebarController");
  qmlRegisterType<ART::Logic::FbItem>("AdvancedRayTracer", 1, 0, "FbItem");

  QQmlApplicationEngine engine;
  ART::Controllers::MainController mainController;

  auto toolBarModel = new ART::Models::ToolbarModel;
  mainController.toolbarController()->setModel(toolBarModel);

  auto rightSidebarModel = new ART::Models::RightSidebarModel;
  mainController.rightSidebarController()->setModel(rightSidebarModel);
  auto leftSidebarModel = new ART::Models::LeftSidebarModel;
  mainController.leftSidebarController()->setModel(leftSidebarModel);

  engine.rootContext()->setContextProperty("mainController", &mainController);
  engine.rootContext()->setContextProperty("menuModel", toolBarModel);
  engine.rootContext()->setContextProperty("rightSidebarModel", rightSidebarModel);
  engine.rootContext()->setContextProperty("leftSidebarModel", leftSidebarModel);
  engine.load(QUrl(QStringLiteral("qrc:/views/MainView.qml")));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  auto *fbItem =  engine.rootObjects().first()->findChild<ART::Logic::FbItem*>("fbItem");
  mainController.setFbItem(fbItem);

  mainController.dumpObjectTree();
  return QApplication::exec();
}
