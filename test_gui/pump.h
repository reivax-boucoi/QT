#ifndef PUMP_H
#define PUMP_H

#include <QDebug>
#include <QSerialPort>

class Pump{
public:
    Pump();
    Pump(int a,QString p, uint bd);
    ~Pump();
    void initialize();
    void setPosition(uint p,char mode);
    uint getPosition();
    uint getPmax();
    uint getAddress();
    uint getBaudRate();
    QString getPort();
    bool isConnected();
protected :

private :
    QSerialPort *serial;
    uint address = 1;
    QString port="/dev/ttyUSB0";
    QSerialPort::BaudRate baud=QSerialPort::Baud38400;
    uint pos = 0; // 0 : origin (empty), 3000 : EOT (full)
    uint pmax = 3000;

    bool comminit();
};

#endif // PUMP_H
