#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
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
    void on_pushButton_clicked();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void on_solveButton_clicked();

private:
    Ui::MainWindow *ui;
    enum BoxState{unknown, defined, user, found};
    struct box{
        int x;
        int y;
        QGraphicsTextItem * text;
        int nbs[9]={1,2,3,4,5,6,7,8,9};
        QGraphicsRectItem * rect;
        BoxState state=unknown;
    }grid[81];
    void checkFound(box b);
    void displaybox(box b);
    int simplifyLine(int a);
    int simplifyCol(int a);
    int simplifySquare(int a);
    int solve(int a);
    void display();
    int w=55;
    int cnt=0;
    QString puzzle = "6.......7....9..2.3.1..259.8....7.13....8....76.3....8.782..1.6.5..3....2.......9";
    QGraphicsScene * scene;
    QGraphicsView * view ;
};

#endif // MAINWINDOW_H
