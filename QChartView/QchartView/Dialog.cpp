#include "Dialog.h"
#include "ui_Dialog.h"

const quint32 c_max = 1000;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),mtLast(0)
{
    ui->setupUi(this);

    lineSeries = new QSplineSeries(this);
    qreal x = 0.f;
    for(size_t i =0; i< c_max; i++){
        x = qreal(i+1)/c_max;
        lineSeries->append(i,getData(x));
    }

//构建图表对象
    m_chart = new QChart();


   //将线添加到图表
    m_chart->addSeries(lineSeries);

    // 创建坐标轴
//    m_chart->createDefaultAxes();
    m_axisX = new QValueAxis();
    m_axisX->setRange(0,1000);
    m_axisX->setTitleText("X");

    m_axisY = new QValueAxis();
    m_axisY->setRange(-10,10);
    m_axisY->setTitleText("Y");
    //影藏图例
//    m_chart->legend()->hide();
    m_chart->setAxisX(m_axisX,lineSeries);
    m_chart->setAxisY(m_axisY,lineSeries);
    //设置主题颜色
    m_chart->setTheme(QtCharts::QChart::ChartThemeBrownSand);

    m_chart->setTitle("绘图");

    m_pScence = new QGraphicsScene(this);

    m_chart->setGeometry(0,0,1000,300);

    m_pScence->addItem(m_chart);


    ui->widget->setScene(m_pScence);
//将图表绑定到视图
//    ui->widget->setChart(m_chart);

    ui->widget->setRenderHint(QPainter::Antialiasing,true);
    m_time = new QTimer(this);
    m_time->setInterval(100);
    connect(m_time,&QTimer::timeout,this,&Dialog::slot_timer);
    m_time->start();
}

Dialog::~Dialog()
{
    delete ui;
    m_chart->removeAllSeries();
}

qreal Dialog::getData(qreal x)
{
    return qSin(x*2*M_PI)*7;
}

void Dialog::slot_timer()
{
    //用一个静态对象存储启动时间
    static QTime tmBegin = QTime::currentTime();
    qint64 tmEllapsed = tmBegin.elapsed();
    qint64 nSkip = tmEllapsed - mtLast;

    QVector<QPointF> psOld =lineSeries->pointsVector();

    QVector<QPointF> ptsNew;
    //计算两次定时器之间流失的时间
    qint64 index =0;
    for(index = 0; index < psOld.count()-nSkip; index++){
        ptsNew.append(QPointF(index,psOld[nSkip+index].y()));
    }

    qreal x = 0.f;

    //补充新数据
    for(index =psOld.count()- nSkip; index < psOld.count(); index++){
        x = qreal(mtLast+index +1)/c_max;
        ptsNew.append(QPointF(index,getData(x)));
    }
    //更新序列
    lineSeries->replace(ptsNew);
    // 更新上次进入定时器的时间

    mtLast = tmEllapsed;

}
