#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug()<<"Avaliable drivers;";
        QStringList drivers = QSqlDatabase::drivers();
        foreach(QString driver,drivers)
            qDebug()<<driver;
    w.show();
    return a.exec();
}
