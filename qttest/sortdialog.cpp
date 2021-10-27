#include "sortdialog.h"
#include "ui_sortdialog.h"

sortDialog::sortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortDialog)
{
    ui->setupUi(this);
    ui->SecondaryGroupBox->hide();
    ui->TertiaryGroupBox->hide();
    setColumnRange('A','Z');
}

sortDialog::~sortDialog()
{
    delete ui;
}

void sortDialog::setColumnRange(QChar first, QChar last)
{
    ui->PrimaryColumnCombo->clear();
    ui->secondaryColumnCombo->clear();
    ui->tertiaryColumnCombo->clear();

    ui->secondaryColumnCombo->addItem(tr("None"));
    ui->tertiaryColumnCombo->addItem(tr("None"));
    ui->primaryOrderCombo->setMinimumSize(ui->secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while(ch <= last)
    {
        ui->PrimaryColumnCombo->addItem(QString(ch));
        ui->tertiaryColumnCombo->addItem(QString(ch));
        ui->secondaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode()+1;
    }
}
