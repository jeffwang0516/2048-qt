#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "points.h"
#include<time.h>
#include<QString>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pointCnt = new Points();
    srand(time(NULL));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid[i][j]=0;
            lastgrid[i][j]=0;
            regretgrid[i][j]=0;
        }
    }
    //radomly choose two grids to start
    grid[rand()%4][rand()%4]=2;
    grid[rand()%4][rand()%4]=2;
    ifMove=false;
    ui->setupUi(this);
    ui->label->setText(NULL);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setText(NULL);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setText(NULL);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setText(NULL);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_5->setText(NULL);
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_6->setText(NULL);
    ui->label_6->setAlignment(Qt::AlignCenter);
    ui->label_7->setText(NULL);
    ui->label_7->setAlignment(Qt::AlignCenter);
    ui->label_8->setText(NULL);
    ui->label_8->setAlignment(Qt::AlignCenter);
    ui->label_9->setText(NULL);
    ui->label_9->setAlignment(Qt::AlignCenter);
    ui->label_10->setText(NULL);
    ui->label_10->setAlignment(Qt::AlignCenter);
    ui->label_11->setText(NULL);
    ui->label_11->setAlignment(Qt::AlignCenter);
    ui->label_12->setText(NULL);
    ui->label_12->setAlignment(Qt::AlignCenter);
    ui->label_13->setText(NULL);
    ui->label_13->setAlignment(Qt::AlignCenter);
    ui->label_14->setText(NULL);
    ui->label_14->setAlignment(Qt::AlignCenter);
    ui->label_15->setText(NULL);
    ui->label_15->setAlignment(Qt::AlignCenter);
    ui->label_16->setText(NULL);
    ui->label_16->setAlignment(Qt::AlignCenter);
    //label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //std::string aa;aa=intstr(grid[0][0]);
    refreshBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//the restart button FUNC
