#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
    #include <QtWidgets>
#include <opencv2/opencv.hpp>

cv::VideoCapture wc;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    wc.open(1);
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButtonCam_clicked(){
    cv::Mat frame;
    if(!wc.isOpened()){
        qDebug()<<"No video";
    }else{
        wc.read(frame);
        if(frame.empty()){
            qDebug()<<"Empty frame";
        }
        cv::cvtColor(frame,frame,CV_BGR2RGB);
       // cv::imshow("WC",frame);
        QImage imgIn= QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        QGraphicsPixmapItem item( QPixmap::fromImage(imgIn));
        QGraphicsScene *scene = new QGraphicsScene;
        scene->addItem(&item);
        ui->graphicsViewCam->setScene(scene);
        ui->graphicsViewCam->show();
        qDebug()<<"Displayed";
    }
}
