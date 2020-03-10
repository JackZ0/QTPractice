#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QChart>
#include <QGraphicsScene>
#include <QTimer>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QChart* m_chart;
    QTimer *m_time;
    QGraphicsScene *m_pScence;
    QLineSeries *lineSeries;
    qint64 mtLast;


    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    /**
     * @brief getData  获取数据，内部模拟生成数据变化
     * @param x X坐标
     * @return
     */
    qreal getData(qreal x);

private slots:
    void slot_timer();
};

#endif // DIALOG_H
