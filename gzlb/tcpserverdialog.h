#ifndef TCPSERVERDIALOG_H
#define TCPSERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>

namespace Ui {
class TcpserverDialog;
}

class TcpserverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TcpserverDialog(QWidget *parent = nullptr);
    ~TcpserverDialog();



    QString port() const
    {
        return m_port;
    }

    QString receiveBuff() const
    {
        return m_receiveBuff;
    }

    QString sendBuff() const
    {
        return m_sendBuff;
    }

    QString ip() const
    {
        return m_ip;
    }

    QTcpServer * name() const
    {
        return m_tcpserver;
    }

public slots:


    void setport(QString port)
    {
        if (m_port == port)
            return;

        m_port = port;
        emit portChanged(m_port);
    }

    void setreceiveBuff(QString receiveBuff)
    {
        if (m_receiveBuff == receiveBuff)
            return;

        m_receiveBuff = receiveBuff;
        emit receiveBuffChanged(m_receiveBuff);
    }

    void setsendBuff(QString sendBuff)
    {
        if (m_sendBuff == sendBuff)
            return;

        m_sendBuff = sendBuff;
        emit sendBuffChanged(m_sendBuff);
    }

    void setip(QString ip)
    {
        if (m_ip == ip)
            return;

        m_ip = ip;
        emit ipChanged(m_ip);
    }

    void setName(QTcpServer * tcpserver)
    {
        if (m_tcpserver == tcpserver)
            return;

        m_tcpserver = tcpserver;
        emit nameChanged(m_tcpserver);
    }

    void sendData();
signals:


    void portChanged(QString port);

    void receiveBuffChanged(QString receiveBuff);

    void sendBuffChanged(QString sendBuff);

    void ipChanged(QString ip);

    void nameChanged(QTcpServer * tcpserver);

private slots:
    void on_btnSend_clicked();



    void on_btnConnect_clicked();

private:
    Ui::TcpserverDialog *ui;
    QString m_port;
    QString m_receiveBuff;
    QString m_sendBuff;
    QString m_ip;
    QTcpServer * m_tcpserver;
};

#endif // TCPSERVERDIALOG_H
