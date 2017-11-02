#include "rgbcontrollerqml.h"


RGBControllerQML::RGBControllerQML()
{
    rgbController = new RGBController();

    timer = new QTimer();



}

RGBControllerQML::~RGBControllerQML(){

    rgbControllerThread->quit();
    rgbControllerThread->wait();



}

void RGBControllerQML::connectToDevice(QString comName, int baud){

    connect(this,SIGNAL(setParameterSignal(QString,int)),rgbController,SLOT(setConnectionParameters(QString,int)));
    emit setParameterSignal(comName,baud);

    rgbControllerThread = new QThread();
    rgbController->moveToThread(rgbControllerThread);
    connect(rgbControllerThread,SIGNAL(started()),rgbController,SLOT(connectToDevice()));
    connect(rgbControllerThread,SIGNAL(finished()),rgbController,SLOT(deleteLater()));
    connect(rgbController,SIGNAL(isConnecting()),this,SLOT(getConnecting()));
    connect(rgbController,SIGNAL(isConnectingFinish()),this,SLOT(getConnectingFinish()));

    connect(this,SIGNAL(disconnectSignal()),rgbController,SLOT(disconnectFromDevice()));
    connect(this,SIGNAL(setRGBSignal(int,int,int)),rgbController,SLOT(setRGB(int,int,int)));
    connect(this,SIGNAL(setHSVSignal(int,int,int)),rgbController,SLOT(setHSV(int,int,int)));
    connect(this,SIGNAL(setAnimationSignal(int,int,int)),rgbController,SLOT(setAnimation(int,int,int)));
    connect(this,SIGNAL(getConnectionStatusSignal()),rgbController,SLOT(getConnectionStatus()));
    connect(rgbController,SIGNAL(getTemperature(QString)),this,SLOT(getTemperatureSlot(QString)));
    connect(this,SIGNAL(sendGetTemperatureRequestSignal()),rgbController,SLOT(sendGetTemperatureRequest()));
    connect(timer,SIGNAL(timeout()),this,SLOT(sendGetTemperatureRequest()));




    rgbControllerThread->start();
    timer->start(3000);


}

void RGBControllerQML::setAnimation(int type, int speed, int step){

    emit setAnimationSignal(type,speed,step);
}

void RGBControllerQML::setHSV(int h, int s, int v){

    emit setHSVSignal(h,s,v);
}

void RGBControllerQML::setRGB(int r, int g, int b){

    emit setRGBSignal(r,g,b);
}

//void RGBControllerQML::sendGetTemperatureRequest(){

//    //rgbController->sendGetTemperatureRequest();
//}

bool RGBControllerQML::getConnectionStatus(){

    return rgbController->getConnectionStatus();

}

void RGBControllerQML::disconnectFromDevice(){


    emit disconnectSignal();
    rgbControllerThread->requestInterruption();


}

void RGBControllerQML::getConnecting(){

    emit qmlConnecting();
}

void RGBControllerQML::getConnectingFinish(){

    emit qmlConnectingFinish();
}





