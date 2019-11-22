#include "widget.h"
#include "ui_widget.h"



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
        cv::cvtColor(m_CapList[i],m_ImgList[i],cv::COLOR_BGR2RGB);
        QImage image(m_ImgList[i].data,m_ImgList[i].cols,m_ImgList[i].rows,QImage::Format_RGB888);
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
    cv::VideoCapture capture;
    capture.open(0,cv::CAP_ANY);
    cv::Mat frame;
    capture >> frame;
    for(int i=0; i<16; i++)
        m_CapList<<frame;
}
