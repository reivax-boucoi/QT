#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::white);
    for(int i=0;i<81;i++){
        grid[i].x=i%9;
        grid[i].y=i/9;
        grid[i].text = new QGraphicsTextItem();
        grid[i].rect = new QGraphicsRectItem();
        grid[i].text->setDefaultTextColor(Qt::black);
        grid[i].rect->setRect( grid[i].x*w, grid[i].y*w,w,w);
        grid[i].text->setPos(grid[i].x*w+w/2,grid[i].y*w+w/2);
        if(puzzle[i]!='.'){
            grid[i].state=defined;
            grid[i].nbs[0]=5;//atoi(char(puzzle[i]));
        }
        grid[i].nbs[0]=5;//atoi(char(puzzle[i])); //DEBUG
        displaybox(grid[i]);
        scene->addItem(grid[i].rect);
        scene->addItem(grid[i].text);
    }


    view = new QGraphicsView(scene);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    if(grid[2].rect->brush()==Qt::red){
        grid[2].rect->setBrush(Qt::green);
    }else{
        grid[2].rect->setBrush(Qt::red);
    }
}

void MainWindow::displaybox(MainWindow::box b){
    switch (b.state){
    case unknown:
        b.rect->setBrush(Qt::white);
        b.text->setPos(b.x*w+-b.text->textWidth()/2,b.y*w-b.text->textWidth()/2);
        //  b.text->setPlainText();
        break;
    case defined:
        b.rect->setBrush(Qt::lightGray);
        b.text->setPos(b.x*w+w/3,b.y*w+w/3-b.text->textWidth()/2);
        b.text->setPlainText(QString(b.nbs[0]));
        break;
    case user:
        b.rect->setBrush(Qt::blue);
        b.text->setPos(b.x*w+w/3,b.y*w+w/3-b.text->textWidth()/2);
        b.text->setPlainText(QString(b.nbs[0]));
        break;
    case found:
        b.rect->setBrush(Qt::green);
        b.text->setPos(b.x*w+w/3,b.y*w+w/3-b.text->textWidth()/2);
        b.text->setPlainText(QString(b.nbs[0]));
        break;
    }

}

int MainWindow::solve(int a){// -1 none | 0 success | nb nb solved

    int res = simplifyLine(a);
    res+= simplifyCol(a);
    res+= simplifySquare(a);
    checkFound(grid[a]);
    if(ui->methods->isChecked()){

    }
}

int MainWindow::simplifyLine(int a){
    int res=0;
    for(int n=0;n<9;n++){//for each possible number
        if(grid[a].nbs[n]!=0){//if contained in possibilities
            for(int i=0;i<9;i++){//for others in the line
                int index=i+a%9;
                if(index!=a && grid[index].state!=unknown && grid[index].nbs[0]==grid[a].nbs[n]){//if defined and common value and other
                    res++;
                    grid[a].nbs[n]=0; //remove fom possibilities
                }
            }
        }
    }
    return res;
}

int MainWindow::simplifyCol(int a){

    int res=0;
    return res;
}

int MainWindow::simplifySquare(int a){
    int res=0;
    return res;

}

void MainWindow::display(){
    for(int i=0;i<81;i++){
        displaybox(grid[i]);
        if(i==cnt)grid[i].rect->setBrush(Qt::yellow);
    }
}

void MainWindow::on_nextButton_clicked(){
    cnt++;
    if(cnt>80)cnt=0;
    display();
}

void MainWindow::on_prevButton_clicked(){
    cnt--;
    if(cnt<0)cnt=80;
    display();
}

void MainWindow::on_solveButton_clicked(){
    if(grid[cnt].state==unknown){
        ui->statusBar->showMessage("Solving...");
        int out=solve(cnt);
        std::string s = "";
        switch(out){
        case -1:
            s="Can't solve further for now";
            break;
        case 0:
            s="Solved !";
            break;
        default:
            s="Eliminated "+ std::to_string(out)+" possibilities";
            break;

        }
        ui->statusBar->showMessage(s.c_str(),3000);
    }else{
        ui->statusBar->showMessage("Already solved !",500);
    }
    display();
}

void MainWindow::checkFound(MainWindow::box b){
    int c=0;
    int j=0;
    for(int i=0;i<9;i++){
        if(b.nbs[i]!=0){
            c++;
            j=i;
        }
    }
    if(c==0){
        //help;
    }
    if(c==1){
        b.nbs[0]=b.nbs[j];
        b.state=found;
    }
}
