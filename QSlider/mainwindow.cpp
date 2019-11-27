#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QtNetwork>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager=new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,
            SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("https://blog.csdn.net/u011046042/article/details/38384327")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QString all=codec->toUnicode(reply->readAll());
    ui->textBrowser->setText(all);
    reply->deleteLater();
}
