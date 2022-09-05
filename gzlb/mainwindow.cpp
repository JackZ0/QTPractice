#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "Algorithm/fibonacci.h"
#include "Algorithm/factorial.h"
#include "xml/xml.h"
#include "Tcp/widget.h"
#include "serialport/serialmainwindow.h"
#include "thread/mythread.h"
#include "Convert/convert.h"
#include "qroundprogressbar.h"

#include <QVector>
#include <QDialog>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QJsonValue>
#include <QIcon>

#include <QProgressBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("通用qt框架代码总结"));
    initUi();
    Xml xmltemp;
    xmltemp.UpdateXml("test.xml");
    m_T = new mythread;
    thread = new QThread(this);
    m_counter = 0;
    m_T->moveToThread(thread);
    m_timer = new QTimer();
    m_timer->setInterval(50);

    connect(m_T,&mythread::myThreadSignal,this,&MainWindow::dealSignal);
    qDebug() << "主进程ID:" <<QThread::currentThread() << endl;
    connect(this, &MainWindow::startMyThread,m_T, &mythread::myTimeOut);
    connect(this,&MainWindow::destroyed,this,&MainWindow::dealClose);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(counterAdd()));


}

void MainWindow::initUi()
{
   menu1 = new QMenu(QString::fromLocal8Bit("&操作"),this);
   menu2 = new QMenu(QString::fromLocal8Bit("&显示"),this);
   menu3 = new QMenu(QString::fromLocal8Bit("&分析"),this);
   menu4 = new QMenu(QString::fromLocal8Bit("&帮助"),this);
   menu5 = new QMenu(QString::fromLocal8Bit(("&数据库测试")),this);
   menu6 = new QMenu(QString::fromLocal8Bit("&通訊"),this);
   menu7 = new QMenu(QString::fromLocal8Bit("&转换"),this);

   menuBar()->addMenu(menu1);
   menuBar()->addMenu(menu2);
   menuBar()->addMenu(menu3);
   menuBar()->addMenu(menu4);
   menuBar()->addMenu(menu5);
   menuBar()->addMenu(menu6);
   menuBar()->addMenu(menu7);

   action1 = new QAction(tr("sqlite"),this);
   action2 = new QAction(tr("mysql"),this);
   action3 = new QAction(QString::fromLocal8Bit("绘图1"),this);
   action4 = new QAction(QString::fromLocal8Bit("绘图2"),this);
   action5 = new QAction(QString::fromLocal8Bit("绘图3"),this);
   action6 = new QAction(QString::fromLocal8Bit("json解析"),this);
   action7 = new QAction(QString::fromLocal8Bit("xml解析"),this);
   action8 = new QAction(QString::fromLocal8Bit("tcp/ip"),this);
   action9 = new QAction(QString::fromLocal8Bit("串口"),this);
   action10 = new QAction(QString::fromLocal8Bit("软件"));

   action12 = new QAction(QString::fromLocal8Bit("速度表"));
   action13 = new QAction(QString::fromLocal8Bit("ASCI"));
   action14 = new QAction(QString::fromLocal8Bit("测试"));
   action15 = new QAction(QString::fromLocal8Bit("进度条测试"));
   action16 = new QAction(QString::fromLocal8Bit("绘图算法1"),this);

   menu1->addAction(action14);


   menu5->addAction(action1);
   menu5->addAction(action2);
   menu2->addAction(action3);
   menu2->addAction(action4);
   menu2->addAction(action5);
   menu2->addAction(action16);
   menu2->addAction(action15);

   menu3->addAction(action6);
   menu3->addAction(action7);

   menu4->addAction(action10);

   menu6->addAction(action8);
   menu6->addAction(action9);
   menu7->addAction(action13);
   menu7->addAction(action12);
   ui->lcdNumber->display("0000");

//   m_systemIcon = new QSystemTrayIcon(this);

//   QIcon icon = QIcon(":/Icon/thumb.ico");
//   //QMenu
//   QMenu *tuopanMenu = new QMenu(this);
//   m_systemIcon->setIcon(icon);
//   m_systemIcon->setContextMenu(tuopanMenu);
//   m_systemIcon->show();
//   setWindowIcon(icon);
   createTrayIcon();

   connect(action1,SIGNAL(triggered()),this,SLOT(action1_sqlite()));
   connect(action3,SIGNAL(triggered()),this,SLOT(action3_showGraphics()));
   connect(action4,SIGNAL(triggered()),this,SLOT(action4_showGraphics()));
   connect(action5,SIGNAL(triggered()),this,SLOT(action5_showGraphics()));
   connect(action6,SIGNAL(triggered()),this,SLOT(action6_showDialog()));
   connect(action8,SIGNAL(triggered()),this,SLOT(action8_showDialog()));
   connect(action9,SIGNAL(triggered()),this,SLOT(action9_showDialog()));
   connect(action10,SIGNAL(triggered()),this,SLOT(action10_showMessage()));
   connect(action12,SIGNAL(triggered()),this,SLOT(action12_show()));
   connect(action13,SIGNAL(triggered()),this,SLOT(aciton13_show()));
   connect(action15,SIGNAL(triggered()),this,SLOT(aciton15_show()));
   connect(action16,SIGNAL(triggered()),this,SLOT(action16_showGraphics()));



}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void MainWindow::dealClose()
{
    on_btnStop_clicked();
    delete m_T;
}

