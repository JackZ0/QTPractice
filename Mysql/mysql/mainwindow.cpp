#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect_mysql();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connect_mysql(){
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QMYSQL");  //连接的MYSQL的数据库驱动
    db.setHostName("localhost");         //主机名
    db.setPort(3306);                    //端口
    db.setDatabaseName("mytest");          //数据库名
    db.setUserName("tester1");              //用户名
    db.setPassword("123456");            //密码
    db.open();

    //测试连接

    if(!db.open())
    {
        qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
        return ;
    }
    else
    {
         qDebug()<<"连接成功"<<"connect to mysql OK";
    }

    db.close();

}
