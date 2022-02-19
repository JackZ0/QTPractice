#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QNetworkInterface>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    startConnect(false);
    on_tcpMode_currentIndexChanged(0);

    initClientSignals();        //初始化客户端信号槽
    initServerSignals();        //初始化服务器信号槽

    //限制只能数字输入
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, this );
    ui->ipAddr1->setValidator( validator );
    ui->ipAddr2->setValidator( validator );
    ui->ipAddr3->setValidator( validator );
    ui->ipAddr4->setValidator( validator );
    ui->ipPort->setValidator( validator );


    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface interface, list)  //遍历本地每个网络接口
    {
          if(interface.hardwareAddress() == "00:00:00:00:00:00:00:E0") //去掉这个MAC地址
                              continue;
          if(interface.hardwareAddress().isEmpty())
                            continue;

       qDebug() << "MAC Address:" << interface.hardwareAddress();

        foreach(QNetworkAddressEntry entry, interface.addressEntries())//遍历每一个IP地址条目
        {
            QHostAddress address2=entry.ip();
            if(address2.protocol() == QAbstractSocket::IPv4Protocol)
            {
                if(entry.ip().toString() == "127.0.0.1")//去掉回环
                    continue;
                //IP地址
                qDebug() << "IP Address: " << entry.ip().toString();
                if(entry.ip().toString().left(7)=="192.168")
                {
                   int addr3,addr4;         //更新地址用
                   sscanf(entry.ip().toString().toLocal8Bit(),"192.168.%d.%d",&addr3,&addr4);

                   ui->ipAddr3->setText(QString("%1").arg(addr3));
                   ui->ipAddr4->setText(QString("%1").arg(addr4));

                }
            }
        }
    }
}

void Widget::on_tcpMode_currentIndexChanged(int index)
{
    if(index==0)        //clent
    {
        ui->ipPortLabel->setText("服务器端口号:");
        ui->ipAddLabel->show();
        ui->ipAdds->show();

        ui->targetLabel->hide();
        ui->targetObject->hide();
    }
    else
    {

        ui->ipAddLabel->hide();
        ui->ipAdds->hide();
        ui->ipPortLabel->setText("本地端口号:");

    }

}




void Widget::on_btn_switch_clicked()        //切换连接开关
{
    bool ret;
    if(ui->btn_switch->text()=="打开连接")
    {
        if(ui->tcpMode->currentIndex()==0)  //启动客户端
           ret=startClient() ;
        else
            ret=startServer();

        if(ret)
            startConnect(true);
    }

    else
    {
        if(ui->tcpMode->currentIndex()==0)  //启动客户端
          m_client.close();
        else
        {
            if( m_server.isListening() )
            {
                QList<QTcpSocket *> m_tcps = m_server.findChildren<QTcpSocket *>();
                foreach (QTcpSocket *tcp, m_tcps)
                {

                    tcp->close();
                }
                m_server.close();
            }
        }
        startConnect(false);
    }

}

void Widget::startConnect(bool ison)
{
    if(!ison)
    {
        ui->btn_switch->setStyleSheet("color:blue;border: 1px solid blue");
        ui->btn_switch->setText("打开连接");

        //失能
        ui->ipAddr1->setEnabled(true);
        ui->ipAddr2->setEnabled(true);
        ui->ipAddr3->setEnabled(true);
        ui->ipAddr4->setEnabled(true);
        ui->tcpMode->setEnabled(true);
        ui->ipPort->setEnabled(true);
        ui->localPort->setText("");
    }
    else
    {
        ui->btn_switch->setStyleSheet("color:red;border: 1px solid red");
        ui->btn_switch->setText("关闭连接");

        //失能
        ui->ipAddr1->setEnabled(false);
        ui->ipAddr2->setEnabled(false);
        ui->ipAddr3->setEnabled(false);
        ui->ipAddr4->setEnabled(false);
        ui->tcpMode->setEnabled(false);
        ui->ipPort->setEnabled(false);


        targetAddr="";
        targetPort=0;
        ui->sendLenLabel->setText("0");
    }
}

void Widget::on_betn_clear_clicked()
{
   ui->recvEdit->clear();
   targetAddr="";
   targetPort=0;
}


void Widget::on_btn_send_clicked()
{
    if(ui->btn_switch->text()!="打开连接")
    {
        unsigned char buf[255];
        int bufLen=0;

        if(ui->tcpMode->currentIndex()==0)  //客户端
        {

            if(ui->hexSend->isChecked())        //十六进制发送？
            {
                QString data = ui->sendEdit->toPlainText();
                QByteArray arr=data.toLocal8Bit();
                while(arr.length()!=0)
                {
                    sscanf(arr,"%2x",&buf[bufLen]);
                    //qDebug()<<"write:"<<bufLen<<buf[bufLen];
                    bufLen+=1;
                    arr= data.remove(0,3).toLocal8Bit();
                }
                m_client.write((char *)buf,bufLen);
            }
            else
             m_client.write(ui->sendEdit->toPlainText().toLocal8Bit(),ui->sendEdit->toPlainText().toLocal8Bit().length());

        }
        else
        {

            if(ui->hexSend->isChecked())  //十六进制发送
            {
                QString data = ui->sendEdit->toPlainText();
                QByteArray arr=data.toLocal8Bit();
                while(arr.length()!=0)
                {
                    sscanf(arr,"%2x",&buf[bufLen]);
                    //qDebug()<<"write:"<<bufLen<<buf[bufLen];
                    bufLen+=1;
                    arr= data.remove(0,3).toLocal8Bit();
                }
            }
            if(ui->targetObject->currentText()!="所有对象")
            {
                QList<QTcpSocket *> m_tcps = m_server.findChildren<QTcpSocket *>();
                foreach (QTcpSocket *tcp, m_tcps)
                {

                    if(ui->targetObject->currentText() == tcp->objectName())
                    {
                        if(ui->hexSend->isChecked())
                        {
                             tcp->write((char *)buf,bufLen);
                        }
                        else
                           tcp->write(ui->sendEdit->toPlainText().toLocal8Bit(),ui->sendEdit->toPlainText().toLocal8Bit().length());
                        break;
                    }

                }
            }
            else            //所有连接上的客户端都发送一遍
            {
                QList<QTcpSocket *> m_tcps = m_server.findChildren<QTcpSocket *>();
                foreach (QTcpSocket *tcp, m_tcps)
                {
                    if(ui->hexSend->isChecked())
                    {
                         tcp->write((char *)buf,bufLen);
                    }
                    else
                         tcp->write(ui->sendEdit->toPlainText().toLocal8Bit(),ui->sendEdit->toPlainText().toLocal8Bit().length());

                }
            }

        }
    }

}

Widget::~Widget()
{

    QList<QTcpSocket *> m_tcps = m_server.findChildren<QTcpSocket *>();
    foreach (QTcpSocket *tcp, m_tcps)
    {

        tcp->close();
    }


    if(m_client.isOpen())
    {
        m_client.close();
         qDebug()<<"m_client close";
    }

    delete ui;
}




