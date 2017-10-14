#ifndef RGBCONTROLLER_H
#define RGBCONTROLLER_H

#include <QSerialPort>


class RGBController : public QSerialPort
{

    Q_OBJECT



public:
    RGBController();

private:

    void sendCommand(QString command);

public slots:

    void connectToDevice(QString comName, int baud);
    void disconnectFromDevice();
    void setRGB(int r, int g, int b);
    void setHSV(int h, int s, int v);
    void setAnimation(int type, int speed, int step);


};

#endif // RGBCONTROLLER_H
