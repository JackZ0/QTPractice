#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    void createView();

private slots:
    void On_ClickedButton();

private:
    QVBoxLayout *mainLayout;
    QPushButton *m_PushButton1;
    QPushButton *m_PushButton2;

};

#endif // WIDGET_H
