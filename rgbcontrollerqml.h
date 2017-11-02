#ifndef RGBCONTROLLERQML_H
#define RGBCONTROLLERQML_H

#include <QThread>
#include <QTimer>
#include <QObject>
#include "rgbcontroller.h"



class RGBControllerQML : public QObject
{

    Q_OBJECT

public:
    RGBControllerQML();
    ~RGBControllerQML();


private:
    QThread *rgbControllerThread;
    QTimer  *timer;
    RGBController *rgbController;


public slots:
    void connectToDevice(QString comName, int baud);
    bool getConnectionStatus();
    void disconnectFromDevice();
    void setRGB(int r, int g, int b);
    void setHSV(int h, int s, int v);
    void setAnimation(int type, int speed, int step);

private slots:
//    void sendGetTemperatureRequest();
//    void getTemperatureSlot();
    void getConnecting();
    void getConnectingFinish();


signals:
    QString getTemperature(QString temperature);
    void qmlConnecting();
    void qmlConnectingFinish();
    void disconnectSignal();
    void setRGBSignal(int r, int g, int b);
    void setHSVSignal(int h, int s, int v);
    void setAnimationSignal(int type, int speed, int step);
    bool getConnectionStatusSignal();
    void setParameterSignal(QString comName, int baud);








};

#endif // RGBCONTROLLERQML_H
