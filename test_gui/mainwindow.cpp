#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pump.h"
#include <QDebug>
Pump *myPump;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
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

void MainWindow::on_initbutton_clicked(){
    myPump->initialize();
    ui->poslider->setValue(0);
    ui->radioButton_absolute->setChecked(true);
}

void MainWindow::on_plungermovebutton_clicked(){
    if(ui->radioButton_absolute->isChecked()){
        myPump->setPosition(ui->poslider->value(),'A');
    }
    else if(ui->radioButton_dispense->isChecked()){
        myPump->setPosition(ui->poslider->value(),'D');
        ui->poslider->setMaximum(myPump->getPosition());
    }
    else if(ui->radioButton_pickup->isChecked()){
        myPump->setPosition(ui->poslider->value(),'P');
        ui->poslider->setMaximum(myPump->getPmax()-myPump->getPosition());
    }
}

void MainWindow::on_radioButton_absolute_clicked(){
    ui->poslider->setMaximum(myPump->getPmax());
}

void MainWindow::on_radioButton_pickup_clicked(){
    ui->poslider->setMaximum(myPump->getPmax()-myPump->getPosition());
}

void MainWindow::on_radioButton_dispense_clicked(){
    ui->poslider->setMaximum(myPump->getPosition());
}

void MainWindow::on_pushButton_connect_clicked(){
    myPump = new Pump(ui->spinBox_address->value(),"/dev/ttyUSB0",38400);
    if(myPump->isConnected())ui->statusBar->showMessage("Pump n°"+QString::number(myPump->getAddress())+" connected on "+myPump->getPort()+" @ "+QString::number(myPump->getBaudRate())+" baud");

}
