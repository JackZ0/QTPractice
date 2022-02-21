#ifndef SERIALMAINWINDOW_H
#define SERIALMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSerialPort>
#include "serialport/console.h"
#include "serialport/settingsdialog.h"

namespace Ui {
class serialMainWindow;
}

class serialMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit serialMainWindow(QWidget *parent = nullptr);
    ~serialMainWindow();

private:
    Ui::serialMainWindow *ui;
    QLabel *m_status = nullptr;
    Console *m_console = nullptr;
    SettingsDialog *m_setting = nullptr;

    void initActionsConnections();
private slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

};

#endif // SERIALMAINWINDOW_H
