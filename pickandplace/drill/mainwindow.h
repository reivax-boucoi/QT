#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{D
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_nextButton_clicked();

    void on_parseButton_clicked();

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
