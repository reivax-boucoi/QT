#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QDebug>
QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyUSB0");
    serial->setBaudRate(QSerialPort::Baud38400);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->open(QIODevice::ReadWrite)){
        serial->write("/1ZR\r");
    }else{
        qDebug()<<serial->errorString();
        serial->error()
    }
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
}

MainWindow::~MainWindow(){
    delete ui;
    serial->close();
}

void MainWindow::serialReceived(){
    QByteArray ba;
    ba=serial->readAll();
    ui->label->setText(ba);
    qDebug()<<ba;
}
