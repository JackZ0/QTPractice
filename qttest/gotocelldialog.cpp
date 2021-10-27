#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegExp>
#include <QRegularExpressionValidator>
#include <QRegExpValidator>
GoToCellDialog::GoToCellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    this->ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));
    connect(this->ui->okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(this->ui->cancellButton,SIGNAL(clicked()),this,SLOT(reject()));

}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::on_lineEdit_textChanged(const QString &arg1)
{
   this->ui->okButton->setEnabled(this->ui->lineEdit->hasAcceptableInput());
}
