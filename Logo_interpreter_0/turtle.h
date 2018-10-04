#ifndef TURTLE_H
#define TURTLE_H

#include <QtMath>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>

class Turtle{
public:
    Turtle(QGraphicsScene* scene,float x,float y,float angle);
    void clear(void);
    void home(void);
    void penOnOff(bool onoff);
    void cmd_fw(float d);
    void cmd_tr(float a);
    void cmd_tl(float a);
    void cmd_pu(float a);
    void cmd_pd(float a);
    void execute(QString str);


private:
    QGraphicsScene* scene;
    QPen* pen;
    float x=0;
    float y=0;
    float angle;
    bool penUp=false;
    struct cmd_t{
        void (Turtle::*fn_ptr)(float);
        int nb_args;
    };
    typedef struct cmd_t cmd_t;
    static std::map<QString , cmd_t> cmdLookUp;

};

#endif // TURTLE_H
