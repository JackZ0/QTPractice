#include "speedo.h"
#include "ui_speedo.h"

#include <math.h>
Speedo::Speedo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Speedo)
{
    ui->setupUi(this);
    resize(400,400);

    m_updateTimer = new QTimer(this);
    m_lcd_Mileage = new QLCDNumber(this);

    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::white);


    m_lcd_Mileage->setDigitCount(8);
    m_lcd_Mileage->setSegmentStyle(QLCDNumber::Flat);    // 设置显示外观
    m_lcd_Mileage->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    m_lcd_Mileage->setGeometry(width()/2-30,height()/2+100,60,50);

    m_startAngle = 150; //顺时针角度
    m_endAngle = 30;

    m_refSize = 200;
    m_radius = m_refSize /2;

    m_minSpeed = 0;   //由于绘制刻度，需要为5倍数
    m_maxSpeed = 220; //由于绘制刻度，需要为5倍数
    m_curSpeed = m_minSpeed;
    //速度对应的角度
    m_anglePerVel = (360.0 - (m_startAngle - m_endAngle)) / (m_maxSpeed - m_minSpeed);

    m_updateTimer->setInterval(50);
    connect(m_updateTimer,SIGNAL(timeout()),this,SLOT(UpdateAngle()),Qt::UniqueConnection);
    m_updateTimer->start();//启动定时器

    setWindowFlags(Qt::FramelessWindowHint);//无窗体
    setAttribute(Qt::WA_TranslucentBackground);//背景透明
}

Speedo::~Speedo()
{
    delete ui;
}

void Speedo::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    float scale = qMin(width(),height());
    //设置缩放比例和原点的先后顺序很重要
    painter.scale(scale/m_refSize,scale/m_refSize);
    painter.translate(m_refSize/2,m_refSize/2); //设置坐标原点
    drawFrame(painter); //绘制边框
    drawDividing(painter);//绘制刻度
    drawNumberIndicator(painter);//绘制指示数字
    drawNumberSpeed(painter);//显示数字速度
    drawTitle(painter);
    drawIndicator(painter);


}

/**
 * @brief Speedo::drawFrame
 * 边框绘制
 * @param painter
 */
void Speedo::drawFrame(QPainter &painter)
{
    painter.save();
    painter.setPen(Qt::NoPen);
    QLinearGradient lg1(-m_radius,-m_radius,m_radius,m_radius);
    lg1.setColorAt(0.1,Qt::white);
    lg1.setColorAt(1,Qt::black);
    //    lg1.setSpread(QGradient::ReflectSpread);//渐变样式

    painter.setBrush(lg1);
    painter.drawEllipse(-m_radius,-m_radius,m_refSize,m_refSize);
    painter.setBrush(Qt::black);
    painter.drawEllipse(QPoint(0,0),90,90);
    painter.restore();

}

/**
 * @brief Speedo::drawNumberIndicator
 * 绘制数字
 * @param painter
 */
void Speedo::drawNumberIndicator(QPainter &painter)
{
    painter.save();

    painter.setPen(Qt::white);

    double x,y;
    double angle, angleArc;
    double w,h;
    QFontMetricsF fm(this->font());

    for (int i = m_minSpeed; i <= m_maxSpeed; i+= 20)//每隔20Km设置一个数字
    {
        angle = 360 - (m_startAngle + (i - m_minSpeed) * m_anglePerVel); //角度
        angleArc = angle * 3.14 / 180; //转换为弧度

        x = 65 * cos(angleArc);//65是一个不断调整后得出的值，不用太在意
        y = -65 * sin(angleArc); // 负号的意义在于 Y轴正方向向下

        QString speed = QString::number(i);

        if (i % 20 == 0)
        {
            w = fm.width(speed);
            h = fm.height();
            painter.drawText(QPointF(x - w / 2,y + h/4),speed);
        }
    }

    painter.restore();

}

