#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *topLayout = new QVBoxLayout();

    QPushButton *btRegion = new QPushButton(QString(tr("机房")));
    QPixmap icnRegion(tr(":/image/Region.png"));
    btRegion->setIcon(icnRegion);
    btRegion->setIconSize(QSize(100,100));
    btRegion->setGeometry(0,0,200,200);

//    setCentralWidget(btRegion);


    QPushButton *btCabicle = new QPushButton(QString(tr("机柜")));
    QPixmap icnCabicle =(tr(":/image/1.png"));
    btCabicle->setIcon(icnCabicle);
    btCabicle->setIconSize(QSize(100,100));
    btRegion->setGeometry(40,40,200,200);

    connect(btRegion,SIGNAL(clicked()),qApp,SLOT(quit()));

//    setCentralWidget(btCabicle);
    QTimer *timer3 = new QTimer();
    connect(timer3,SIGNAL(timeout()),this,SLOT(update()));
    timer3->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter paint(this);
    paint.setPen(Qt::DashLine);
    paint.setRenderHint(QPainter::Antialiasing,true);
    QPixmap ap1(":image/1.png");
    QPixmap ap2(":image/2.png");
    QPixmap ap3(":image/3.png");
    paint.drawPixmap(100,200,ap1);
    paint.drawPixmap(400,200,ap2);
    paint.drawPixmap(700,200,ap3);

    paint.drawLine(720,150,100,200);
    paint.drawLine(720,150,400,200);
    paint.drawLine(720,150,700,200);

}
