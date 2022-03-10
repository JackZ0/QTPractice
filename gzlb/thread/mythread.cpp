#include "mythread.h"
#include <QDebug>
mythread::mythread(QObject *parent )
{
    m_isStop = false;
}

mythread::~mythread()
{

}

void mythread::myTimeOut()
{
    while(false == m_isStop){
        QThread::sleep(1);
        emit myThreadSignal();
        qDebug() <<"子进程ID：" << QThread::currentThread();
        if(true == m_isStop)
        {
            break;
        }
    }
}

void mythread::setFlag(bool flag)
{
    m_isStop = flag;
}







