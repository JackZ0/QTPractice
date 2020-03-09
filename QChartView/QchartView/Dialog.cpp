#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QLineSeries *lineSeries = new QLineSeries(this);
    for(size_t i =0; i< 100; i++){
        lineSeries->append(i,sin(0.7f*i));
    }

//构建图表对象
    m_chart = new QChart();


   //将线添加到图表
    m_chart->addSeries(lineSeries);

    // 创建坐标轴
    m_chart->createDefaultAxes();

    //影藏图例
//    m_chart->legend()->hide();

    //设置主题颜色
    m_chart->setTheme(QtCharts::QChart::ChartThemeBrownSand);

    m_chart->setTitle("绘图");

    m_pScence = new QGraphicsScene(this);

    m_chart->setGeometry(0,0,500,500);

    m_pScence->addItem(m_chart);


    ui->widget->setScene(m_pScence);
//将图表绑定到视图
//    ui->widget->setChart(m_chart);

    ui->widget->setRenderHint(QPainter::Antialiasing,true);
}

Dialog::~Dialog()
{
    delete ui;
    m_chart->removeAllSeries();
}
