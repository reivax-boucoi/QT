#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    qDebug()<<"Pressed!";
}

void MainWindow::on_actionExit_triggered(){
    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Confirmation","Do you really want to quit logger_test ?", QMessageBox::Yes| QMessageBox::Cancel);
    if(confirm==QMessageBox::Yes){
        QApplication::quit();
    }
}

void MainWindow::on_actionClear_2_triggered(){
    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Confirmation","Do you really want to clear log ?", QMessageBox::Yes, QMessageBox::No);
    if(confirm==QMessageBox::Yes){
        logStr.clear();
        ui->textEdit->setText(QString());
    }
}

void MainWindow::on_actionSave_data_triggered(){

    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}
