#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    painter.setPen(QColor(255,0,255));
    painter.setBrush(QBrush(QColor(255,255,0)));


    painter.drawLine(QPoint(0,0),QPoint(100,100));


    painter.drawText(200,200,"hello chess!");
    painter.drawEllipse(QPoint(200,300),50,50);
}
