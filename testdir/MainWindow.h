#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getPortInfo();
    void setPortConfig();


private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QSerialPort *m_serialPort;


private slots:
    void getData();
    void receiveInfo();
    void sendSerialData();
    void on_pushButtonOperation_clicked();
    void on_pushButtonClear_clicked();
};

#endif // MAINWINDOW_H
