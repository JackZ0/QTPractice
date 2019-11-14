#include "threaddialog.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QCloseEvent>
#include <QDebug>
#include <iostream>

using namespace std;
ThreadDialog::ThreadDialog(QWidget *parent)
    : QDialog(parent)
{

    m_ThreadA.setMessage("A");
    m_ThreadB.setMessage("B");
    m_ThreadC.setMessage("C");

    m_ThreadAButton = new QPushButton;
    m_ThreadAButton->setText("Sart A");
    m_ThreadBButton = new QPushButton;
    m_ThreadBButton->setText(tr("Start B"));
    m_ThreadCButton = new QPushButton;
    m_ThreadCButton->setText(tr("Start C"));
    m_QuitButton = new QPushButton;
    m_QuitButton->setText(tr("Quit"));
    m_QuitButton->setDefault(true);

    connect(m_ThreadAButton,SIGNAL(clicked(bool)),SLOT(startOrStopThreadA()));
    connect(m_ThreadBButton,SIGNAL(clicked(bool)),SLOT(startOrStopThreadB()));
    connect(m_ThreadCButton,SIGNAL(clicked(bool)),SLOT(startOrStopThreadC()));
    connect(m_QuitButton,SIGNAL(clicked(bool)),SLOT(close()));

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(m_ThreadAButton);
    hLayout->addWidget(m_ThreadBButton);
    hLayout->addWidget(m_ThreadCButton);
    hLayout->addWidget(m_QuitButton);
    setLayout(hLayout);
    setWindowTitle(tr("Thread"));
}

ThreadDialog::~ThreadDialog()
{
}


//int ThreadDialog::ThreadDialogfuncA(int a){
//    cout << a << endl;
//    return a;
//}
//QString ThreadDialog::ThreadDialogfuncB(){
//    return "B";
//}

//QString ThreadDialog::ThreadDialogfuncC(){
//    return "C";
//}


void ThreadDialog::closeEvent(QCloseEvent *event)
{
    m_ThreadA.stop();
    m_ThreadB.stop();

    m_ThreadA.wait();
    m_ThreadB.wait();

    event->accept();
}

void ThreadDialog::startOrStopThreadA()
{
    if(m_ThreadA.isRunning())
    {
        m_ThreadA.stop();
        m_ThreadAButton->setText(tr("Start A"));
        qDebug()<<" A 线程停止";
    }
    else
    {
        m_ThreadA.start();
        m_ThreadAButton->setText(tr("Stop A"));
    }
}

void ThreadDialog::startOrStopThreadB()
{
    if(m_ThreadB.isRunning())
    {
        m_ThreadB.stop();
        m_ThreadBButton->setText(tr("Start B"));
        qDebug()<<"B线程停止";
    }
    else
    {
        m_ThreadB.start();
        m_ThreadBButton->setText(tr("Stop B"));
    }
}
void ThreadDialog::startOrStopThreadC()
{
    if(m_ThreadC.isRunning())
    {
        m_ThreadC.stop();
        m_ThreadCButton->setText(tr("Start C"));
        qDebug()<<"C线程停止";
    }
    else
    {
        m_ThreadC.start();
        m_ThreadCButton->setText(tr("Stop C"));
    }
}
