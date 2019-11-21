/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed Apr 3 20:17:23 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label8;
    QLabel *label6;
    QLabel *label5;
    QLabel *label7;
    QLabel *label12;
    QLabel *label10;
    QLabel *label11;
    QLabel *label9;
    QLabel *label16;
    QLabel *label13;
    QLabel *label14;
    QLabel *label15;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 650);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 620, 81, 23));
        label1 = new QLabel(Widget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(0, 0, 200, 150));
        label1->setScaledContents(false);
        label2 = new QLabel(Widget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(200, 0, 200, 150));
        label2->setScaledContents(false);
        label3 = new QLabel(Widget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(400, 0, 200, 150));
        label3->setScaledContents(false);
        label4 = new QLabel(Widget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(600, 0, 200, 150));
        label4->setScaledContents(false);
        label8 = new QLabel(Widget);
        label8->setObjectName(QString::fromUtf8("label8"));
        label8->setGeometry(QRect(600, 150, 200, 150));
        label8->setScaledContents(false);
        label6 = new QLabel(Widget);
        label6->setObjectName(QString::fromUtf8("label6"));
        label6->setGeometry(QRect(200, 150, 200, 150));
        label6->setScaledContents(false);
        label5 = new QLabel(Widget);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(0, 150, 200, 150));
        label5->setScaledContents(false);
        label7 = new QLabel(Widget);
        label7->setObjectName(QString::fromUtf8("label7"));
        label7->setGeometry(QRect(400, 150, 200, 150));
        label7->setScaledContents(false);
        label12 = new QLabel(Widget);
        label12->setObjectName(QString::fromUtf8("label12"));
        label12->setGeometry(QRect(600, 300, 200, 150));
        label12->setScaledContents(true);
        label10 = new QLabel(Widget);
        label10->setObjectName(QString::fromUtf8("label10"));
        label10->setGeometry(QRect(200, 300, 200, 150));
        label10->setScaledContents(true);
        label11 = new QLabel(Widget);
        label11->setObjectName(QString::fromUtf8("label11"));
        label11->setGeometry(QRect(400, 300, 200, 150));
        label11->setScaledContents(true);
        label9 = new QLabel(Widget);
        label9->setObjectName(QString::fromUtf8("label9"));
        label9->setGeometry(QRect(0, 300, 200, 150));
        label9->setScaledContents(true);
        label16 = new QLabel(Widget);
        label16->setObjectName(QString::fromUtf8("label16"));
        label16->setGeometry(QRect(600, 450, 200, 150));
        label16->setScaledContents(true);
        label13 = new QLabel(Widget);
        label13->setObjectName(QString::fromUtf8("label13"));
        label13->setGeometry(QRect(0, 450, 200, 150));
        label13->setScaledContents(true);
        label14 = new QLabel(Widget);
        label14->setObjectName(QString::fromUtf8("label14"));
        label14->setGeometry(QRect(200, 450, 200, 150));
        label14->setScaledContents(true);
        label15 = new QLabel(Widget);
        label15->setObjectName(QString::fromUtf8("label15"));
        label15->setGeometry(QRect(400, 450, 200, 150));
        label15->setScaledContents(true);

     //   retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi



};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
