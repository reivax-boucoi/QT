#ifndef TURTLE_H
#define TURTLE_H

#include <QtMath>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>

class Turtle{
public:

    Turtle(QGraphicsScene* scene);
    Turtle(QGraphicsScene* scene,float x,float y,float angle);
    void clear(void);
    void home(void);
    void penOnOff(bool onoff);
    bool penOnOff(void);
    void fw(float d);
    void turn(float a);
    void execute(QString str);


private:
    QGraphicsScene* scene;
    QPen* pen;
    float x=0;
    float y=0;
    float angle;
    bool penUp=false;

};

#endif // TURTLE_H
