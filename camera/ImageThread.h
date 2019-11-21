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

    int LabelNum; //���̴߳���Ŀؼ��ı��

    int StopFlag;  //ֵΪ1ʱֹͣ

signals:
    void ImageProcessFinished(QImage image, int num);//�źţ���GUI���̴�������

};

#endif // IMAGETHREAD_H
