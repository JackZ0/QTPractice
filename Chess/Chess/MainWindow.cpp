#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMouseEvent>
#include <QDebug>
#include <algorithm>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for( int i =0; i < 32; i++)
    {
        _s[i].init(i);
    }
    _r = 20;
    _selectid = -1;
    _bRetTurn = true;
//    _button = new QPushButton("this is button",this);

//    _button->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //绘制类
    // 绘制打印机、绘图、考屏幕
    QPainter painter(this);

    //划横线
    int d = 40;
    for(int i = 1 ; i <= 10; i++){
        painter.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }
    //画竖线
    for(int j=1; j <=9; ++j){
        if(j == 1 || j == 9){
            painter.drawLine(QPoint(j*d,d),QPoint(j*d,10*d));
        }
        else{
            painter.drawLine(QPoint(j*d,d),QPoint(j*d,5*d));
            painter.drawLine(QPoint(j*d,6*d),QPoint(j*d,10*d));
        }
    }

    // 画米线

    painter.drawLine(QPoint(4*d,1*d),QPoint(6*d,3*d));
    painter.drawLine(QPoint(6*d,1*d),QPoint(4*d,3*d));
    painter.drawLine(QPoint(4*d,8*d),QPoint(6*d,10*d));
    painter.drawLine(QPoint(6*d,8*d),QPoint(4*d,10*d));


    // 绘制32个棋子

    for (int i = 0; i < 32; i++){
        drawStone(painter,i);
    }

//    painter.setPen(QColor(255,0,255));
//    painter.setBrush(QBrush(QColor(255,255,0)));

    //    painter.drawEllipse(_ptClick,30,30);
}

void MainWindow::mousePressEvent(QMouseEvent *)
{

}
/**
 * @brief MainWindow::mouseReleaseEvent 鼠标事件获取位置
 * @param ev
 */
void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    QPoint pt = ev->pos();

    int row,col;
    bool bRet = getRowCol(pt,row,col);
    qDebug() << "row << col" << row << col << endl;
    if(bRet == false){
        return ;
    }

    int clickid = -1;
    for (int i = 0; i < 32; i++){
        if(_s[i]._row == row && _s[i]._col == col && _s[i]._dead == false){
            clickid = i;
            break;
        }
    }


    if(_selectid == -1){
        if(clickid != -1){
            if(_bRetTurn == _s[clickid]._red){
                _selectid = clickid;
                update();
            }

        }
    }
    else
    {
        if(canMove(_selectid,row,col,clickid)){
           //走棋
            _s[_selectid]._row = row;
            _s[_selectid]._col = col;
            if(clickid != -1){
                _s[clickid]._dead = true;
            }
            _selectid = -1;
            _bRetTurn = !_bRetTurn;
            update();
        }

    }
}

//void MainWindow::mousePressEvent(QMouseEvent *ev)
//{
//    // 得到鼠标点击的地方
//    _ptClick = ev->pos();

//    //强制程序进行重绘
//    update();

//}

void MainWindow::drawStone(QPainter & painter,int id)
{
    if(_s[id]._dead)
        return ;
    QPoint c = center(id);
    QRect rect = QRect(c.x()-_r,c.y()-_r,_r*2,_r*2);;
//    qDebug() <<"-----------"<< id << endl;
    if(id == _selectid){
        painter.setBrush(QBrush(Qt::gray));
    }
    else{
        painter.setBrush(QBrush(Qt::yellow));
    }
    painter.setPen(Qt::black);
    painter.drawEllipse(center(id),_r,_r);

    if(_s[id]._red){
        painter.setPen(Qt::red);
    }

//    painter.setFont(QFont("system",_r,70));

    painter.drawText(rect,_s[id].getText(),QTextOption(Qt::AlignCenter));
}

QPoint MainWindow::center(int row, int col)
{
    QPoint ret;
    ret.rx() = (col+1)* _r*2;
    ret.ry() = (row+1)* _r*2;
    return ret;

}

QPoint MainWindow::center(int id)
{
    return  center(_s[id]._row, _s[id]._col);
}


