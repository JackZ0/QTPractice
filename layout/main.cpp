#include "MainWindow.h"
#include <QApplication>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QGridLayout *gridlayout= new QGridLayout();
    QHBoxLayout *hlayout = new QHBoxLayout();
    QHBoxLayout *hlayout2 = new QHBoxLayout();
    QHBoxLayout *hlayout3 = new QHBoxLayout();
    QVBoxLayout *vlayout = new QVBoxLayout();

    QPushButton *button1 = new QPushButton();
    button1->setText("button1");
    QPushButton *button2 = new QPushButton();
    button2->setText("button2");
    QPushButton *button3 = new QPushButton();
    button3->setText("button3");
    QPushButton *button4 = new QPushButton();
    button4->setText("button4");
    QPushButton *button5 = new QPushButton();
    button5->setText("button5");
    QPushButton *button6 = new QPushButton();
    button6->setText("button6");
    QPushButton *button7 = new QPushButton();
    button7->setText("button7");
    QPushButton *button8 = new QPushButton();
    button8->setText("button8");
    QPushButton *button9 = new QPushButton();
    button9->setText("button9");
    QPushButton *button10 = new QPushButton();
    button10->setText("button10");
    QPushButton *button11 = new QPushButton();
    button11->setText("button11");
    QPushButton *button12 = new QPushButton();
    button12->setText("button12");
    QPushButton *button13 = new QPushButton();
    button13->setText("button13");
    QPushButton *button14 = new QPushButton();
    button14->setText("button14");
    QPushButton *button15 = new QPushButton();
    button15->setText("button15");
    QPushButton *button16 = new QPushButton();
    button16->setText("button16");

    QLabel *label = new QLabel();
    label->setText("asdfasdfasdfsdf");
    hlayout3->addWidget(label);

    hlayout->addWidget(button1);
    hlayout->addWidget(button2);
    hlayout->addWidget(button3);
    hlayout->addWidget(button4);
    hlayout->addWidget(button5);
    hlayout->addWidget(button6);
    hlayout->addWidget(button7);
    hlayout->addWidget(button8);


    hlayout2->addWidget(button9);
    hlayout2->addWidget(button10);
    hlayout2->addWidget(button11);
    hlayout2->addWidget(button12);
    hlayout2->addWidget(button13);
    hlayout2->addWidget(button14);
    hlayout2->addWidget(button15);
    hlayout2->addWidget(button16);

   gridlayout->addLayout(hlayout,0,0);
   gridlayout->addLayout(hlayout3,1,0);
   gridlayout->addLayout(hlayout2,2,0);

   QWidget *widget = new QWidget();
   widget->setLayout(gridlayout);
   w.setCentralWidget(widget);
   w.show();
   return a.exec();
}
