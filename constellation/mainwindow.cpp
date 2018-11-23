#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtDataVisualization;
QSerialPort serial;
QScatter3DSeries *series;


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        // qDebug() << "Name : " << info.portName();
        //qDebug() << "Description : " << info.description();
        //qDebug() << "Manufacturer: " << info.manufacturer();

        serial.setPortName(info.portName());
        serial.setBaudRate(4800);
    }
    if (!serial.open(QIODevice::ReadWrite)){
        qDebug()<<"Error opening serial port !"<<endl;
    }else{
        qDebug()<<"Connected to"<<serial.portName()<<"at"<<serial.baudRate()<<"bauds"<<endl;

        connect(&serial, SIGNAL(readyRead()), this, SLOT(readData()));

        Q3DScatter *scatter = new Q3DScatter();
        ui->graphWidget=QWidget::createWindowContainer(scatter);
        series = new QScatter3DSeries;
        series->setItemSize(.1f);
       // series->setBaseColor(Qt::white);
        series->setColorStyle(Q3DTheme::ColorStyleObjectGradient);
        scatter->addSeries(series);
        scatter->axisX()->setTitle("r");
        scatter->axisY()->setTitle("g");
        scatter->axisZ()->setTitle("b");
        Q3DTheme* t=new Q3DTheme(Q3DTheme::ThemeEbony);
       // t->setBackgroundColor(Qt::black);
        scatter->setActiveTheme(t);
        ui->gridLayout->addWidget(ui->graphWidget, 4, 0, 1, 4);
    }
}

MainWindow::~MainWindow(){
    serial.close();
    delete ui;
}

void MainWindow::readData(){
    while (serial.canReadLine()){
        QByteArray data = serial.readLine();
        if(data.count(',')==2){
            int rgb[3];
            int i=0;
            data=data.chopped(2);
            QList<QByteArray> l=data.split(',');
            foreach(QByteArray b,l){
                rgb[i]=b.toInt();
                i++;
            }
            series->dataProxy()->addItem(QVector3D(rgb[0],rgb[1],rgb[2]));
        }
        //qDebug()<<data;
    }
}


void MainWindow::on_clearButton_clicked(){
    series->dataProxy()->resetArray(NULL);
}

void MainWindow::on_mode_clicked(){
    QByteArray a="c";
    a+=ui->spinBox->value()+48;
    a+="\r\n";
    qDebug()<<a;
    serial.write(a);
}
