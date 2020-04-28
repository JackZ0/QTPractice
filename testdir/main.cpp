#include "MainWindow.h"
#include <QApplication>
#include <QDir>
#include <QTime>

#include <QDebug>
QStringList filelist;
int k;
int FindFile(const QString& _filePath)
{

    QDir dir(_filePath);
    if (!dir.exists()) {
        return -1;
    }
  //取到所有的文件和文件名，但是去掉.和..的文件夹（这是QT默认有的）
    dir.setFilter(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);
    //文件夹优先
    dir.setSorting(QDir::DirsFirst);
    //转化成一个list
    QFileInfoList list = dir.entryInfoList();
    QStringList infolist = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    if(list.size()< 1 ) {
        return -1;
    }
    int i=0;
    //递归算法的核心部分
    do{
        QFileInfo fileInfo = list.at(i);
        //如果是文件夹，递归
        bool bisDir = fileInfo.isDir();
        if(bisDir) {
            FindFile(fileInfo.filePath());
        }
        else{
            for(int m = 0; m <infolist.size(); m++) {
                                //这里是获取当前要处理的文件名
//                qDebug() << infolist.at(m);
                qDebug()<< fileInfo.dir().path() << "Path" <<endl;
                QString src=fileInfo.dir().path()+"/"+infolist.at(m);
                filelist.append(src);
                 qDebug() << "src" << src;
                QString dst = "D://allback/"+QString::number(k)+".jpg";
                qDebug()<< "dest" << dst << endl;
                QFile file(src);
                file.copy(dst);
                k++;
            }
            break;
        }//end else
        i++;

//        qDebug() <<fileInfo.filePath() << "||"<< src << endl;

    } while(i < list.size());
}
int main(int argc, char *argv[])
{
    int j = 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString _filePath = "D://111111";
    QDir dir(_filePath);
        if (!dir.exists()) {
            return -1;
        }

      //取到所有的文件和文件名，但是去掉.和..的文件夹（这是QT默认有的）
        dir.setFilter(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);

        //文件夹优先
        dir.setSorting(QDir::DirsFirst);

        //转化成一个list
        QFileInfoList list = dir.entryInfoList();
        if(list.size()< 1 ) {
            return -1;
        }
        int i=0;

        //递归算法的核心部分
        do{
            QFileInfo fileInfo = list.at(i);
            //如果是文件夹，递归
            bool bisDir = fileInfo.isDir();
            if(bisDir) {
                FindFile(fileInfo.filePath());
            }
            else{
                //bool isDll = fileInfo.fileName().endsWith(".dll");
//                qDebug() << fileInfo.filePath() << ":" <<fileInfo.fileName();

            }//end else
            i++;
        } while(i < list.size());

    return a.exec();
}
