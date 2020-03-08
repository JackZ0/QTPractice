#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>


#include "Stone.h"

namespace Ui {
class MainWindow;
}

class Board : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    virtual void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

//    virtual void mousePressEvent(QMouseEvent *ev);


    void drawStone(QPainter & painter,int id);
    QPoint center(int row,int col);
    QPoint center(int id);
    bool getRowCol(QPoint pt, int &row, int &col);
    bool canMove(int moveid, int row, int col, int killid);
    bool canMoveJiang(int moveid, int row, int col, int killid);
    bool canMoveShi(int moveid, int row, int col, int killid);
    bool canMoveXiang(int moveid, int row, int col, int killid);
    bool canMoveJu(int moveid, int row, int col, int );
    bool canMoveMa(int moveid, int row, int col, int killid);
    bool canMovePao(int moveid, int row, int col, int killid);
    bool canMoveBing(int moveid, int row, int col, int );

    int relation(int row1,int col1,int row, int col);

    bool hasStone(int row,int col);
    int hasStone(int a, int b, bool bRow, int row,int col);


    Stone _s[32];
    int _r; //棋子半径
    QPushButton* _button;

    QPoint _ptClick;
    int _selectid;
    bool _bRetTurn;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
