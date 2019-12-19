#include "mainwindow.h"
#include <QApplication>

#include <QQuickView>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QJsonObject obj;
    obj.insert("name","aaa");
    obj.insert("age",23);
    QJsonObject addr;
    addr.insert("city","guangzhou");
    addr.insert("province","guangdong");

    qDebug()<<addr;
    qDebug()<<obj;
    QQuickView *view = new QQuickView;
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl(QStringLiteral("mysql.qml")));
    view->show();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("mysql.qml")));
    w.show();
    w.update();
    qDebug()<<"Avaliable drivers;";
        QStringList drivers = QSqlDatabase::drivers();
        foreach(QString driver,drivers)
            qDebug()<<driver;
    return a.exec();
}
