#ifndef SERIALWIDGET_H
#define SERIALWIDGET_H

#include <QWidget>

namespace Ui {
class serialWidget;
}

class serialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit serialWidget(QWidget *parent = nullptr);
    ~serialWidget();

private:
    Ui::serialWidget *ui;
};

#endif // SERIALWIDGET_H
