#ifndef SPEEDO_H
#define SPEEDO_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QLCDNumber>
namespace Ui {
class Speedo;
}

class Speedo : public QWidget
{
    Q_OBJECT

public:
    explicit Speedo(QWidget *parent = nullptr);
    ~Speedo();
protected:
    void paintEvent(QPaintEvent* event);


private:
    Ui::Speedo *ui;
    int m_radius;
    int m_refSize;
    int m_maxSpeed;
    int m_minSpeed;
    int m_startAngle;
    int m_anglePerVel;
    int m_endAngle;
    int m_curSpeed;
    QTimer *m_updateTimer;
    double m_value;
    QColor m_foreground;
    QColor m_background;
    QString m_title;
    QLCDNumber *m_lcd_Mileage;//显示总里程



    void drawFrame(QPainter &painter);
    void drawNumberIndicator(QPainter &painter);
    void drawDividing(QPainter &painter);
    void drawNumberSpeed(QPainter &painter);
    void drawIndicator(QPainter &painter);
    void drawTitle(QPainter &painter);

private slots:
    void UpdateAngle();

};

#endif // SPEEDO_H
