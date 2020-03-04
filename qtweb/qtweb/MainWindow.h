#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintDevice>
#include <QPen>
#include <QLabel>
#include <QPainter>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionStart_triggered();

    void on_actionStop_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionConf_triggered();

private:

    QGraphicsScene *scene;
    Ui::MainWindow *ui;

    void DrawRect(int posx,int posy,QString lable,QGraphicsScene *scenePare);

};

#endif // MAINWINDOW_H
