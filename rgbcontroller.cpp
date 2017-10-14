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





