#include "MainWindow.h"
#include <QApplication>
#include <QDir>
#include <QTime>

#include <QDebug>

int main(int argc, char *argv[])
{
    int j = 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
