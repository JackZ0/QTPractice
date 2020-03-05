#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QGraphicsTextItem>
#include <QDebug>
#include <QMessageBox>
#include "ConfigDialog.h"
#include "FieldData.h"
#include "MineSweepScene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FieldData::getInstance();

    _view = new QGraphicsView;
    this->setCentralWidget(_view);

    _scene = new MineSweepScene;
    _view->setScene(_scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DrawRect(int posx, int posy, QString lable,QGraphicsScene *scenePare)
{
//    QGraphicsScene *scene = new QGraphicsScene;
//    QImage image(550, 550, QImage::Format_RGB32);
    QGraphicsTextItem *txtitem = new QGraphicsTextItem("text");

    for(int i=0; i < 10;i++){
        scenePare->addRect(QRect(posx+i*100,posy,100,50));
        txtitem->setPos(posx+i*100,posy);
        scenePare->addSimpleText("i23");
        scenePare->addItem(txtitem);
    }
}



void MainWindow::on_actionStart_triggered()
{

}

void MainWindow::on_actionStop_triggered()
{

}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"关于","软件使用v1.0版本");
}

void MainWindow::on_actionConf_triggered()
{
    ConfigDialog confDialog(Field->getHeight(),Field->getWidth(),Field->getMines());
    if(confDialog.exec() == QDialog::Accepted){
        if(confDialog._mines < confDialog._width*confDialog._height*0.5){
            Field->customise(confDialog._width,confDialog._height,confDialog._mines);
            Field->reset();
        }
        else{
            QMessageBox::warning(this,"雷数","雷数过多怎么玩！");
        }

    }
}