void MainWindow::createTrayIcon()
{
    m_trayIcomMenu = new QMenu(this);
    minimizeAction = new QAction(tr("Minimize"), this);
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

    m_trayIcomMenu->addAction(minimizeAction);

    m_systemIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/Icon/Icon/thumb.ico");
    m_systemIcon->setIcon(icon);
    m_systemIcon->setContextMenu(m_trayIcomMenu);
    setWindowIcon(icon);
    m_systemIcon->show();
    connect(m_systemIcon, &QSystemTrayIcon::activated, this, &MainWindow::activeTray);
    connect(m_systemIcon, &QSystemTrayIcon::messageClicked, this, &MainWindow::showWindow);

}

void MainWindow::showMenu()
{
    m_trayIcomMenu->show();
}

void MainWindow::showWindow()
{
    this->show();
}

void MainWindow::showMessage()
{
    m_systemIcon->showMessage("Information",//消息窗口标题
            "There is a new message!",//消息内容
            QSystemTrayIcon::MessageIcon::Information,//消息窗口图标
            5000);

}

void MainWindow::action1_sqlite()
{
    m_dialog1 = new QDialog(this);
    m_dialog1->setFixedSize(QSize(800,800));
    m_dialog1->setWindowTitle(tr("sqlite 数据"));
    //建立并打开数据库
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("test.db");
    if (!database.open())
    {
      qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
      qDebug() << "Succeed to connect database." ;
    }
    QSqlQuery sql_query;
    if(!sql_query.exec("INSERT INTO main.HDR (Id, Value, timestamp) VALUES (1, 23.0, '2022-2-11 00:01:03');"))
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "inserted 1!";
    }
    database.close();
   QTableWidget *m_tablewidget = new QTableWidget(m_dialog1);
   QRect m_rect(100,100,500,500);
   m_tablewidget->setColumnCount(5);
   m_tablewidget->setRowCount(4);
   m_tablewidget->setGeometry(m_rect);
   for(int i=0;i<4;i++)                //循环添加数据
   {
      m_tablewidget->setItem(i,0,new QTableWidgetItem("hh"));    //动态创建item插入据方便验证
      m_tablewidget->setItem(i,1,new QTableWidgetItem("hh"));
      m_tablewidget->setItem(i,2,new QTableWidgetItem("hh"));
      m_tablewidget->setItem(i,3,new QTableWidgetItem("hh"));
   }
   m_tablewidget->show();
   m_dialog1->show();
}

void MainWindow::action3_showGraphics()
{
    m_dialog3 = new QDialog(this);
    m_dialog3->setFixedSize(QSize(800,800));
    m_dialog3->setWindowTitle(tr("图表展示"));

    QCustomPlot *customPlot2 = new QCustomPlot(m_dialog3);
    customPlot2->resize(800, 800);
    customPlot2->setGeometry(0,0,800,800);

    //可变数组存放绘图的坐标的数据，分别存放x和y坐标的数据，101为数据长度
    QVector<double> x2(101),y2(101);
    //添加数据，这里演示y=x^3，为了正负对称，x从-10到+10
    for (int i = 0; i<101; i++)
    {
        //x[i] = i/5 - 10;
        //y[i] = qPow(x[i], 2);//x的y次方;
        x2[i] = i;
        y2[i] = 4*x2[i]*x2[i]+9;
    }
    //向绘图区域QCustomPlot添加一条曲线
    customPlot2->addGraph();
    //添加数据
    customPlot2->graph(0)->setData(x2, y2);
    //设置坐标轴名称
    customPlot2->xAxis->setLabel("x2");
    customPlot2->yAxis->setLabel("y2");
    //设置坐标轴显示范围，否则只能看到默认范围
    customPlot2->xAxis->setRange(0, 11);
    customPlot2->yAxis->setRange(0, 1100);
    customPlot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    m_dialog3->show();

}

