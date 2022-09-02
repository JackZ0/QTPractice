#include "qroundprogressbar.h"
#include <QPainter>
QRoundProgressBar::QRoundProgressBar(QWidget *parent,BarStyle style) : QWidget(parent)
  ,m_min(0)
  ,m_max(100)
  ,m_value(0)
  ,m_startAngel(90)
  ,m_barStyle(style)
  ,m_outlinePenWidth(0)
  ,m_dataPenWidth(0)
  ,m_decimals(0)
{

}

QRoundProgressBar::~QRoundProgressBar()
{

}

void QRoundProgressBar::setStartAngle(double angle)
{
    if (angle != m_startAngel)
    {
        m_startAngel = angle;
        update();
    }
}

void QRoundProgressBar::setOutlinePenWidth(double penWidth)
{
    if (penWidth != m_outlinePenWidth)
    {
       m_outlinePenWidth = penWidth;
       update();
    }
}

void QRoundProgressBar::setDataPenWidth(double penWidth)
{
    if (penWidth != m_dataPenWidth)
    {
        m_dataPenWidth = penWidth;
        update();
    }
}

void QRoundProgressBar::setDecimals(int count)
{
    if (count >= 0 && count != m_decimals)
    {
       m_decimals = count;
       update();
    }

}

void QRoundProgressBar::setBarStyle(BarStyle style)
{
    if (style != m_barStyle)
    {
        m_barStyle = style;
        update();
    }

}

void QRoundProgressBar::setRange(double min, double max)
{
    m_min = min;
    m_max = max;

    if (m_max < m_min)
    {
        qSwap(m_max, m_min);
    }

    if (m_value < m_min)
    {
        m_value = m_min;
    }
    else if (m_value > m_max)
    {
        m_value = m_max;
    }

    update();
}

void QRoundProgressBar::setValue(double val)
{
    if (m_value != val)
    {
        if (val < m_min)
        {
            m_value = m_min;
        }
        else if (val > m_max)
        {
            m_value = m_max;
        }
        else
        {
            m_value = val;
        }
        update();
    }
}

void QRoundProgressBar::setValue(int val)
{
    setValue(double(val));
}


void QRoundProgressBar::setMinimum(double min)
{
    setRange(min, m_max);
}

void QRoundProgressBar::setMaximum(double max)
{
    setRange(m_min, max);
}


void QRoundProgressBar::paintEvent(QPaintEvent* /*event*/)
{
    //外圈直径
    double outerDiameter = this->width();

    //外圈矩形
    QRectF baseRect(0, 0, outerDiameter, outerDiameter);

    QPainter p(this);
    p.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    //画背景矩形填充白色
    p.fillRect(baseRect, QBrush(QColor("#FFFFFF")));

    //内圆直径
    double innerDiameter;

    //内圈矩形
    QRectF innerRect;

    //计算内圈矩形
    if (m_barStyle == StyleLine)
    {
        innerDiameter = outerDiameter - m_outlinePenWidth;
    }

    else if(m_barStyle == StyleDonut)
    {
        innerDiameter = outerDiameter * 0.9;
    }
    double delta = (outerDiameter - innerDiameter) / 2;
    innerRect = QRectF(delta, delta, innerDiameter, innerDiameter);
    //画基础图形
    drawBase(p, baseRect, innerRect);
    //计算当前步长比例
    double arcStep = 360.0 / (m_max - m_min) * m_value;
    //根据值画出进度条
    drawValue(p, baseRect, m_value, arcStep, innerRect, innerDiameter);
    //画文字
    drawText(p, baseRect, m_value);
    p.end();
}

void QRoundProgressBar::drawBase(QPainter &p, const QRectF &baseRect, const QRectF &innerRect)
{
    switch (m_barStyle)
    {
        case StyleDonut:
        {
            QPainterPath dataPath;
            dataPath.setFillRule(Qt::OddEvenFill);
            dataPath.moveTo(baseRect.center());
            dataPath.addEllipse(innerRect);

            QPen pen;
            pen.setColor(QColor("#DEE3E7"));
            pen.setWidth(10);
            p.setPen(pen);
            p.setBrush(QBrush(QColor("#FFFFFF")));

            p.drawPath(dataPath);
            break;
        }
        case StylePie:
        {
            p.setPen(QPen(QColor("#FFFFFF"), m_outlinePenWidth));
            p.setBrush(QBrush(QColor("#DEE3E7")));
            p.drawEllipse(baseRect);
            break;
        }

        case StyleLine:
        {
            p.setPen(QPen(QColor("#FFFFFF"), m_outlinePenWidth));
            p.setBrush(Qt::NoBrush);
            p.drawEllipse(baseRect.adjusted(m_outlinePenWidth / 2, m_outlinePenWidth / 2, -m_outlinePenWidth / 2, -m_outlinePenWidth / 2));
            break;
        }

        default:
        {
            break;
        }
    }
}

void QRoundProgressBar::drawValue(QPainter &p, const QRectF &baseRect , double value, double arcLength
                          , const QRectF & innerRect, double innerDiameter)
{
    if (value == m_min)
    {
        return;
    }

    if (m_barStyle == StyleLine)
    {
        p.setPen(QColor("#00FF00"));
        p.setBrush(Qt::NoBrush);
        p.drawArc(baseRect,m_startAngel * 16, -arcLength * 16);
    }
    else if (m_barStyle == StyleDonut)
    {
        QPen pen;
        pen.setColor(QColor("#00FF00"));
        pen.setWidth(10);
        pen.setCapStyle(Qt::RoundCap);
        p.setPen(pen);
        p.drawArc(innerRect, m_startAngel*16 , -16*arcLength);
    }
    else
    {
        //获取中心点坐标
        QPointF centerPoint = baseRect.center();
        QPainterPath dataPath;
        dataPath.setFillRule(Qt::WindingFill);
        dataPath.moveTo(centerPoint);
        //逆时针画弧长
        dataPath.arcTo(baseRect, m_startAngel, -arcLength);
        if (m_barStyle == StylePie)
        {
            dataPath.lineTo(centerPoint);
            p.setPen(QPen(QColor("#00FF00"), m_dataPenWidth));
        }
        p.setBrush(QBrush(QColor("#00FF00")));
        p.drawPath(dataPath);
    }
}

void QRoundProgressBar::drawText(QPainter &p, const QRectF &rect, double value)
{
    QString textToDraw = "%";
    double percent = (value - m_min) / (m_max - m_min) * 100.0;
    textToDraw = QString::number(percent, 'f', m_decimals) + textToDraw;
    QFont f;
    f.setFamily("微软雅黑");
    f.setPixelSize(20);
    p.setFont(f);
    p.setPen(QColor("#606266"));
    p.drawText(rect, Qt::AlignCenter, textToDraw);
}
