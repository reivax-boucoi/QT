#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <opencv2/opencv.hpp>

cv::Mat frame;
cv::VideoCapture wc;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    wc.open(1);
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButtonCam_clicked(){
    if(!wc.isOpened()){
        qDebug()<<"No video";
    }else{
        wc.read(frame);
        if(frame.empty()){
            qDebug()<<"Empty frame";
        }
        cv::cvtColor(frame,frame,CV_BGR2GRAY);
        cv::imshow("WC",frame);
    }
}