void MainWindow::action4_showGraphics()
{
    m_dialog4 = new QDialog(this);
    m_dialog4->setFixedSize(QSize(800,800));
    m_dialog4->setWindowTitle(tr("图表展示"));
    QCustomPlot *customPlot = new QCustomPlot(m_dialog4);
    customPlot->resize(800, 800);
    //可变数组存放绘图的坐标的数据，分别存放x和y坐标的数据，101为数据长度
    QVector<double> x(101),y(101);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    Fibonacci fib;
    factorial fac;
    //添加数据，这里演示y=x^3，为了正负对称，x从-10到+10
    for (int i = 0; i<10; i++)
    {
        x[i] = i;
        y[i] = fac.func(i);
        qDebug() << y[i] ;

    }
    //向绘图区域QCustomPlot添加一条曲线
    customPlot->addGraph();

    //添加数据
    customPlot->graph(0)->setData(x, y);

    //设置坐标轴名称
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");

    //设置坐标轴显示范围，否则只能看到默认范围
    customPlot->xAxis->setRange(0, 10);
    customPlot->yAxis->setRange(0, 20000);
    m_dialog4->show();
}

void MainWindow::action5_showGraphics()
{
    m_dialog5 = new QDialog(this);
    m_dialog5->setFixedSize(QSize(800,800));
    m_dialog5->setWindowTitle(tr("图表展示"));

    QCustomPlot *customPlot3 = new QCustomPlot(m_dialog5);
    QDateTime qtimeObj = QDateTime::currentDateTime();//获取时间
    customPlot3->resize(800, 800);
    customPlot3->setGeometry(0,0,800,800);
    //可变数组存放绘图的坐标的数据，分别存放x和y坐标的数据，101为数据长度
    QVector<double> time,y3;
    //添加数据，这里演示y=x^3，为了正负对称，x从-10到+10
    if(time.count() < 7)
    {
        y3.append(qrand()%50);
        time.append(qtimeObj.toTime_t());
        customPlot3->xAxis->setRange(time.at(0),time.at(time.size()-1));
    }
    else
    {
        y3.removeFirst();
        time.removeFirst();
        y3.append(qrand()%50);
        customPlot3->xAxis->setRange(time.at(0),time.at(time.size()-1));
    }
    if(time.count() == 1)
    {
        customPlot3->addGraph();
        customPlot3->yAxis->setRange(0,100);
    }
    qDebug()<<"num is"<<time.count()<<"y="<<y3<<"time is"<<time;
    //QCPAxisTickerDateTime 时间坐标轴 必须要用 智能指针
    QSharedPointer<QCPAxisTickerDateTime> timer(new QCPAxisTickerDateTime);
    //timer->setDateTimeFormat("yyyy-MM-dd");    //设置时间格式
    timer->setDateTimeFormat("hh-mm-ss");    //设置时间格式
    timer->setTickCount(7);    //设置时间轴 一共几格
    customPlot3->xAxis->setTickLabelRotation(30);//设置label 旋转30° 横着显示可能显示不全
    timer->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);//允许执行可读性较差的滴答步骤，从而有助于更接近所请求的滴答计数
    //设置坐标轴
    customPlot3->xAxis->setTicker(timer);
    //CustomPlot->xAxis->setRange(time.at(0),time.at(6));
    customPlot3->graph(0)->setData(time,y3);
    //可以进行鼠标位置 放大缩小 拖拽  放大缩小坐标系！！！功能非常强大
    customPlot3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //重绘 每次改变完以后都要调用这个进行重新绘制
    customPlot3->replot();
    m_dialog5->show();
}

#define POINT_COUNT 4000
#define A_SANJIAO 3
void MainWindow::action16_showGraphics()
{
    m_dialog6 = new QDialog(this);
    m_dialog6->setFixedSize(QSize(1900,800));
    m_dialog6->setWindowTitle(QString::fromLocal8Bit("三角函数"));

    QCustomPlot *customPlot3 = new QCustomPlot(m_dialog6);
    customPlot3->resize(1900, 800);
    customPlot3->setGeometry(0,0,1900,800);
    QVector<double> x(POINT_COUNT), y(POINT_COUNT); //初始化向量x和y

    int i = 0;
    for (int j=0; j<POINT_COUNT; j++)
    {
        x.push_back(j); // x范围[0,360]
//        y.push_back(A_SANJIAO*sin((3.14/180)*j)); //
//        y.push_back(A_SANJIAO*cos(0.017453292519943295*j)); //
//        y.push_back(A_SANJIAO*tan(0.017453292519943295*j)); //
        y.push_back(A_SANJIAO*sin((3.14/180)*j) - cos(3*0.017453292519943295*j) - cos(5*0.017453292519943295*j));
    }
    qDebug() << "y" <<y;
    customPlot3->addGraph();//添加数据曲线（一个图像可以有多个数据曲线）

    // graph(0);可以获取某个数据曲线（按添加先后排序）
        // setData();为数据曲线关联数据

    customPlot3->graph(0)->setData(x,y);
    customPlot3->graph(0)->setName(QString::fromLocal8Bit("三角函数")); // 设置图例名称

    customPlot3->xAxis->setLabel("x");
    customPlot3->yAxis->setLabel("y");

    customPlot3->xAxis->setRange(0,POINT_COUNT);
    customPlot3->yAxis->setRange(-2*A_SANJIAO,2*A_SANJIAO);
    customPlot3->legend->setVisible(true);

    customPlot3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //重绘 每次改变完以后都要调用这个进行重新绘制
    customPlot3->replot();
    m_dialog6->show();
}

