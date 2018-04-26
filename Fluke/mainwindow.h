#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_request_clicked();

    void on_pushButton_Hold_clicked();

    void on_pushButton_hv_clicked();

    void on_pushButton_connect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
