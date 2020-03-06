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
    painter.drawLine(QPoint(0,0),QPoint(100,100));
}
