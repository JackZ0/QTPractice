#include "convert.h"
#include "ui_convert.h"

Convert::Convert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Convert)
{
    ui->setupUi(this);
}

Convert::~Convert()
{
    delete ui;
}
