#include "serialmainwindow.h"
#include "ui_serialmainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QLabel>
#include <QMessageBox>

serialMainWindow::serialMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serialMainWindow),
    m_status(new QLabel),
    m_console(new Console),
    m_setting(new SettingsDialog),
    m_serial(new QSerialPort(this))
{
    ui->setupUi(this);
    ui->actionQuit->setEnabled(true);
    ui->actionAboutQt->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);

    ui->statusbar->addWidget(m_status);


    initActionsConnections();

    connect(m_serial, &QSerialPort::errorOccurred, this, &serialMainWindow::handleError);

    connect(m_serial, &QSerialPort::readyRead, this, &serialMainWindow::readData);

    connect(m_console, &Console::getData, this, &serialMainWindow::writeData);

}

serialMainWindow::~serialMainWindow()
{
    delete ui;
}

void serialMainWindow::initActionsConnections()
{
    connect(ui->actionConnect,&QAction::triggered,this, &serialMainWindow::openSerialPort);
    connect(ui->actionDisconnect,&QAction::triggered,this,&serialMainWindow::closeSerialPort);
    connect(ui->actionQuit,&QAction::triggered,this,&serialMainWindow::close);
    connect(ui->actionClear, &QAction::triggered, m_console, &Console::clear);
    connect(ui->actionConfigure,&QAction::triggered, m_setting, &SettingsDialog::show);
    connect(ui->actionAboutQt, &QAction::triggered, qApp,&QApplication::aboutQt);

}

void serialMainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}

void serialMainWindow::openSerialPort()
{
    const SettingsDialog::Settings p = m_setting->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);

    if(m_serial->open(QIODevice::ReadWrite))
    {
        m_console->setEnabled(true);
        m_console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(true);
        ui->actionDisconnect->setEnabled(false);
        ui->actionConfigure->setEnabled(false);

        showStatusMessage(tr("Connected to %1: %2 ,%3, %4, %5, %6").arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

    }
    else
    {
        QMessageBox::critical(this, tr("Error"),m_serial->errorString());
        showStatusMessage(tr("Open error"));
    }
}

void serialMainWindow::closeSerialPort()
{
    if(m_serial->isOpen())
        m_serial->close();
    m_console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}

void serialMainWindow::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

void serialMainWindow::readData()
{
    const QByteArray data = m_serial->readAll();
    m_console->putData(data);
}

void serialMainWindow::handleError(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this,tr("Critical Error"),m_serial->errorString());
        closeSerialPort();
    }
}
