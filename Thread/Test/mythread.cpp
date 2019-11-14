#include "mythread.h"
#include <QDebug>

MyThread::MyThread()
{
    m_Stopped = false;
}

void MyThread::setMessage(const QString &message)
{
    m_MessageStr = message;
}

void MyThread::stop()
{
    m_Stopped = true;
}

void MyThread::run()
{
    while(!m_Stopped)
        qDebug()<<m_MessageStr<<m_MessageStr<<m_MessageStr;
    m_Stopped = false;
}
