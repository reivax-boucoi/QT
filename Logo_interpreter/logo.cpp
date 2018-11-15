#include "logo.h"

/*
    {"pu",0},
    {"pd",0},
    {"lt",1},
    {"rt",1},
    {"fw",1},
    {"repeat",2}
*/
Logo::Logo(Turtle *t){
    this->t=t;
    this->cmds=
}

void Logo::execute(QString str){
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
                command(cm[i],arg);
                i++;
            }else{
                qDebug()<<"No argument provided for cmd "<<cm[i]<<" !"<<endl;
            }
        }
    }
}

void Logo::command(QString cmd, int arg){

    if(cmd== "fw"){
        t->fw(arg);
        qDebug()<<"Moved fw "<<arg<<endl;
    }else if(cmd== "lt"){
        t->turn(-arg);
    }else if(cmd== "rt"){
        t->turn(arg);
    }else if(cmd== "pu"){
        t->penOnOff(0);
    }else if(cmd== "pd"){
        t->penOnOff(1);
    }else{
        qDebug()<<"Unknown command \""<<cmd<<"\" !"<<endl;
    }
}