void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("font: 26pt\"MV Boli\";color: rgb(255, 8, 32)");
}
void MainWindow::on_pushButton_released()
{
    pointCnt->backZero();
    ui->pushButton->setStyleSheet("font: 26pt\"MV Boli\";color: rgb(26, 144, 255)");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid[i][j]=0;
            lastgrid[i][j]=0;
            regretgrid[i][j]=0;
        }
    }

    grid[rand()%4][rand()%4]=2;
    grid[rand()%4][rand()%4]=2;
    showLabel();
    ui->pushButton_2->show();
    setStyleSheet("background-color:black;");
    refreshBoard();
}
void MainWindow::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("font: 36pt \"Narkisim\";color: rgb(26, 144, 255)");
}
void MainWindow::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("font: 36pt \"Narkisim\";color: rgb(255, 34, 56);");
    if(pointCnt->get()>0&&pointCnt->get()>=pointCnt->prev()){
      for(int i = 0; i<4; ++i)
          for(int j = 0; j<4; ++j)
              grid[i][j]=lastgrid[i][j];
      pointCnt->changePoint(-3);
      refreshBoard();
    }
}
void MainWindow::moveUp(int i,int j)
{
  if(grid[i][j]!=0){
    bool bump=false;
    int newi;
    newi=i-1;
    while(grid[newi][j]==0&&bound(newi,j))
        newi=newi-1;
    if(bound(newi,j)==false){
        grid[0][j]=grid[i][j];
        //ifMove=true;
    }else{
        if(grid[newi][j]==grid[i][j]&&!ifCombined[newi][j]){
            bump=true;
            grid[newi][j] *= 2;
            ifCombined[newi][j]=true;
            //ifMove=true;
        }else{
            grid[newi+1][j]=grid[i][j];
            //ifMove=true;
        }
    }
    if(newi+1 !=i || bump)
        grid[i][j]=0;
  }
}
void MainWindow::moveDown(int i,int j)
{
  if(grid[i][j]!=0){
    bool bump=false;
    int newi;
    newi=i+1;
    while(grid[newi][j]==0&&bound(newi,j))
        newi=newi+1;
    if(bound(newi,j)==false){
        grid[3][j]=grid[i][j];
        //ifMove=true;
    }else{
        if(grid[newi][j]==grid[i][j]&&!ifCombined[newi][j]){
            bump=true;
            grid[newi][j] *= 2;
            ifCombined[newi][j]=true;
            //ifMove=true;
        }else{
            grid[newi-1][j]=grid[i][j];
            //ifMove=true;
        }
    }
    if(newi-1 !=i || bump)
        grid[i][j]=0;
  }
}
void MainWindow::moveRight(int i,int j)
{
  if(grid[i][j]!=0){
    bool bump=false;
    int newj;
    newj=j+1;
    while(grid[i][newj]==0&&bound(i,newj))
        newj=newj+1;
    if(bound(i,newj)==false){
        grid[i][3]=grid[i][j];
        //ifMove=true;
    }else{
        if(grid[i][newj]==grid[i][j]&&!ifCombined[i][newj]){
            bump=true;
            grid[i][newj] *= 2;
            ifCombined[i][newj]=true;
            //ifMove=true;
        }else{
            grid[i][newj-1]=grid[i][j];
            //ifMove=true;
        }
    }
    if(newj-1 !=j || bump)
        grid[i][j]=0;
  }
}
void MainWindow::moveLeft(int i,int j)
{
  if(grid[i][j]!=0){
    bool bump=false;
    int newj;
    newj=j-1;
    while(grid[i][newj]==0&&bound(i,newj))
        newj=newj-1;
    if(bound(i,newj)==false){
        grid[i][0]=grid[i][j];
        //ifMove=true;
    }else{
        if(grid[i][newj]==grid[i][j]&&!ifCombined[i][newj]){
            bump=true;
            grid[i][newj] *= 2;
            ifCombined[i][newj]=true;
            //ifMove=true;
        }else{
            grid[i][newj+1]=grid[i][j];
            //ifMove=true;
        }
    }
    if(newj+1 !=j || bump)
        grid[i][j]=0;
  }
}
//check if out of bound
bool MainWindow::bound(int i,int j)
{
    if(i>=0&&j>=0&&i<4&&j<4)
        return true;
    else
        return false;
}
//check if there isn't any blanks
bool MainWindow::allNonZero()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j]==0)
                return false;
        }
    }
    return true;
}
//check if there's still possible moves
int MainWindow::possible()
{
    if(allNonZero()==true){
        bool poss=false;
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                  moveUp(i,j);
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                if(grid[i][j]!=lastgrid[i][j])
                    poss=true;
        if(poss){
            for(int i = 0; i<4; ++i)
                for(int j = 0; j<4; ++j)
                    grid[i][j]=lastgrid[i][j];

            return 3;
        }
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                  moveDown(i,j);
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                if(grid[i][j]!=lastgrid[i][j])
                    poss=true;
        if(poss){
            for(int i = 0; i<4; ++i)
                for(int j = 0; j<4; ++j)
                    grid[i][j]=lastgrid[i][j];

            return 3;
        }
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                  moveRight(i,j);
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                if(grid[i][j]!=lastgrid[i][j])
                    poss=true;
        if(poss){
            for(int i = 0; i<4; ++i)
                for(int j = 0; j<4; ++j)
                    grid[i][j]=lastgrid[i][j];

            return 3;
        }
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                  moveLeft(i,j);
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                if(grid[i][j]!=lastgrid[i][j])
                    poss=true;
        if(poss){
            for(int i = 0; i<4; ++i)
                for(int j = 0; j<4; ++j)
                    grid[i][j]=lastgrid[i][j];

            return 3;
        }
        return 2;

    }
    return 1;

}

