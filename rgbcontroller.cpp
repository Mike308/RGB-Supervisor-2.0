#include "rgbcontroller.h"

RGBController::RGBController()
{

}


void RGBController::connectToDevice(QString comName, int baud){

    if (!this->isOpen()){

        this->setPortName(comName);
        this->setBaudRate(baud);
        this->setFlowControl(QSerialPort::NoFlowControl);
        this->setDataBits(QSerialPort::Data8);
        this->setStopBits(QSerialPort::OneStop);
        this->open(QIODevice::ReadWrite);


    }

}

void RGBController::sendCommand(QString command){

    const QByteArray &commandArray = command.toLocal8Bit();
    this->write(commandArray);

}

void RGBController::setRGB(int r, int g, int b){

    this->sendCommand("AT+RGB="+QString::number(r)+","+QString::number(g)+","+QString::number(b)+"\r\n");


}

void RGBController::setHSV(int h, int s, int v){

    this->sendCommand("AT+HSV="+QString::number(h)+","+QString::number(s)+","+QString::number(b)+"\r\n");
}










