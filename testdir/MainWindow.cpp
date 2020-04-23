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
    QStringList baud,stopbit,check,databit;
    baud << "115200"<<  "76800"<<"9600"<< "4800" << "2400" <<"1200";
    stopbit << "1" << "1.5" << "2";
    check << "无" << "奇校验" << "偶校验" ;
    for(int i=5; i<9;i++ )
    {
        databit.append(QString::number(i));
    }
    ui->comboBoxBaud->addItems(baud);
    ui->comboBoxStop->addItems(stopbit);
    ui->comboBoxCheck->addItems(check);
    ui->comboBoxDataBit->addItems(databit);
    getPortInfo();
    setPortConfig();
    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPortInfo()
{
    QStringList m_serialPortname;
    m_serialPortname.clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        m_serialPortname << info.portName();
        qDebug() << "serialportname" << info.portName();
        qDebug() << "description" << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        qDebug() << "Serial Number: " << info.serialNumber();
        qDebug() << "System Location: " << info.systemLocation();
    }
    ui->comboBoxSerialNum->addItems(m_serialPortname);
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

void MainWindow::on_pushButtonOperation_clicked()
{
    if (ui->pushButtonOperation->text() == tr("open")){
        int baudselect = ui->comboBoxBaud->currentIndex();
        int databit = ui->comboBoxDataBit->currentIndex();
        int check = ui->comboBoxCheck->currentIndex();
        int stop = ui->comboBoxStop->currentIndex();
        switch (baudselect) {
        case 0:
            m_serialPort->setBaudRate(QSerialPort::Baud115200);
            break;
        case 1:
            m_serialPort->setBaudRate(QSerialPort::Baud19200);
            break;
        case 2:
            m_serialPort->setBaudRate(QSerialPort::Baud4800);
            break;
        case 3:
            m_serialPort->setBaudRate(QSerialPort::Baud2400);
            break;
        default:
            break;
        }
        switch (databit) {
        case 0:
            m_serialPort->setDataBits(QSerialPort::Data5);
            break;
        case 1:
            m_serialPort->setDataBits(QSerialPort::Data6);
            break;
        case 2:
            m_serialPort->setDataBits(QSerialPort::Data7);
            break;
        case 3:
            m_serialPort->setDataBits(QSerialPort::Data8);
            break;
        default:
            break;
        switch (check) {
         case 0:
            m_serialPort->setParity(QSerialPort::NoParity);
            break;
        case 1:
            m_serialPort->setParity(QSerialPort::EvenParity);
            break;
        case 2:
            m_serialPort->setParity(QSerialPort::OddParity);
            break;
        default:
            break;
        }
        switch (stop) {
        case 0:
            m_serialPort->setStopBits(QSerialPort::UnknownStopBits);
            break;
        case 1:
            m_serialPort->setStopBits(QSerialPort::OneStop);
            break;
        case 2:
            m_serialPort->setStopBits(QSerialPort::OneAndHalfStop);
            break;
        case 3:
            m_serialPort->setStopBits(QSerialPort::TwoStop);
            break;
        default:
            break;
        }
        }
        m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
        ui->comboBoxBaud->setEnabled(false);
        ui->comboBoxCheck->setEnabled(false);
        ui->comboBoxDataBit->setEnabled(false);
        ui->comboBoxSerialNum->setEnabled(false);
        ui->comboBoxStop->setEnabled(false);
        ui->pushButtonOperation->setText("close");
    }else{
        m_serialPort->close();
        ui->comboBoxBaud->setEnabled(true);
        ui->comboBoxCheck->setEnabled(true);
        ui->comboBoxDataBit->setEnabled(true);
        ui->comboBoxSerialNum->setEnabled(true);
        ui->comboBoxStop->setEnabled(true);
        ui->pushButtonOperation->setText("open");
    }
}
