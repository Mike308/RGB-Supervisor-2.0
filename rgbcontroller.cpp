#include "rgbcontroller.h"
#include <QDebug>
#include <QColor>

RGBController::RGBController()
{



}


void RGBController::setConnectionParameters(QString comName, int baud){

    this->comName = comName;
    this->baud = baud;
}


void RGBController::connectToDevice(){


    qDebug () << "Connecting...";

    if (!this->isOpen()){

        this->setPortName(comName);
        this->setBaudRate(baud);
        this->setFlowControl(QSerialPort::NoFlowControl);
        this->setDataBits(QSerialPort::Data8);
        this->setStopBits(QSerialPort::OneStop);
        emit isConnecting();
        this->open(QIODevice::ReadWrite);
        emit isConnectingFinish();



    }

    connect(this,SIGNAL(readyRead()),this,SLOT(getTemperatureSlot()));

}

void RGBController::disconnectFromDevice(){

    this->close();

}

bool RGBController::getConnectionStatus(){

    return this->isOpen();
}

void RGBController::sendCommand(QString command){

    const QByteArray &commandArray = command.toLocal8Bit();
    this->write(commandArray);

}

void RGBController::setRGB(int r, int g, int b){

    this->sendCommand("AT+RGB="+QString::number(r)+","+QString::number(g)+","+QString::number(b)+"\r\n");


}

void RGBController::setHSV(int h, int s, int v){

    this->sendCommand("AT+HSV="+QString::number(h)+","+QString::number(s)+","+QString::number(v)+"\r\n");
}


void RGBController::setAnimation(int type, int speed, int step){

    this->sendCommand("AT+ANIM="+QString::number(type)+","+QString::number(speed)+","+QString::number(step)+"\r\n");
}

void RGBController::setAnimation(int type, int speed, int step, int red, int green, int blue){
    qDebug () << "Type: " << type << " Speed: " << speed << " Step: " << step << " Red: " << red << " Green: " << green << " Blue: " << blue;
    QColor color;
    color.setRgb(red,green,blue);
    int h;
    int s;
    int v;
    color.getHsv(&h,&s,&v);
    int sVal = (s * 100) / 255;
    int vVal = (v * 100) / 255;
    qDebug () << "H: " << h << " S: " << sVal << " V: "<< vVal;
    this->sendCommand("AT+ANIM="+QString::number(type)+","+QString::number(speed)+","+QString::number(step)+","+QString::number(h)+","+QString::number(sVal)+","+QString::number(vVal)+"\r\n");
}

void RGBController::sendGetTemperatureRequest(){

    this->sendCommand("AT+TEMP?\r\n");

}

void RGBController::getTemperatureSlot(){

    if (this->canReadLine()){

        QString temperature = QString::fromLatin1(this->readAll());
        emit getTemperature(temperature);

    }

}












