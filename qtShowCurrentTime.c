/*windows 平台下用Qt Creator实现  在ui界面中手动添加两个label :labelDate 显示日期,labelDateTime 显示时间*/

/*       matrix.h      */

#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QtGui>

namespace Ui {
    class matrix;
}

class matrix : public QWidget
{
    Q_OBJECT

public:
    explicit matrix(QWidget *parent = 0);
    ~matrix();

private:
    Ui::matrix *ui;
    QMessageBox *msg;
    QTimer *timer;


private slots:
    void changeTime();
    void on_pushButtonExit_clicked();
};

#endif // MATRIX_H

/*             matrix.cpp             */

#include "matrix.h"
#include "ui_matrix.h"

matrix::matrix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::matrix)
{
    ui->setupUi(this);
    this->timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(changeTime()));
    timer->start(1000);
}

matrix::~matrix()
{
    delete ui;
}
void matrix::changeTime()
{
    QDateTime date = QDateTime::currentDateTime();
    QTime lcdTime = date.time();
    QDate dateTime = date.date();
    int hourInt = lcdTime.hour();
    QString hour = QString("%1").arg(hourInt);
    int minuteInt = lcdTime.minute();
    QString minute = QString("%1").arg(minuteInt);
    int secondInt = lcdTime.second();
    QString second = QString("%1").arg(secondInt);
    if(hourInt<10)
        hour = "0" + hour;
    if(minuteInt<10)
        minute = "0" + minute;
    if(secondInt < 10)
        second = "0" + second;
    QString timeStr = QString("%1:%2:%3").arg(hour).arg(minute).arg(second);
    ui->labelDateTime->setText(timeStr);

    int yearInt = dateTime.year();
    QString year = QString("%1").arg(yearInt);
    int monthInt = dateTime.month();
    QString month = QString("%1").arg(monthInt);
    int dayInt = dateTime.day();
    QString day = QString("%1").arg(dayInt);
    if(yearInt < 10)
        year = "0" + year;
    if(monthInt < 10)
        month = "0" + month;
    if(dayInt < 10)
        day = "0" + day;
    QString dateStr = QString("%1-%2-%3").arg(year).arg(month).arg(day);
    ui->labelDate->setText(dateStr);
}

/*       main.cpp     */
#include <QtGui/QApplication>
#include "matrix.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    matrix w;
    w.setWindowFlags(Qt::Widget|Qt::CustomizeWindowHint);//去掉边框
    w.showMaximized();
    w.show();

    return a.exec();
}

