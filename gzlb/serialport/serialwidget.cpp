#include "serialwidget.h"
#include "ui_serialwidget.h"

serialWidget::serialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serialWidget)
{
    ui->setupUi(this);
}

serialWidget::~serialWidget()
{
    delete ui;
}
