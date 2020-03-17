#include "Dialog.h"
#include "ui_Dialog.h"

const quint32 c_max = 100;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),m_x(0.f),lineSeries(NULL)
{
    ui->setupUi(this);
//    setWindowFlags(Qt::FramelessWindowHint);
    lineSeries = new QSplineSeries(this);
    lineSeries2 = new QSplineSeries(this);

    m_x = 99;
    lineSeries->append(m_x,1);


//构建图表对象
    m_chart = new QChart();


   //将线添加到图表
    m_chart->addSeries(lineSeries);

    // 创建坐标轴
//    m_chart->createDefaultAxes();
    m_axisX = new QValueAxis();
    m_axisX->setRange(0,c_max);
    m_axisX->setTitleText("X");
    m_axisX->setLabelFormat("%g"); //小数点显示
    m_axisX->setTickCount(5);  // 设置刻度

    m_axisY = new QValueAxis();
    m_axisY->setRange(-10,10);
    m_axisY->setTitleText("Y");
    //影藏图例
    m_chart->legend()->hide();
    m_chart->setAxisX(m_axisX,lineSeries);
    m_chart->setAxisY(m_axisY,lineSeries);
    //设置主题颜色
    m_chart->setTheme(QtCharts::QChart::ChartThemeBlueCerulean);

    m_chart->setTitle("绘图");

    m_pScence = new QGraphicsScene(this);

    m_chart->setGeometry(0,0,500,300);

    m_pScence->addItem(m_chart);


    ui->widget->setScene(m_pScence);
//将图表绑定到视图
//    ui->widget->setChart(m_chart);

    ui->widget->setRenderHint(QPainter::Antialiasing,true);
    m_time = new QTimer(this);
    m_time->setInterval(1000);//采样周期
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

void Dialog::changeStyle()
{
    //窗体
    setDialogPalette();
    //图表

    //文字

    //标题

    // 刻度
}

void Dialog::setDialogPalette()
{
    QChart::ChartTheme theme = QChart::ChartThemeBlueIcy;
    m_chart->setTheme(theme);

    QPalette pal = window()->palette();
    switch (theme) {
        case QChart::ChartThemeLight:
        pal.setColor(QPalette::Window,QRgb(0xF0f0f0));
        pal.setColor(QPalette::WindowText,QRgb(0xF0f0f0));
        break;
    case QChart::ChartThemeBlueCerulean:
        pal.setColor(QPalette::Window,QRgb(0xF4f4f0));
        pal.setColor(QPalette::WindowText,QRgb(0xF4f0f4));
        break;
    case QChart::ChartThemeDark:
        pal.setColor(QPalette::Window,QRgb(0x20f0f0));
        pal.setColor(QPalette::WindowText,QRgb(0x20f0f0));
        break;
    case QChart::ChartThemeBrownSand:
        pal.setColor(QPalette::Window,QRgb(0xF060f0));
        pal.setColor(QPalette::WindowText,QRgb(0x60f0f0));
        break;
    case QChart::ChartThemeBlueNcs:
        pal.setColor(QPalette::Window,QRgb(0xF080f0));
        pal.setColor(QPalette::WindowText,QRgb(0x80f0f0));
        break;
    case QChart::ChartThemeHighContrast:
        pal.setColor(QPalette::Window,QRgb(0xF010f0));
        pal.setColor(QPalette::WindowText,QRgb(0xF010f0));
        break;
    case QChart::ChartThemeBlueIcy:
        pal.setColor(QPalette::Window,QRgb(0x11f0f0));
        pal.setColor(QPalette::WindowText,QRgb(0x11f0f0));
        break;
    case QChart::ChartThemeQt:
    default:
        pal.setColor(QPalette::Window,QRgb(0x44f0f0));
        pal.setColor(QPalette::WindowText,QRgb(0x44f0f0));
        break;
    }
    window()->setPalette(pal);
}

void Dialog::slot_timer()
{
    qreal xOffset = 0.f;
    qreal dIncrease =1;

    for(int i =0; i < c_max;i++){
        m_x +=dIncrease;
        xOffset +=dIncrease;
        lineSeries->append(m_x,qrand()%10);
    }
    if(lineSeries->count()*dIncrease >c_max){
        lineSeries->removePoints(0,lineSeries->count()*dIncrease-c_max);
    }

    qreal xUnit = m_chart->plotArea().width() / (m_axisX->max() - m_axisX->min());
    qreal xScroll = xOffset*xUnit;
    m_chart->scroll(xScroll,0);
}
