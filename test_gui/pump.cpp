#include "pump.h"

Pump::Pump(){
    comminit();
}

Pump::Pump(char a, QString p, QSerialPort::BaudRate bd){
    address=a;
    port=p;
    baud=bd;
    comminit();
}

Pump::~Pump(){
    serial->close();
}
void Pump::initialize(){
    //serial->write('/'+address+"ZR\r");
    serial->write("/1ZR");
    qDebug()<<"Connected to "+serial->portName()+" @ "+QString::number(serial->baudRate())+" baud";
}

void Pump::setPosition(uint p, char mode){

    switch(mode){
     case 'A': // Absolute mode
        if(p<0)p=0;
        if(p>pmax)p=pmax;
        serial->write('/'+address+'A'+p+"\r");
        pos=p;
    break;
    case 'D': // Dispense mode
        if(p>pos)p=pos;
        serial->write('/'+address+'D'+p+"\r");
        pos-=p;
    break;
    case 'P': // Pickup mode;
        if((p+pos)>pmax)p=pmax-pos;
        serial->write('/'+address+'P'+p+"\r");
        pos+=p;
    }
}

bool Pump::comminit(){
    serial = new QSerialPort();
    serial->setPortName(port);
    serial->setBaudRate(baud);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(! serial->open(QIODevice::ReadWrite)){
        QString er = serial->errorString();
        qDebug()<<er;
        //ui->status_label->setText("Failed for "+serial->portName()+" : "+er);
        return false;
    }
    return true;
}
