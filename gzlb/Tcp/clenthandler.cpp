#include "widget.h"
#include "ui_widget.h"


void Widget::initClientSignals()  //初始化客户端信号槽
{
    connect(&m_client, SIGNAL(connected()), this, SLOT(onClientConnected()));
    connect(&m_client, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
    connect(&m_client, SIGNAL(readyRead()), this, SLOT(onClientDataReady()));
    connect(&m_client, SIGNAL(bytesWritten(qint64)), this, SLOT(onClientBytesWritten(qint64)));
    connect(&m_client, SIGNAL(error(QAbstractSocket::SocketError )), this, SLOT(onClientErr(QAbstractSocket::SocketError)));

}
bool Widget::startClient()         //启动客户端
{
    QString ip = QString("%1.%2.%3.%4").arg(ui->ipAddr1->text()).arg(ui->ipAddr2->text()).arg(ui->ipAddr3->text()).arg(ui->ipAddr4->text());
    qDebug()<<ip;
    m_client.connectToHost(ip, ui->ipPort->text().toInt());

    if(m_client.waitForConnected(800))
    {
        return true;
    }
    else
    {

        QMessageBox::information(this,"提示",QString("连接超时"),QMessageBox::Ok);
        return false;
    }

}

void Widget::onClientConnected()
{
    startConnect(true);
    QMessageBox::information(this,"提示","连接成功",QMessageBox::Ok);


    ui->localPort->setText(QString("%1").arg(m_client.localPort())); //显示本地端口号

}
void Widget::onClientDisconnected()
{
    startConnect(false);
    QMessageBox::information(this,"提示","断开完成",QMessageBox::Ok);
}

void Widget::onClientDataReady()
{

    if(m_client.peerAddress().toString()!=targetAddr || m_client.peerPort()!=targetPort  )
    {
        targetAddr = m_client.peerAddress().toString();
        targetPort = m_client.peerPort();

        ui->recvEdit->insertPlainText("[接受来自"+ targetAddr+":"+QString("%1").arg(targetPort)+"]:\r\n");

    }

    ui->recvEdit->moveCursor(QTextCursor::End);

    if(ui->hexRecv->isChecked())        //十六进制接收？
    {
          QByteArray data =  m_client.readAll();


          for(int i=0;i<data.length();i++)
          {

              ui->recvEdit->insertPlainText(QString("%1 ").arg((unsigned char)data[i],2,16,QChar('0')).toUpper());

          }
          ui->recvEdit->insertPlainText("\r\n");
    }
    else
        ui->recvEdit->insertPlainText(QString::fromLocal8Bit(m_client.readAll())+"\r\n");


}
void Widget::onClientBytesWritten(qint64 bytes)
{
    qDebug() << "onBytesWritten:" << bytes;

    ui->sendLenLabel->setText(QString("%1").arg(ui->sendLenLabel->text().toInt()+bytes));

}

void  Widget::onClientErr(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"onClientErr:"<<socketError;

    m_client.close();
    startConnect(false);
    QMessageBox::information(this,"提示",QString("连接失败:%1").arg((int)socketError),QMessageBox::Ok);
}
