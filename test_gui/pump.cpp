#include "pump.h"

Pump::Pump(int a, QSerialPort *s){
    address=a;
    serial=s;
}

Pump::~Pump(){
    serial->close();
}
void Pump::initialize(){
    std::string s = '/'+std::to_string(address)+"ZR\r";
    serial->write(s.c_str());
    pos=0;
}

void Pump::setPosition(uint p, char mode){
    //qDebug()<<p;
    std::string slhljjh='/'+std::to_string(address);
    switch(mode){
     case 'A': // Absolute mode
        if(p>pmax)p=pmax;
        slhljjh +='A';
        pos=p;
    break;
    case 'D': // Dispense mode
        if(p>pos)p=pos;
        slhljjh +='D';
        pos-=p;
    break;
    case 'P': // Pickup mode;
        if((p+pos)>pmax)p=pmax-pos;
        slhljjh +='P';
        pos+=p;
        break;
    }
    slhljjh+=std::to_string(p)+"R\r";
    serial->write(slhljjh.c_str());
}

void Pump::setValve(QString p){
    std::string s = '/'+std::to_string(address)+qPrintable(p.at(0).toUpper())+"R\r";
    serial->write(s.c_str());
    qDebug()<<s.c_str();
    /*if(p=="Input")serial->write("/1IR\r");
    if(p=="Output")serial->write("/1OR\r");
    if(p=="Bypass")serial->write("/1BR\r");
    if(p=="Extra")serial->write("/1ER\r");*/
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
