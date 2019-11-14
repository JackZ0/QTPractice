#ifndef THREADDIALOG_H
#define THREADDIALOG_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include "mythread.h"

class ThreadDialog : public QDialog
{
    Q_OBJECT

public:
    ThreadDialog(QWidget *parent = 0);
    ~ThreadDialog();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void startOrStopThreadA();
    void startOrStopThreadB();
    void startOrStopThreadC();


private:
   MyThread m_ThreadA;
   MyThread m_ThreadB;
   MyThread m_ThreadC;

   int ThreadDialogfuncA(int a,int b);

   QPushButton *m_ThreadAButton;
   QPushButton *m_ThreadBButton;
   QPushButton *m_ThreadCButton;

   QPushButton *m_QuitButton;
};

#endif // THREADDIALOG_H
