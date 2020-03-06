#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *);

    virtual void mousePressEvent(QMouseEvent *ev);

    QPushButton* _button;

    QPoint _ptClick;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
