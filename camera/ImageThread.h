#ifndef IMAGETHREAD_H
#define IMAGETHREAD_H

#include<QThread>
#include<QImage>
#include<QTimer>

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
#include<QDebug>

using namespace cv;

class ImageThread : public QThread
{
    Q_OBJECT

public:
    ImageThread(CvCapture * capture, int num);

private:
    void run();
    CvCapture * cap;
    IplImage * img;
    Mat currentFrame;
    QImage frame;

    int LabelNum; //此线程处理的控件的编号

    int StopFlag;  //值为1时停止

signals:
    void ImageProcessFinished(QImage image, int num);//信号，给GUI进程传送数据

};

#endif // IMAGETHREAD_H
