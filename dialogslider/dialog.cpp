#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    movie = new QMovie(":/img/timg.gif");
//    movie2 = new QMovie(":/img/timg.gif");

    connect(this->ui->horizontalSlider,SIGNAL(valueChanged(int)),this->ui->spinBox,SLOT(setValue(int)));
    connect(this->ui->spinBox,SIGNAL(valueChanged(int)),this->ui->horizontalSlider,SLOT(setValue(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    if(isplaying){
        movie->stop();
        isplaying = false;
    }
    else{
        ui->label->setMovie(movie);
        movie->start();
        isplaying = true;
    }
}

void Dialog::on_pushButton_2_clicked()
{
    if(isplaying){
        movie->stop();
        isplaying = false;
    }
    else{
        ui->label_2->setMovie(movie);
        movie->start();
        isplaying = true;
    }
}
