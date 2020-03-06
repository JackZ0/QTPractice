#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _button = new QPushButton("this is button",this);
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

    painter.setPen(QColor(255,0,255));
    painter.setBrush(QBrush(QColor(255,255,0)));


//    painter.drawLine(QPoint(0,0),QPoint(100,100));


//    painter.drawText(200,200,"hello chess!");
//    painter.drawEllipse(QPoint(200,300),50,50);
    painter.drawEllipse(_ptClick,30,30);
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    // 得到鼠标点击的地方
    _ptClick = ev->pos();

    //强制程序进行重绘
    update();

}
