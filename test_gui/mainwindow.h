#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_initbutton_clicked();


    void on_plungermovebutton_clicked();

    void on_radioButton_absolute_clicked();

    void on_radioButton_pickup_clicked();

    void on_radioButton_dispense_clicked();


    void on_pushButton_connect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
