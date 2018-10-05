#include "turtle.h"

Turtle::Turtle(QGraphicsScene *scene, float x, float y, float angle){
    this->scene=scene;
    this->x=x;
    this->y=y;
    this->angle=angle;
    pen=new QPen(Qt::black,3,Qt::SolidLine,Qt::RoundCap);

    cmdLookUp["fw"]={&Turtle::cmd_fw,1};
    cmdLookUp["pu"]={&Turtle::cmd_pu,0};
    cmdLookUp["pd"]={&Turtle::cmd_pd,0};/*
    cmdLookUp["lt"]=cmd_lt;
    cmdLookUp["rt"]=cmd_rt;*/
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

void Turtle::cmd_pu(float a){
    penOnOff(0);
}
void Turtle::cmd_pd(float a){
    penOnOff(1);
}
void Turtle::execute(QString str){
    if(str.length()<2){
        qDebug()<<"Too short !"<<endl;
        return;
    }
    QStringList cm = str.split(" ");
    for(int i=0;i<cm.size()-1;i++){
        if(cm[i]=="repeat"){
            int arg=cm[i+1].toInt();
            if(arg){

            }else{
                qDebug()<<"Missing argument for command repeat"<<endl;
            }

        }
        if(cmdLookUp.find(cm[i])!=cmdLookUp.end()){//if is a command
            cmd_t cmd = cmdLookUp[cm[i]];
            if(cmd.nb_args){//if requires arguments
                int arg=cm[i+1].toInt();
                if(!arg){
                    qDebug()<<"Missing argument for command\""<<cm[i]<<"\"!"<<endl;
                }else{
                    i++;
                     (*(cmd.fn_ptr))(arg);
                    qDebug()<<"Run "<<cm[i-1]<<" with arg "<<arg<<endl;
                }
            }else{
                (*(cmd.fn_ptr))(0);
            }
        }else{
            qDebug()<<"unknown command \""<<cm[i]<<"\"!"<<endl;
        }
    }
}

