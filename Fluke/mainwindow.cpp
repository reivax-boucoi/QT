#include "mainwindow.h"
#include "ui_mainwindow.h"

QSerialPort serial;
bool HOLD=false;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);

}

MainWindow::~MainWindow(){
    delete ui;
    serial.close();
}

void MainWindow::on_pushButton_request_clicked(){
    serial.write("d\n");
}

void MainWindow::on_pushButton_Hold_clicked(){
    serial.write("n\n");
}

void MainWindow::on_pushButton_hv_clicked(){
    if(HOLD){
        serial.write("q\n");
    }else{
        serial.write("i\n");
    }
}

void MainWindow::on_pushButton_connect_clicked(){
    if(serial.isOpen()){
        serial.close();
    }
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Name : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();

        // Example use QSerialPort
        serial.setPortName(info.portName());
        serial.setBaudRate(2400);
        if (serial.open(QIODevice::ReadWrite)){
            ui->pushButton_Hold->setEnabled(true);
            ui->pushButton_hv->setEnabled(true);
            ui->pushButton_request->setEnabled(true);
        };
    }
}
