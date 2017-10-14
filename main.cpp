#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "rgbcontroller.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    RGBController rgbController;


    QQmlApplicationEngine engine;
    QQmlContext *appContext = engine.rootContext();
    appContext->setContextProperty("rgbController",&rgbController);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
