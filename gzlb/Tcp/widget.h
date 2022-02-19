#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMessageBox>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT


    QTcpSocket m_client;
    QTcpServer m_server;


    QString targetAddr;
    int targetPort;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void on_btn_switch_clicked();
    void on_tcpMode_currentIndexChanged(int index);
    void on_btn_send_clicked();             //发送按钮
    void on_betn_clear_clicked();           //清空按钮


    //客户端槽函数
    void onClientConnected();
    void onClientDisconnected();
    void onClientDataReady();
    void onClientBytesWritten(qint64 bytes);
    void onClientErr(QAbstractSocket::SocketError socketError);
    //服务器槽函数
    void onServerNewConnection();
    void onServerConnected();
    void onServerDisconnected();
    void onServerDataReady();
    void onServerBytesWritten(qint64 bytes);

private:
    void startConnect(bool ison);


    void initClientSignals();   //初始化客户端信号槽
    bool startClient();         //启动客户端


    void initServerSignals();   //初始化客户端信号槽
    bool startServer();     //启动服务器

    Ui::Widget *ui;
};

#endif // WIDGET_H
