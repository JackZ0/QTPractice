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

private:
    Ui::Convert *ui;
};

#endif // CONVERT_H
