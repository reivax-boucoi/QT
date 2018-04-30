#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_nextButton_clicked(){

}

void MainWindow::on_parseButton_clicked(){

}

void MainWindow::on_sendButton_clicked(){

}
