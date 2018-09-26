#include "mainwindow.h"
#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QSerialPort *port;
    port = new QSerialPort();
    port->setBaudRate(QSerialPort::Baud38400);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
    port->setPortName("dev/ttyACM0");
    if(port->open(QIODevice::ReadOnly)){
        qDebug()<<"Opened !";
        connect(port,SIGNAL(readyRead()),this,SLOT());
    }else{
        qDebug()<<"Not opened !";
    }
    MainWindow w;
    w.show();

    return a.exec();
}
