#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);
    ~mythread();

    void MyTimeout();

    void setFlag(bool flag = true);

signals:
    void mySignal();

public slots:

private:
    bool m_isStop;


};

#endif // MYTHREAD_H
