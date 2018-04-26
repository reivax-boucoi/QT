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

    bool comminit();

    void pumpControls(bool on);

private slots:

    void serialReceived();

    void on_initbutton_clicked();

    void on_plungermovebutton_clicked();

    void on_radioButton_absolute_clicked();

    void on_radioButton_pickup_clicked();

    void on_radioButton_dispense_clicked();

    void on_pushButton_connect_clicked();

    void on_comboBox_valve_activated(const QString &arg1);

    void on_pushButton_cycle_clicked();

    void on_pushButton_zeroall_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