void MainWindow::action6_showDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->setFixedSize(QSize(800,800));
    dialog->setWindowTitle(tr("json解析"));
    QLabel *label = new QLabel(dialog);
    QString txt = "json解析:";
    txt.append('\n');

    QFile file("data.json");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug() <<"file not exist!";
    }
    QString value = file.readAll();
    qDebug() << value;

    file.close();

    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8());
    if(!parseJsonErr.error == QJsonParseError::NoError)
    {
        qDebug() << tr("解析出错");
        return;
    }
    QJsonObject jsonObject = document.object();
    qDebug() << "jsonObject[name] ==" << jsonObject["name"].toString();

    if(jsonObject.contains(QStringLiteral("secendName")))
    {
        QJsonValue jsonValuList = jsonObject.value(QStringLiteral("secondName"));
        QJsonObject item = jsonValuList.toObject();
        qDebug() << "item[thirdName] == " << item["thirdName"].toString();
    }

    if(jsonObject.contains(QStringLiteral("recoveryPrimaryNode")))
    {
        QJsonValue arrayValue = jsonObject.value(QStringLiteral("recoveryPrimaryNode"));
           if(arrayValue.isArray())
           {
               QJsonArray array = arrayValue.toArray();
               for(int i=0;i<array.size();i++)
               {
                   QJsonValue iconArray = array.at(i);
                   QJsonObject icon = iconArray.toObject();
                   QString id = icon["id"].toString();
                   QString iconTxt = icon["iconTxt"].toString();
                   QString iconName = icon["iconName"].toString();
                   qDebug()<<"id="<<id<<"iconTxt="<<iconTxt<<"iconName="<<iconName;
                   txt.append(id);
                   txt.append('\t');
                   txt.append(iconTxt);
                   txt.append('\t');
                   txt.append(iconName);
                   txt.append('\n');
               }
           }
       }
    label->setText(txt);
    dialog->show();
}

void MainWindow::action8_showDialog()
{
    m_widget1 = new Widget(nullptr);
    m_widget1->show();
}

void MainWindow::action9_showDialog()
{
    m_window1 = new serialMainWindow(nullptr);
    m_window1->show();
}

void MainWindow::action10_showMessage()
{
    QMessageBox::information(this,tr("欢迎加入"),tr("一起来码砖") ,QMessageBox::Ok);
}

void MainWindow::action12_show()
{
    m_speedo = new Speedo(nullptr);

    m_speedo->show();
}

void MainWindow::aciton13_show()
{
    m_convert = new Convert(this);
    m_convert->show();
}

void MainWindow::aciton15_show()
{
    tempBar = new QRoundProgressBar(nullptr);

    m_timer->start(1000);
    tempBar->setDataPenWidth(3);
    tempBar->setOutlinePenWidth(3);
    tempBar->setStartAngle(0);

    tempBar->show();
}

void MainWindow::activeTray(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Context:
        showMenu();
        break;
    case QSystemTrayIcon::DoubleClick:
        showWindow();
        break;
    case QSystemTrayIcon::Trigger:
        showMessage();
        break;
    }
}


void MainWindow::on_btnStart_clicked()
{
    if(thread->isRunning() == true)
    {
        return;
    }
    //启动子线程，但没有启动线程处理函数
    thread->start();
    m_T->setFlag(false);

    //**************************************************
    //不能够直接调用该线程处理函数
    //不然的话，都会导致线程处理函数和主线程是在同一个线程
    // myThread->MyTimeout();
    //**************************************************


    //只能够通过 signal - slot 来调用线程处理函数
    emit startMyThread();
}

//void MainWindow::startThread()
//{
//    m_T->myTimeOut();
//}


void MainWindow::on_btnStop_clicked()
{
    if(thread->isRunning() == false)
    {
        return ;
    }
    m_T->setFlag(true);
    thread->quit();
    thread->wait();
}

void MainWindow::counterAdd()
{
    m_counter++;
    tempBar->setValue(m_counter%100);
    ui->progressBar->setValue(m_counter%100);
}
