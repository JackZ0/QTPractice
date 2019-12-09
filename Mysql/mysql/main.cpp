#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    qDebug()<<"Avaliable drivers;";
        QStringList drivers = QSqlDatabase::drivers();
        foreach(QString driver,drivers)
            qDebug()<<driver;
    return a.exec();
}
