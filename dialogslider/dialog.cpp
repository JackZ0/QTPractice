#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    movie = new QMovie(":/img/greenled.gif");
    movie2 = new QMovie(":/img/redled.gif");

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
        ui->label->setGeometry(0,0,40,40);
        movie2->setScaledSize(QSize(40,40));
        ui->label->setMovie(movie2);

        movie2->start();
         isplaying = false;

    }
    else{
        ui->label->setGeometry(0,0,40,40);
        movie->setScaledSize(QSize(40,40));
        ui->label->setMovie(movie);
        movie->start();
        isplaying = true;
    }
}

void Dialog::on_pushButton_2_clicked()
{
    if(isplaying2){
        movie2->stop();
        isplaying2 = false;
    }
    else{
        ui->warning->setGeometry(100,0,40,40);
        movie2->setScaledSize(QSize(40,40));
        ui->warning->setMovie(movie2);
        movie2->start();
        isplaying2 = true;
    }
}
