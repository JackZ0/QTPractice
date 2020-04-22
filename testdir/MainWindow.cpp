#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     m_serialPort = new QSerialPort();
     getPortInfo();
     setPortConfig();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPortInfo()
{
    QStringList m_serialPortname;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        m_serialPortname <<info.portName();
        qDebug() << "serialportname" << info.portName();
        qDebug() << "description" << info.description();
        m_serialPort->setPortName(info.portName());
        qDebug() << "Manufacturer: " << info.manufacturer();
       qDebug() << "Serial Number: " << info.serialNumber();
       qDebug() << "System Location: " << info.systemLocation();
    }
}


void MainWindow::setPortConfig()
{
    if(m_serialPort->isOpen()){
        m_serialPort->clear();
        m_serialPort->close();
    }
//    m_serialPort->setPortName("com1");
    if(!m_serialPort->open(QIODevice::ReadWrite)){
        qDebug() << m_serialPort << "打开失败";
        return;
    }
    m_serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
}

void MainWindow::getData()
{

}

void MainWindow::receiveInfo()
{
    QByteArray info = m_serialPort->readAll();
    QByteArray hexData = info.toHex();
    qDebug() << hexData << "hexData" << endl;
    if(hexData == "0x01"){
        qDebug() <<"run normal" << endl;
    }
    else {
        qDebug() << "run unnormal" << endl;
    }
}

void MainWindow::sendSerialData()
{
   m_serialPort->write("send !");
}
