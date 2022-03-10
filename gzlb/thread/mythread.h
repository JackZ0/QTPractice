#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);
    ~mythread();

    void myTimeOut();
    void setFlag(bool flag = true);


signals:
    void myThreadSignal();

public slots:

private:
    bool m_isStop;




};

#endif // MYTHREAD_H
