#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define PREFIX "/1"
#define PORT "/dev/ttyUSB0"
#define BAUD 38400
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
    void serialReceived();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
