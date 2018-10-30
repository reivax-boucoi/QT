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
    void cmd_penOnOff(bool onoff);
    void cmd_fw(float d);
    void cmd_tr(float a);
    void cmd_tl(float a);
    void execute(QString str);


private:
    QGraphicsScene* scene;
    QPen* pen;
    float x=0;
    float y=0;
    float angle;
    bool penUp=false;
    typedef void (*fn_ptr)(float);
    std::map<QString , fn_ptr> cmdLookUp;

};

#endif // TURTLE_H
