#include "rgbcontroller.h"

RGBController::RGBController()
{
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,sendGetTemperatureRequest());

}


void RGBController::connectToDevice(QString comName, int baud){

    if (!this->isOpen()){

        this->setPortName(comName);
        this->setBaudRate(baud);
        this->setFlowControl(QSerialPort::NoFlowControl);
        this->setDataBits(QSerialPort::Data8);
        this->setStopBits(QSerialPort::OneStop);
        this->open(QIODevice::ReadWrite);
        timer->start(3000);
        connect(this,SIGNAL(readyRead()),this,getTemperatureSlot());



    }

}

void RGBController::disconnectFromDevice(){

    timer->stop();
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












