#ifndef PUMP_H
#define PUMP_H

#include <QDebug>
#include <QSerialPort>

class Pump{
public:
    Pump();
    Pump(int a,QSerialPort *s);
    ~Pump();
    void initialize();
    void setPosition(uint p, char mode);
    void setValve(QString p);
    uint getPosition();
    uint getPmax();
    uint getAddress();
protected :

private :
    uint pos = 0; // 0 : origin (empty), 3000 : EOT (full)
    uint address = 1;
    uint pmax = 3000;
    QSerialPort *serial;
};

#endif // PUMP_H
