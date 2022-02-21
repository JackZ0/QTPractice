#include "serialmainwindow.h"
#include "ui_serialmainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QLabel>
#include <QMessageBox>

serialMainWindow::serialMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serialMainWindow)
{
    ui->setupUi(this);
    ui->actionQuit->setEnabled(true);
    ui->actionAboutQt->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);

    ui->statusbar->addWidget(m_status);


}

serialMainWindow::~serialMainWindow()
{
    delete ui;
}

void serialMainWindow::initActionsConnections()
{

}

void serialMainWindow::openSerialPort()
{

}

void serialMainWindow::closeSerialPort()
{

}

void serialMainWindow::writeData(const QByteArray &data)
{

}

void serialMainWindow::readData()
{

}

void serialMainWindow::handleError(QSerialPort::SerialPortError error)
{

}
