#include "ImageThread.h"
#include<QImage>
#include<QPixmap>

#include "MatToQImage.h"


ImageThread::ImageThread(cv::Mat  capture,int num):QThread()
{
    cap >> capture;
    LabelNum = num;

    StopFlag = 0;
}

void ImageThread::run()
{
    qDebug()<<"in Image Thread "<<LabelNum;

    while(StopFlag == 0)
    {

        emit ImageProcessFinished(frame, LabelNum);
        msleep(300);

    }
}
