#include "cncinterface.h"
#include <QSerialPort>

cncinterface::cncinterface(){
    QSerialPort serialPort;
    const QString serialPortName =;
    serialPort.setPortName(serialPortName);
}
