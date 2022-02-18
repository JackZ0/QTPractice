#include "tcpserverdialog.h"
#include "ui_tcpserverdialog.h"
#include <QTcpSocket>
#include <QRegExp>
#include <QValidator>
TcpserverDialog::TcpserverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpserverDialog)
{
    ui->setupUi(this);

    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx,this);
    ui->txtPort->setValidator(validator);

    m_ip = ui->txtIp->text().trimmed();
    m_port = ui->txtPort->text().trimmed();
    m_sendBuff = ui->txtSend->toPlainText().trimmed();

}

TcpserverDialog::~TcpserverDialog()
{
    delete ui;
}

void TcpserverDialog::sendData()
{
    //获取服务端数据
    QString sWriteData = m_sendBuff.at(qrand()%m_sendBuff.size());
    //获取与客户端通信的socket
    QTcpSocket *pClientConnection  = m_tcpserver->nextPendingConnection();
    //从客户端读数据
    QString sReadData = pClientConnection->readAll();
    pClientConnection->write(sWriteData.toUtf8());


}

void TcpserverDialog::on_btnSend_clicked()
{
    qDebug() << "发送" << endl;
    sendData();
}





void TcpserverDialog::on_btnConnect_clicked()
{
    bool ret;
    if(ui->btnConnect->text() == "连接")
    {

    }
}
