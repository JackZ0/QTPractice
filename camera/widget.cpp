#include "widget.h"
#include "ui_widget.h"

#include <opencv2/video.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/cvconfig.h>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_LabelList <<ui->label1<<ui->label2<<ui->label3<<ui->label4
                  <<ui->label5<<ui->label6<<ui->label7<<ui->label8
                    <<ui->label9<<ui->label10<<ui->label11<<ui->label12
                      <<ui->label13<<ui->label14<<ui->label15<<ui->label16;

    OpenCamera();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(ShowImage()));
    timer->start(40);

}

Widget::~Widget()
{
    delete ui;
    cvReleaseCapture(& m_CapList[0]);
}

//启动多线程
void Widget::on_pushButton_clicked()
{
    timer->stop();

    for(int i=0; i<16; i++)
    {
        ImageThread * thread = new ImageThread(m_CapList.at(i), i);
        connect(thread,SIGNAL(finished()),this,SLOT(deleteThread()));
        connect(thread,SIGNAL(ImageProcessFinished(QImage,int)),this,SLOT(ShowImageFromThread(QImage,int)));
        thread->start();
    }
}

void Widget::deleteThread()
{
    qDebug()<<"delete thread...";
    QObject * obj = sender();
    ImageThread * thread = qobject_cast<ImageThread *>(obj);
    obj->deleteLater();
}

void Widget::ShowImage()
{
    for(int i=0; i<16; i++)
    {
        m_ImgList << cvQueryFrame(m_CapList.at(i));
        cvCvtColor(m_ImgList[i],m_ImgList[i],CV_BGR2RGB);
        QImage image((const uchar *)m_ImgList.at(i)->imageData,m_ImgList.at(i)->width,m_ImgList.at(i)->height,QImage::Format_RGB888);
        pixmap = QPixmap::fromImage(image);
        m_LabelList.at(i)->setPixmap(pixmap);
    }
}

void Widget::ShowImageFromThread(QImage image, int num)
{
    //qDebug()<<"ShowImageFormThread";
    m_LabelList.at(num)->setPixmap(QPixmap::fromImage(image));
}

void Widget::OpenCamera()
{
    CvCapture * cap = cvCreateCameraCapture(0);
    for(int i=0; i<16; i++)
        m_CapList<<cap;
}
