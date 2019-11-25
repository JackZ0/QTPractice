#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createView();
}

void Widget::createView()
{
    //初始化
    mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);
    m_PushButton1 = new QPushButton("Button1");
    m_PushButton2 = new QPushButton("Button2");

    //设置控件唯一ID名称
    m_PushButton1->setObjectName("Button1");
    m_PushButton2->setObjectName("Button2");

    //添加按钮
    mainLayout->addWidget(m_PushButton1);
    mainLayout->addWidget(m_PushButton2);

    connect(m_PushButton1,SIGNAL(clicked(bool)),this,SLOT(On_ClickedButton()));
    connect(m_PushButton2,SIGNAL(clicked(bool)),this,SLOT(On_ClickedButton()));
}

void Widget::On_ClickedButton()
{
    QString m_ObjectName = sender()->objectName();
    if(m_ObjectName.compare(QStringLiteral("Button1"))==0)
    {
        qDebug()<<m_ObjectName;
    }
    else if (m_ObjectName.compare(QStringLiteral("Button2"))==0)
    {
        qDebug()<<m_ObjectName;
    }
}
