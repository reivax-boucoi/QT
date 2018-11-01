#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setBackgroundBrush(Qt::white);
    view->show();
    t=new Turtle(scene,50.0,50.0,0.0);
    t->penOnOff(1);
}

MainWindow::~MainWindow(){
    delete view;
    delete ui;
}

void MainWindow::on_runButton_clicked(){
    qDebug()<<"Run"<<endl;
    //t->execute(ui->textEdit->toPlainText());
}

void MainWindow::on_clearAllButton_clicked(){
    t->clear();
    t->home();
    ui->textEdit->clear();
}
void MainWindow::on_clearScreenButton_clicked(){
    t->clear();
    t->home();
}
