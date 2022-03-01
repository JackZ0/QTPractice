#ifndef CONVERT_H
#define CONVERT_H

#include <QWidget>

namespace Ui {
class Convert;
}

class Convert : public QWidget
{
    Q_OBJECT

public:
    explicit Convert(QWidget *parent = nullptr);
    ~Convert();

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

private:
    Ui::Convert *ui;
};

#endif // CONVERT_H
