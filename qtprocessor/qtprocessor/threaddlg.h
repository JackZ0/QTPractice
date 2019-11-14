#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYTHREAD_H