bool MainWindow::getRowCol(QPoint pt, int &row, int &col)
{
    for(row =0; row <=9 ; row++){
        for(col = 0; col <= 8; col++){
            QPoint c = center(row,col);
            int dx = c.x() - pt.x();
            int dy = c.y() - pt.y();
            int dist = dx*dx + dy*dy;
            if(dist < _r*_r){
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief MainWindow::canMove 判断是否可以移动
 * @param moveid
 * @param row
 * @param col
 * @param killid
 * @return
 */
bool MainWindow::canMove(int moveid, int row, int col, int killid)
{
    if(killid == -1){}
    else{


    //颜色相同的点不能移动
    if(_s[moveid]._red == _s[killid]._red )
    {
        _selectid = killid;
        update();
        return false;
    }

    switch (_s[moveid]._type) {
        case Stone::JIANG:
        return canMoveJiang(moveid,row,col,killid);
        case Stone::SHI:
        return canMoveShi(moveid,row,col,killid);
        case Stone::XIANG:
        return canMoveXiang(moveid,row,col,killid);
        case Stone::JU:
        return canMoveJu(moveid,row,col,killid);
        case Stone::MA:
        return canMoveMa(moveid,row,col,killid);
        case Stone::PAO:
        return canMove6(moveid,row,col,killid);
        case Stone::BING:
        return canMove7(moveid,row,col,killid);

    }
    }
    return true;

}
/**
 * @brief MainWindow::canMove1  规则1将的规则  在米字格里面 只能步长1个格子
 * @param moveid
 * @param row
 * @param col
 * @param killid
 * @return
 */
bool MainWindow::canMoveJiang(int moveid, int row, int col, int killid)
{
    if(_s[moveid]._red)
    {
        if(row >2) return false;
    }
    else{
        if(row <7)  return false;
    }
    if(col <3)
        return false;
    if(col > 5)
        return false;

    int dr = _s[moveid]._row -row;
    int dc = _s[moveid]._col -col;

    if(dr + dc  == 1)
        return true;
    return false;
}

/**
 * @brief MainWindow::canMove2  士規則
 * @param moveid
 * @param row
 * @param col
 * @param killid
 * @return
 */
bool MainWindow::canMoveShi(int moveid, int row, int col, int killid)
{
    if(_s[moveid]._red)
    {
        if(row >2) return false;
    }
    else{
        if(row <7)  return false;
    }
    if(col <3 || col > 5)
        return false;

    int dr = _s[moveid]._row -row;
    int dc = _s[moveid]._col -col;
//    int d = abs(dr)*10 + abs(dc);
    if( dr == 1 && dc == 1)
        return true;
    return false;
}

bool MainWindow::canMoveXiang(int moveid, int row, int col, int killid)
{
   if(_s[moveid]._red){
    if(row > 4)
       return false;
   }
   else
   {
       if(row < 5)
           return false;
   }
  int dy = abs(_s[moveid]._row - row);
  int dx = abs(_s[moveid]._col - col);
  if(dx == 2 && dy == 2){
      int r = (_s[moveid]._row + row)/2;
      int c = (_s[moveid]._col + col)/2;
      if(hasStone(r,c)) return false;
      return true;
      }

    return true;
}

bool MainWindow::canMoveJu(int moveid, int row, int col, int killid)
{
    if(_s[moveid]._row == row){
           if(hasStone(_s[moveid]._col,col,true,row,col)) return false;
           return true;
       }
       else if(_s[moveid]._col == col){
           if(hasStone(_s[moveid]._row,row,false,row,col)) return false;
           return true;
       }
       else {
           return false;
       }
}

bool MainWindow::canMoveMa(int moveid, int row, int col, int killid)
{
    return true;
}

bool MainWindow::canMove6(int moveid, int row, int col, int killid)
{
    return true;
}

bool MainWindow::canMove7(int moveid, int row, int col, int killid)
{
    return true;
}

int MainWindow::relation(int row1, int col1, int row, int col)
{
    return qAbs(row1-row)*10+qAbs(col1-col);
}



bool MainWindow::hasStone(int row, int col)
{
    for(int i=0;i<32;i++)
            if(_s[i]._dead==false && _s[i]._row == row && _s[i]._col == col)
                return true;
        return false;
}

int MainWindow::hasStone(int a, int b, bool bRow, int row, int col)
{
    int t = 0;
        int mn = min(a,b);
        int mx = max(a,b);
        for(int i=mn+1;i<mx;i++){
            if(bRow){
                if(hasStone(row,i)) t++;
            }
            else{
                if(hasStone(i,col)) t++;
            }
        }
        return t;
}
