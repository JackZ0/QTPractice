#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
//class QThread;
class QString;

class MyThread : public QThread
{
public:
    MyThread();

    void setMessage(const QString &messagez);
    void stop();

protected:
    void run();

private:
    QString m_MessageStr;
    volatile bool m_Stopped;
};

#endif // MYTHREAD_H
