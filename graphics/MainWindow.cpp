#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QGraphicsScene>
#include "myitem.h"
#include <QPainter>
#include <QGraphicsView>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene;
    QImage image(550, 550, QImage::Format_RGB32);
    QRectF rect(100.0, 200.1, 100.2, 16.3);
    scene->addRect(rect);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
