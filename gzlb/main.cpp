#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>


void initSkin();
void initSkin()
{
    QFile file(QStringLiteral(":/res/1.qss") );
    if(file.open(QFile::ReadOnly))
    {
         qDebug() << "open success!" << endl;
         QTextStream filetext(&file);
         QString stylesheet = filetext.readAll();
         qApp->setStyleSheet(stylesheet);
    }
    else
    {
        qDebug() << "open failed" << endl;
    }

    file.close();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initSkin();
    MainWindow w;
    w.show();
    return a.exec();
}
