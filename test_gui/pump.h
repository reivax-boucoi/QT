#ifndef PUMP_H
#define PUMP_H

#include <QDebug>

#include <QSerialPort>
//#include <QMainWindow>

class Pump{
public:
    Pump();
    Pump(char a,QString p, QSerialPort::BaudRate bd);
    ~Pump();
    void initialize();
    void setPosition(uint p,char mode);
protected :

private :
    QSerialPort *serial;
    char address =1;
    QString port="/dev/ttyUSB0";
    QSerialPort::BaudRate baud=QSerialPort::Baud38400;
    uint pos = 0; // 0 : origin (empty), 3000 : EOT (full)
    uint pmax = 3000;

    bool comminit();
};

#endif // PUMP_H
