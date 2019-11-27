#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(this->ui->horizontalSlider,SIGNAL(valueChanged(int)),this->ui->spinBox,SLOT(setValue(int)));
    connect(this->ui->spinBox,SIGNAL(valueChanged(int)),this->ui->horizontalSlider,SLOT(setValue(int)));
}

Dialog::~Dialog()
{
    delete ui;
}
