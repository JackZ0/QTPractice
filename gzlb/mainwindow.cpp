#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "Algorithm/fibonacci.h"
#include "Algorithm/factorial.h"
#include "xml/xml.h"
#include <QVector>
#include <QDialog>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("通用qt框架代码总结");
    initUi();
    Xml xmltemp;
    xmltemp.UpdateXml("test.xml");
}

void MainWindow::initUi()
{
   menu1 = new QMenu(tr("&操作"),this);
   menu2 = new QMenu(tr("&显示"),this);
   menu3 = new QMenu(tr("&分析"),this);
   menu4 = new QMenu(tr("&帮助"),this);
   menu5 = new QMenu(tr("&数据库测试"),this);
   menuBar()->addMenu(menu1);
   menuBar()->addMenu(menu2);
   menuBar()->addMenu(menu3);
   menuBar()->addMenu(menu4);
   menuBar()->addMenu(menu5);
   action1 = new QAction(tr("sqlite"),this);
   action2 = new QAction(tr("mysql"),this);
   action3 = new QAction(tr("绘图1"),this);
   action4 = new QAction(tr("绘图2"),this);
   action5 = new QAction(tr("绘图3"),this);
   menu5->addAction(action1);
   menu5->addAction(action2);
   menu2->addAction(action3);
   menu2->addAction(action4);
   menu2->addAction(action5);
   connect(action1,SIGNAL(triggered()),this,SLOT(action1_sqlite()));
   connect(action3,SIGNAL(triggered()),this,SLOT(action3_showGraphics()));
   connect(action4,SIGNAL(triggered()),this,SLOT(action4_showGraphics()));
   connect(action5,SIGNAL(triggered()),this,SLOT(action5_showGraphics()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::action1_sqlite()
{
   m_dialog1 = new QDialog(this);
   m_dialog1->setFixedSize(QSize(800,800));
   m_dialog1->setWindowTitle(tr("sqlite 数据"));

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

