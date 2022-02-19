#include "widget.h"
#include "ui_widget.h"




void Widget::initServerSignals()   //初始化信号槽
{
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));


}
bool Widget::startServer()         //启动服务器
{

    if(m_server.listen(QHostAddress::AnyIPv4,ui->ipPort->text().toInt()))       //只监听IPV4的所有客户端
    {
        ui->targetLabel->show();
        ui->targetObject->show();
        ui->localPort->setText(QString("%1").arg(m_server.serverPort()));

        return true;
    }
    else
       return false;

}

void Widget::onServerNewConnection()
{
    qDebug() << "onNewConnection";
    QTcpSocket* tcp = m_server.nextPendingConnection();     //获取新的客户端信息

    QString info=tcp->peerAddress().toString()+":"+QString("%1").arg(tcp->peerPort());
    ui->targetObject->addItem(info);
    QMessageBox::information(this,"提示",QString("新的客户端连入:%1").arg(info),QMessageBox::Ok);

    tcp->setObjectName(info);       //设置名称,方便查找

    connect(tcp, SIGNAL(connected()), this, SLOT(onServerConnected()));
    connect(tcp, SIGNAL(disconnected()), this, SLOT(onServerDisconnected()));
    connect(tcp, SIGNAL(readyRead()), this, SLOT(onServerDataReady()));
    connect(tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(onServerBytesWritten(qint64)));

}
void Widget::onServerConnected()
{

}
void Widget::onServerDisconnected()
{
    QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(sender());

    if( tcp != NULL )       //从连接对象中移除掉
    {
        qDebug() << "onServerDisconnected";
        qDebug() << "Local Address:" << tcp->peerAddress();
        qDebug() << "Local Port:" << tcp->peerPort();


        QString info=tcp->peerAddress().toString()+":"+QString("%1").arg(tcp->peerPort());

        QMessageBox::information(this,"提示",QString("客户端断开连接:%1").arg(info),QMessageBox::Ok);

        int index = ui-> targetObject ->findText(info);
        if(index>=0)
        ui->targetObject->removeItem(index);
    }

}
void Widget::onServerDataReady()
{
    QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(sender());

    if(tcp->peerAddress().toString()!=targetAddr || tcp->peerPort()!=targetPort  )
    {
        targetAddr = tcp->peerAddress().toString();
        targetPort = tcp->peerPort();

        ui->recvEdit->insertPlainText("[接受来自"+ targetAddr+":"+QString("%1").arg(targetPort)+"]:\r\n");

    }

    ui->recvEdit->moveCursor(QTextCursor::End);

    if(ui->hexRecv->isChecked())        //十六进制接收？
    {
          QByteArray data =  tcp->readAll();


          for(int i=0;i<data.length();i++)
          {

              ui->recvEdit->insertPlainText(QString("%1 ").arg((unsigned char)data[i],2,16,QChar('0')).toUpper());

          }
          ui->recvEdit->insertPlainText("\r\n");
    }
    else
        ui->recvEdit->insertPlainText(QString::fromLocal8Bit(tcp->readAll())+"\r\n");


}
void Widget::onServerBytesWritten(qint64 bytes)
{
    qDebug() << "onBytesWritten:" << bytes;

    ui->sendLenLabel->setText(QString("%1").arg(ui->sendLenLabel->text().toInt()+bytes));

}
