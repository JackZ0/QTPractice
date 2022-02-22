#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/res/1.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug() << "open success!" << endl;
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
    }
    else
    {
        qDebug() << "open failed" << endl;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
