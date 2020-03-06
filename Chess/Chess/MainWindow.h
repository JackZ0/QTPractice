#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>


#include "Stone.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *);

//    virtual void mousePressEvent(QMouseEvent *ev);
    Stone _s[32];
    int _r=20; //棋子半径
    QPushButton* _button;

    QPoint _ptClick;

    void drawStone(QPainter & painter,int id);
    QPoint center(int row,int col);
    QPoint center(int id);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
