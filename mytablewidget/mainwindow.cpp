#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QDebug>
int row=0;
QList <QTableWidgetItem *> item;
//QList <QTableWidgetItem *> item2;
//QList <QTableWidgetItem *> item3;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    item = ui->tableWidget->findItems("", Qt::MatchContains);
    ui->tableWidget->setCurrentCell(item.at(row)->row(),0);


//  item2 = ui->tableWidget->findItems("2", Qt::MatchExactly);
//  item3 = ui->tableWidget->findItems("3", Qt::MatchExactly);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_6_clicked()
{
    if(row>0)
            {row--;}
        qDebug()<<row;
    qDebug()<<item.at(row)->row();

   ui->tableWidget->setCurrentCell(item.at(row)->row(),0);

}

void MainWindow::on_pushButton_5_clicked()
{
    if(row<item.count()-1)
    {
        row++;
    }
    qDebug()<<row;
    qDebug()<<item.at(row)->row();
     ui->tableWidget->setCurrentCell(item.at(row)->row(),0);
}

void MainWindow::on_pushButton_clicked()
{

    int rownum=ui->tableWidget->rowCount();
    for(int i=0;i<rownum;i++)
    {
        ui->tableWidget->setRowHidden(i, true);
    }
    item = ui->tableWidget->findItems("1", Qt::MatchExactly);
    if (!item.isEmpty())//不为空
   {
       for (int i = 0; i < item.count(); i++)
       {
           ui->tableWidget->setRowHidden(item.at(i)->row(),false);//item.at(i).row()输出行号

       }
   }
    row=0;
     ui->tableWidget->setCurrentCell(item.at(0)->row(),0);
}

void MainWindow::on_pushButton_4_clicked()
{
    item = ui->tableWidget->findItems("", Qt::MatchContains);
    int rownum=ui->tableWidget->rowCount();
    for(int i=0;i<rownum;i++)
    {
        ui->tableWidget->setRowHidden(i, false);
        qDebug()<<item.at(i)->row();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int rownum=ui->tableWidget->rowCount();
    for(int i=0;i<rownum;i++)
    {
        ui->tableWidget->setRowHidden(i, true);
    }
    item = ui->tableWidget->findItems("2", Qt::MatchExactly);
    if (!item.isEmpty())//不为空
           {
               for (int i = 0; i < item.count(); i++)
               {
                   ui->tableWidget->setRowHidden(item.at(i)->row(),false);//item.at(i).row()输出行号

               }
           }
    row=0;
    ui->tableWidget->setCurrentCell(item.at(0)->row(),0);
}

void MainWindow::on_pushButton_3_clicked()
{
    int rownum=ui->tableWidget->rowCount();
    for(int i=0;i<rownum;i++)
    {
        ui->tableWidget->setRowHidden(i, true);
    }
    item = ui->tableWidget->findItems("3", Qt::MatchExactly);
    if (!item.isEmpty())//不为空
           {
               for (int i = 0; i < item.count(); i++)
               {
                   ui->tableWidget->setRowHidden(item.at(i)->row(),false);//item.at(i).row()输出行号

               }
           }
    row=0;
    ui->tableWidget->setCurrentCell(item.at(0)->row(),0);
}
