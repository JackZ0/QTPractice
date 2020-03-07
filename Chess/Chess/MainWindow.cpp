#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for( int i =0; i < 32; i++)
    {
        _s[i].init(i);
    }
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

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    QPoint pt = ev->pos();

    int row,col;
    bool bRet = getRowCol(pt,row,col);
    qDebug() << "row << col" << row << col << endl;
    if(bRet == false){
        return ;
    }

    int i ;
    int clickid = -1;
    for (i = 0; i < 32; i++){
        if(_s[i]._row == row && _s[i]._col == col && _s[i]._dead == false){
            break;
        }
    }
    if(i < 32){
        clickid = i;
    }

    if(_selectid == -1){
        if(clickid != -1){
            _selectid = clickid;
            update();
        }
    }
    else
    {
        _s[_selectid]._row = row;
        _s[_selectid]._col = col;
        if(clickid != -1){
            _s[clickid]._dead = true;
        }
        update();
    }


    //pt 转换成象棋的行列值
    // 判断这个行列中有没有象棋子


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
    qDebug() <<"-----------"<< id << endl;
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
