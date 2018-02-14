#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pump.h"
#include <QDebug>
#include <QTime>

void delay( int millisecondsToWait )
{
    QTime dl = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dl ){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

QSerialPort *serial;
const int nbPumps =8;
Pump *myPumps[nbPumps];

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    serial = new QSerialPort();
    // ui->status_label->setText("Connected to "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud");
    // QString er = serial->errorString();
    // qDebug()<<er;
    // ui->status_label->setText("Failed for "+serial->portName()+" : "+er);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
}

MainWindow::~MainWindow(){
    delete ui;
    for(int i=0;i<nbPumps;i++)delete myPumps[i];
}
bool MainWindow::comminit(){
    serial->setPortName("/dev/ttyUSB0");
    serial->setBaudRate(QSerialPort::Baud38400);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(! serial->open(QIODevice::ReadWrite)){
        QString er = serial->errorString();
        qDebug()<<er;
        return false;
    }
    return true;
}

void MainWindow::pumpControls(bool on){
    if(on){
        ui->initbutton->setEnabled(true);
        ui->radioButton_absolute->setEnabled(true);
        ui->radioButton_dispense->setEnabled(true);
        ui->radioButton_pickup->setEnabled(true);
        ui->poslider->setEnabled(true);
        ui->plungermovebutton->setEnabled(true);
        ui->lcdNumber->setEnabled(true);
        ui->comboBox_valve->setEnabled(true);
        ui->pushButton_cycle->setEnabled(true);
    }else{
        ui->initbutton->setEnabled(false);
        ui->radioButton_absolute->setEnabled(false);
        ui->radioButton_dispense->setEnabled(false);
        ui->radioButton_pickup->setEnabled(false);
        ui->poslider->setEnabled(false);
        ui->plungermovebutton->setEnabled(false);
        ui->lcdNumber->setEnabled(false);
        ui->comboBox_valve->setEnabled(false);
        ui->pushButton_cycle->setEnabled(false);
    }
}


void MainWindow::serialReceived(){
    QByteArray ba;
    ba=serial->readAll();
    ui->label_status->setText(ba);
    qDebug()<<ba;
}

void MainWindow::on_initbutton_clicked(){
    myPumps[ui->spinBox_address->value()-1]->initialize();
    ui->poslider->setValue(0);
    ui->radioButton_absolute->setChecked(true);
}

void MainWindow::on_plungermovebutton_clicked(){
    if(ui->radioButton_absolute->isChecked()){
        myPumps[ui->spinBox_address->value()-1]->setPosition(ui->poslider->value(),'A');
    }
    else if(ui->radioButton_dispense->isChecked()){
        myPumps[ui->spinBox_address->value()-1]->setPosition(ui->poslider->value(),'D');
        ui->poslider->setMaximum(myPumps[ui->spinBox_address->value()-1]->getPosition());
    }
    else if(ui->radioButton_pickup->isChecked()){
        myPumps[ui->spinBox_address->value()-1]->setPosition(ui->poslider->value(),'P');
        ui->poslider->setMaximum(myPumps[ui->spinBox_address->value()-1]->getPmax()-myPumps[ui->spinBox_address->value()-1]->getPosition());
    }
}

void MainWindow::on_radioButton_absolute_clicked(){
    ui->poslider->setMaximum(myPumps[ui->spinBox_address->value()-1]->getPmax());
}

void MainWindow::on_radioButton_pickup_clicked(){
    ui->poslider->setMaximum(myPumps[ui->spinBox_address->value()-1]->getPmax()-myPumps[ui->spinBox_address->value()]->getPosition());
}

void MainWindow::on_radioButton_dispense_clicked(){
    ui->poslider->setMaximum(myPumps[ui->spinBox_address->value()-1]->getPosition());
}

void MainWindow::on_pushButton_connect_clicked(){
    if(ui->pushButton_connect->text()=="Connect"){
        if(!serial->isOpen()){
            pumpControls(comminit());
        }
        if(serial->isOpen()){
            for(int i=0;i<nbPumps;i++){
                myPumps[i] = new Pump(i+1,serial);
            }
            ui->statusBar->showMessage("Connected on "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud");
            ui->pushButton_connect->setText("Disconnect");
        }else{
            ui->statusBar->showMessage("Failed to connect on "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud : "+serial->errorString());
        }
    }else{
        serial->close();
        ui->statusBar->showMessage("Diconnected");
        pumpControls(false);
        ui->pushButton_connect->setText("Connect");
    }
}

void MainWindow::on_comboBox_valve_activated(const QString &arg1){
    myPumps[ui->spinBox_address->value()-1]->setValve(ui->comboBox_valve->currentText());
}

void MainWindow::on_pushButton_cycle_clicked(){
    for(int i=0;i<8;i++){
        myPumps[i]->setValve("Input");
        delay(150);
    }
      for(int i=0;i<8;i++){
    myPumps[i]->setPosition(3000,'A');
    delay(150);
}
      delay(2500);
      for(int i=0;i<8;i++){
    myPumps[i]->setValve("Output");
    delay(150);
}
      for(int i=0;i<8;i++){
    myPumps[i]->setPosition(0,'A');
    delay(150);
}
}

void MainWindow::on_pushButton_zeroall_clicked(){
    for(int i=0;i<nbPumps;i++){
        myPumps[i]->initialize();
        delay(150);
    }
}
