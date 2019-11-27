#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>


class QNetworkReply;
class QNetworkAccessManager;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
     QNetworkAccessManager *manager;
    Ui::MainWindow *ui;
private slots:
    void replyFinished(QNetworkReply *);
};

#endif // MAINWINDOW_H
