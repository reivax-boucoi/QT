#include "turtle.h"


Turtle::Turtle(QGraphicsScene *scene){
    this->scene=scene;
    pen=new QPen(Qt::black,3,Qt::SolidLine,Qt::RoundCap);
}

Turtle::Turtle(QGraphicsScene *scene, float x, float y, float angle){
    this->scene=scene;
    this->x=x;
    this->y=y;
    this->angle=angle;
    pen=new QPen(Qt::black,3,Qt::SolidLine,Qt::RoundCap);
}

void Turtle::clear(){
    scene->clear();
}

void Turtle::home(){
   //penOnOff(0);
    x=0;
    y=0;
    angle=0;
}

void Turtle::penOnOff(bool onoff){
    penUp=!onoff;
}

void Turtle::fw(float d){
    float x1=x+d*qCos(qDegreesToRadians(angle));
    float y1=y+d*qSin(qDegreesToRadians(angle));
    if(!penUp){
    QGraphicsLineItem* line=new QGraphicsLineItem(x,y,x1,y1);
    line->setPen(*pen);
    scene->addItem(line);
    }
    x=x1;
    y=y1;

}

void Turtle::turn(float a){
    angle+=a;
}
