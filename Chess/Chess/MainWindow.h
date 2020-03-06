#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
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
    QPoint _ptClick;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
