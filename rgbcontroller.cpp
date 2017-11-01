#include "rgbcontroller.h"
#include <QDebug>

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

void RGBController::sendGetTemperatureRequest(){

    this->sendCommand("AT+TEMP?\r\n");

}

void RGBController::getTemperatureSlot(){

    if (this->canReadLine()){

        QString temperature = QString::fromLatin1(this->readAll());
        emit getTemperature(temperature);
    }

}












