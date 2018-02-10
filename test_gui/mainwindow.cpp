#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pump.h"
#include <QDebug>
Pump *myPump;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    myPump = new Pump();
    myPump->initialize();
   // ui->status_label->setText("Trying "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud");
       // ui->status_label->setText("Connected to "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud");

       // QString er = serial->errorString();
       // qDebug()<<er;
       // ui->status_label->setText("Failed for "+serial->portName()+" : "+er);

    //connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
}

MainWindow::~MainWindow(){
    delete ui;
    delete myPump;
}
/*
void MainWindow::serialReceived(){
    QByteArray ba;
    ba=serial->readAll();
    ui->status_label->setText(ba);
    qDebug()<<ba;
}*/