/**
 * @brief Speedo::drawDividing
 * 绘制刻度
 * @param painter
 */
void Speedo::drawDividing(QPainter &painter)
{
    painter.save();
    painter.rotate(m_startAngle);//将坐标系顺时针旋转150°，到达起始位置

    QPen pen(Qt::white);
    painter.setPen(pen);

    int step = (m_maxSpeed - m_minSpeed) / 5;
    double angleStep = (360.0 - (m_startAngle - m_endAngle)) / step;

    for (int i = m_minSpeed; i <= m_maxSpeed; i += 5)
    {
        if (i >= 140){ //绘制红色
            pen.setColor(Qt::red);
            painter.setPen(pen);
        }

        if (i % 20 == 0){//粗线
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(88,0,75,0);

        }else if (i % 10 == 0){//中等
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawLine(88,0,80,0);

        }else if (i % 5 == 0){ //短线
            pen.setWidth(0);
            painter.setPen(pen);
            painter.drawLine(83,0,80,0);
        }
        painter.rotate(angleStep);
    }

    painter.restore();

}

/**
 * @brief Speedo::drawNumberSpeed
 * 绘制数字式速度
 * @param painter
 */
void Speedo::drawNumberSpeed(QPainter &painter)
{
    painter.save();
    painter.setPen(Qt::white);
    QString speed = QString("%1 KM/H").arg(m_curSpeed);
    QFontMetricsF fm(this->font());
    qreal w = fm.size(Qt::TextSingleLine,speed).width();
    painter.drawText(-w/2,-20,speed);

    painter.restore();
}


/**
 * @brief Speedo::drawIndicator
 *
 * 根据当前速度计算当前指针的角度，然后旋转坐标系到当前角度。最后绘制指针和旋转中心。
 * @param painter
 */
void Speedo::drawIndicator(QPainter &painter)
{
    painter.save();
    //绘制指针

    double curAngle = m_startAngle + m_curSpeed * m_anglePerVel;
    painter.rotate(curAngle); //旋转坐标系

    QRadialGradient haloGradient(0, 0, 60, 0, 0);  //辐射渐变
    haloGradient.setColorAt(0, QColor(60,60,60));
    haloGradient.setColorAt(1, QColor(160,160,160)); //灰
    painter.setPen(Qt::white); //定义线条文本颜色  设置线条的颜色
    painter.setBrush(haloGradient);//刷子定义形状如何填满 填充后的颜色

    static const QPointF points[3] = {
        QPointF(0.0, 2),
        QPointF(0.0, -2),
        QPointF(70.0, 0),
    };
    painter.drawPolygon(points,3); //绘制指针
    painter.restore();

    painter.save();
    //绘制旋转中心
    QRadialGradient rg(0,0,10);
    rg.setColorAt(0.0,Qt::darkGray);
    rg.setColorAt(0.5,Qt::white);
    rg.setColorAt(1.0,Qt::darkGray);
    painter.setPen(Qt::NoPen);
    painter.setBrush(rg);
    painter.drawEllipse(QPoint(0,0),5,5);

    painter.restore();
}

void Speedo::drawTitle(QPainter &painter)
{
    painter.save();
    painter.setPen(m_foreground);
    QString str(m_title);
    QFontMetricsF fm(this->font());
    double w = fm.size(Qt::TextSingleLine,str).width();
    painter.drawText(-w/2,-30,str);
    painter.restore();
}

void Speedo::UpdateAngle()
{
    static bool isOverFlow = false;
    static float mileage = 0.0;
    mileage += 0.1;
    if (isOverFlow)
        m_curSpeed -= 1;
    else
        m_curSpeed += 1;

    if (m_curSpeed >= m_maxSpeed)
        isOverFlow = true;

    if (m_curSpeed <= m_minSpeed)
        isOverFlow = false;

    m_lcd_Mileage->display(QString::number(mileage,'f',1));

    update();//刷新控件，会调用paintEvent函数

}
