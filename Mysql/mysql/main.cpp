#include "mainwindow.h"
#include <QApplication>

#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QQuickView *view = new QQuickView;
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl(QStringLiteral("mysql.qml")));
    view->show();
    w.show();
    w.update();
    qDebug()<<"Avaliable drivers;";
        QStringList drivers = QSqlDatabase::drivers();
        foreach(QString driver,drivers)
            qDebug()<<driver;
    return a.exec();
}
