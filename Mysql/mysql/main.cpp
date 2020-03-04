#include "mainwindow.h"
#include <QApplication>

#include <QQuickView>
#include <QQmlApplicationEngine>
#include <user.h>
#include <UserDB.h>
#include <QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;

    UserDB TestDB;
    int intResult = 0;
    User TestUser;
    TestUser.id = 4;
    TestUser.orgniztionId =2;
    TestUser.accountName = "li";
    TestUser.realName ="si";
    TestUser.password = "123456";
    TestUser.loginCount = 4;
//    TestUser.email = "123@gmail.com";
    TestUser.telephone = "12121";
    TestUser.createAt = QDateTime::currentDateTime();
    TestUser.loginAt = QDateTime::currentDateTime();
    TestUser.isValid = 0;
    TestUser.json = "test";

    intResult = TestDB.UpdateUser(TestUser);
//    intResult = TestDB.DeleteUserById(4);
    TestUser = TestDB.QueryUserById(1);
    qDebug() << intResult;
//    QJsonObject obj;
//    obj.insert("name","aaa");
//    obj.insert("age",23);
//    QJsonObject addr;
//    addr.insert("city","guangzhou");
//    addr.insert("province","guangdong");

//    qDebug()<<addr;
//    qDebug()<<obj;
//    QQuickView *view = new QQuickView;
//    view->setResizeMode(QQuickView::SizeRootObjectToView);
//    view->setSource(QUrl(QStringLiteral("mysql.qml")));
//    view->show();

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("mysql.qml")));
//    w.show();
//    w.update();
    qDebug()<<"Avaliable drivers;";
        QStringList drivers = QSqlDatabase::drivers();
        foreach(QString driver,drivers)
            qDebug()<<driver;
    return a.exec();
}
