#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QDebug>
QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName(PORT);
    if(BAUD==38400){
        serial->setBaudRate(QSerialPort::Baud38400);
    }else{
        serial->setBaudRate(QSerialPort::Baud9600);
    }
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    ui->status_label->setText("Trying "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud");
    if(serial->open(QIODevice::ReadWrite)){
        serial->write(PREFIX"ZR\r");
        ui->status_label->setText("Connected to "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud");
    }else{
        QString er = serial->errorString();
        qDebug()<<er;
        ui->status_label->setText("Failed for "+serial->portName()+" : "+er);
        //serial->error();
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
    ui->status_label->setText(ba);
    qDebug()<<ba;
}
