#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include<QLabel>
#include<string>
#include "points.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void moveUp(int i, int j);   
    void moveDown(int i, int j);
    void moveRight(int i, int j);
    void moveLeft(int i, int j);
    bool bound(int i, int j);
    bool allNonZero();
    int possible();
    void refreshBoard();
    void showLabel();
    void hideLabel();
private slots:
    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_pushButton_2_pressed();
    void on_pushButton_2_released();

protected:


private:
    int grid[4][4];
    int lastgrid[4][4];
    bool ifCombined[4][4];
    bool ifMove;
    Points *pointCnt;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
