#ifndef RGBCONTROLLER_H
#define RGBCONTROLLER_H

#include <QSerialPort>
#include <QTimer>

class RGBController : public QSerialPort
{

    Q_OBJECT



public:
    RGBController();

private:
    void sendCommand(QString command);
    QTimer *timer;


public slots:
    void connectToDevice(QString comName, int baud);
    bool getConnectionStatus();
    void disconnectFromDevice();
    void setRGB(int r, int g, int b);
    void setHSV(int h, int s, int v);
    void setAnimation(int type, int speed, int step);

private slots:
    void sendGetTemperatureRequest();
    void getTemperatureSlot();

signals:
    QString getTemperature(QString temperature);





};

#endif // RGBCONTROLLER_H
