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
    int setR;
    int setG;
    int setB;
    int setH;
    int setS;
    int setV;



public slots:
    void connectToDevice(QString comName, int baud);
    bool getConnectionStatus();
    void disconnectFromDevice();
    void setRGB(int r, int g, int b);
    void setHSV(int h, int s, int v);
    void setAnimation(int type, int speed, int step);
    void setAnimation(int type, int speed, int step, int red, int green, int blue);


private slots:
    void sendGetTemperatureRequest();
    void getTemperatureSlot(QString temperature);
    void getConnecting();
    void getConnectingFinish();
    void setRGBSlot();
    void setHSVSlot();


signals:
    QString getTemperature(QString temperature);
    void qmlConnecting();
    void qmlConnectingFinish();
    void disconnectSignal();
    void setRGBSignal(int r, int g, int b);
    void setHSVSignal(int h, int s, int v);
    void setAnimationSignal(int type, int speed, int step);
    void setAnimationSignal(int type, int speed, int step, int red, int green, int blue);
    bool getConnectionStatusSignal();
    void setParameterSignal(QString comName, int baud);
    void sendGetTemperatureRequestSignal();









};

#endif // RGBCONTROLLERQML_H
