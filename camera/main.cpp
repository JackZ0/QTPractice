#include <QtWidgets/QApplication>
#include <QTextCodec>
#include "widget.h"

int main(int argc, char *argv[])
{
   // QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
