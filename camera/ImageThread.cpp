#include "ImageThread.h"
#include<QImage>
#include<QPixmap>

#include "MatToQImage.h"


ImageThread::ImageThread(CvCapture * capture,int num):QThread()
{
    cap = capture;
    LabelNum = num;

    StopFlag = 0;
}

void ImageThread::run()
{
    qDebug()<<"in Image Thread "<<LabelNum;

    while(StopFlag == 0)
    {
        img = cvQueryFrame(cap);
        currentFrame = Mat(img);
        //cvCvtColor(img,img,CV_BGR2RGB);
        //QImage image((const uchar *)img->imageData,img->width,img->height,QImage::Format_RGB888);
        //QPixmap pixmap = QPixmap::fromImage(image);

        frame = MatToQImage(currentFrame);
        emit ImageProcessFinished(frame, LabelNum);
        msleep(300);

    }
}
