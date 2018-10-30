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

void Turtle::cmd_penOnOff(bool onoff){
    penUp=!onoff;
}

void Turtle::cmd_fw(float d){
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

void Turtle::cmd_tr(float a){
    angle+=a;
}
void Turtle::cmd_tl(float a){
    cmd_tr(-a);
}
void Turtle::execute(QString str){
    if(str.length()<2){
        qDebug()<<"Too short !"<<endl;
        return;
    }
    QStringList cm = str.split(" ");
    for(int i=0;i<cm.size()-1;i++){
        if(cm[i]=="repeat"){

        }else{
            int arg=cm[i+1].toInt();
            if(arg!=0){
                //command(cm[i],arg);
                i++;
            }else{
                qDebug()<<"No argument provided for cmd "<<cm[i]<<" !"<<endl;
            }
        }
    }
}

