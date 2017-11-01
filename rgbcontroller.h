#ifndef RGBCONTROLLER_H
#define RGBCONTROLLER_H

#include <QSerialPort>
#include <QTimer>
#include <QThread>


class RGBController : public QSerialPort
{

    Q_OBJECT



public:
    RGBController();





private:
    void sendCommand(QString command);
    QTimer *timer;
    QThread *connectThread;
    QString comName;
    int baud;

public slots:
    void setConnectionParameters(QString comName, int baud);
    void connectToDevice();
    void sendGetTemperatureRequest();
    void disconnectFromDevice();
    void setRGB(int r, int g, int b);
    void setHSV(int h, int s, int v);
    void setAnimation(int type, int speed, int step);
    bool getConnectionStatus();


private slots:
    void getTemperatureSlot();

signals:
    QString getTemperature(QString temperature);
    void isConnecting();
    void isConnectingFinish();





};

#endif // RGBCONTROLLER_H
