#include "operationdialog.h"
#include "ui_operationdialog.h"

operationDialog::operationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::operationDialog)
{
    ui->setupUi(this);
}

operationDialog::~operationDialog()
{
    delete ui;
}