void MainWindow::refreshBoard()
{
    ui->label->setText(grid[0][0]==0?" ":QString::number(grid[0][0]));
    ui->label_2->setText(grid[0][1]==0?" ":QString::number(grid[0][1]));
    ui->label_3->setText(grid[0][2]==0?" ":QString::number(grid[0][2]));
    ui->label_4->setText(grid[0][3]==0?" ":QString::number(grid[0][3]));
    ui->label_5->setText(grid[1][0]==0?" ":QString::number(grid[1][0]));
    ui->label_6->setText(grid[1][1]==0?" ":QString::number(grid[1][1]));
    ui->label_7->setText(grid[1][2]==0?" ":QString::number(grid[1][2]));
    ui->label_8->setText(grid[1][3]==0?" ":QString::number(grid[1][3]));
    ui->label_9->setText(grid[2][0]==0?" ":QString::number(grid[2][0]));
    ui->label_10->setText(grid[2][1]==0?" ":QString::number(grid[2][1]));
    ui->label_11->setText(grid[2][2]==0?" ":QString::number(grid[2][2]));
    ui->label_12->setText(grid[2][3]==0?" ":QString::number(grid[2][3]));
    ui->label_13->setText(grid[3][0]==0?" ":QString::number(grid[3][0]));
    ui->label_14->setText(grid[3][1]==0?" ":QString::number(grid[3][1]));
    ui->label_15->setText(grid[3][2]==0?" ":QString::number(grid[3][2]));
    ui->label_16->setText(grid[3][3]==0?" ":QString::number(grid[3][3]));
    ui->label_17->setText("SCORE:"+QString::number(pointCnt->get()));//points

}
/*
 rgb(170, 255, 0)rgb(85, 170, 255)rgb(0, 170, 255)rgb(255, 255, 127)
origin:background-color: rgb(41, 255, 209);*/
void MainWindow::keyPressEvent(QKeyEvent *event)
{

  if(event->key() == Qt::Key_Up||event->key() == Qt::Key_Down||event->key() == Qt::Key_Right||event->key() == Qt::Key_Left){
      for(int i=0;i<4;i++)
          for(int j=0;j<4;j++){
              ifCombined[i][j]=false;
              regretgrid[i][j]=lastgrid[i][j];
          }
    ifMove=false;
    if(event->key() == Qt::Key_Up){
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                  moveUp(i,j);
    }


    if(event->key() == Qt::Key_Down){
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 3; i>=0; --i)
            for(int j = 0; j<4; ++j)
                  moveDown(i,j);


    }
    if(event->key() == Qt::Key_Right){
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 0; i<4; ++i)
            for(int j =3; j>=0; --j)
                  moveRight(i,j);


    }
    if(event->key() == Qt::Key_Left){
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                lastgrid[i][j]=grid[i][j];
        for(int i = 0; i<4; ++i)
            for(int j = 0; j<4; ++j)
                  moveLeft(i,j);

    }
    /*TESTING when 2048 occurs
    if(event->key() == Qt::Key_D){
        grid[2][2]=2048;
    }
    */

    for(int i = 0; i<4; ++i)
        for(int j = 0; j<4; ++j)
            if(grid[i][j]!=lastgrid[i][j])
                ifMove=true;
    if(!ifMove){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){

            lastgrid[i][j]=regretgrid[i][j];
        }
    }
    if(ifMove){

        pointCnt->changePoint(5);//plus five points
        //prepoints=points;
        int a,b;
        while(1){
            a=rand()%4;b=rand()%4;
            if(grid[a][b]==0){
                grid[a][b]=rand()%100>91?4:2;
                break;
            }
        }
        refreshBoard();
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j]==2048){
                hideLabel();
                ui->pushButton_2->hide();
                setStyleSheet("background-image: url(:/WIN.png);");
                for(int i=0;i<4;i++){
                    for(int j=0;j<4;j++){
                        grid[i][j]=0;
                    }
                }

                grid[rand()%4][rand()%4]=2;
                grid[rand()%4][rand()%4]=2;
            }
        }
    }
    if(possible()==2){
        hideLabel();
        ui->pushButton_2->hide();
        setStyleSheet("background-image: url(:/LOSE.png);");
    }
  }
}
void MainWindow::showLabel()
{
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->label_10->show();
    ui->label_11->show();
    ui->label_12->show();
    ui->label_13->show();
    ui->label_14->show();
    ui->label_15->show();
    ui->label_16->show();
    ui->label_18->show();
}
void MainWindow::hideLabel()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
    ui->label_15->hide();
    ui->label_16->hide();
    ui->label_18->hide();
}


