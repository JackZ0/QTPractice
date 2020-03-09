#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QChart>
#include <QGraphicsScene>

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
    QGraphicsScene *m_pScence;
};

#endif // DIALOG_H
