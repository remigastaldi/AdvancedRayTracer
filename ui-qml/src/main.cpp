#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>

#include "main-controller.hpp"
#include "menu-controller.hpp"

#include "menu-model.hpp"

int main(int argc, char *argv[])
{
  QApplication::setApplicationName("AdvancedRayTracer");
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
  qmlRegisterType<ART::Controllers::MenuController>("AdvancedRayTracer", 1, 0, "MenuController");

  ART::Controllers::MainController main_controller;


  auto menu_model = new ART::Models::MenuModel;
  main_controller.menuController()->setModel(menu_model);

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("mainController", &main_controller);
  engine.rootContext()->setContextProperty("menuModel", menu_model);
  engine.load(QUrl(QStringLiteral("qrc:/views/MainView.qml")));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
