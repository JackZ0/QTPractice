#include "ConfigDialog.h"
#include "ui_ConfigDialog.h"
#include <QIntValidator>

ConfigDialog::ConfigDialog(int cw,int ch, int cm,QWidget *parent) :
    _width(cw),
    _height(ch),
    _mines(cm),
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    QIntValidator * valid = new QIntValidator(0,100,this);
    ui->LineEditWidth->setValidator(valid);
    ui->lineEditHeight->setValidator(valid);
    ui->lineEditMines->setValidator(valid);

    ui->LineEditWidth->setText(QString::number(_width));
    ui->lineEditHeight->setText(QString::number(_height));
    ui->lineEditMines->setText(QString::number(_mines));


}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::accept()
{
    _width = ui->LineEditWidth->text().toInt();
    _height = ui->lineEditHeight->text().toInt();
    _mines = ui->lineEditMines->text().toInt();

    QDialog::accept();
}
