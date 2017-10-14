#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSerialPortInfo>

#include "rgbcontroller.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    RGBController rgbController;
    QSerialPortInfo serialPortInfo;
    QList<QSerialPortInfo> serialPortInfoList = serialPortInfo.availablePorts();
    QStringList portsName;

    foreach (QSerialPortInfo port, serialPortInfoList) {

         portsName.append(port.portName());

    }





    QQmlApplicationEngine engine;
    QQmlContext *appContext = engine.rootContext();
    appContext->setContextProperty("rgbController",&rgbController);
    appContext->setContextProperty("portsNameModel",QVariant::fromValue(portsName));

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
