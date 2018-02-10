#include "pump.h"

Pump::Pump(){
    comminit();
}

Pump::Pump(int a, QString p, uint bd){
    address=a;
    port=p;
    if(bd==38400)baud=QSerialPort::Baud38400;
    if(bd==9600)baud=QSerialPort::Baud9600;
    comminit();
}

Pump::~Pump(){
    serial->close();
}
void Pump::initialize(){
    serial->write("/1ZR\r");
    //serial->write("/1ZR\r");
    pos=0;
}

void Pump::setPosition(uint p, char mode){
    qDebug()<<p;
    switch(mode){
     case 'A': // Absolute mode
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

uint Pump::getPosition(){
    return pos;
}

uint Pump::getPmax(){
    return pmax;
}

uint Pump::getAddress(){
    return address;
}

uint Pump::getBaudRate(){
    if(baud==QSerialPort::Baud9600)return 9600;
    if(baud==QSerialPort::Baud38400)return 38400;
    return -1; // Julien ?
}

QString Pump::getPort(){
    return port;
}

bool Pump::isConnected(){
    return serial->isOpen();
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
        return false;
    }
    return true;
}
