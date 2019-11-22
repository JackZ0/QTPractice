#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QList>
#include <QLabel>
#include <QPixmap>
#include "ImageThread.h"
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
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/cvconfig.h>

//using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_pushButton_clicked();

    void deleteThread();

    void ShowImage();
    void ShowImageFromThread(QImage image, int num);

    void OpenCamera();

private:
    Ui::Widget *ui;

    QTimer * timer;

    cv::VideoCapture cap;
    QList<cv::Mat > m_CapList;
    QList<cv::Mat > m_ImgList;
    QList<QLabel *> m_LabelList;

    IplImage * img;
    QPixmap pixmap;
};

#endif // WIDGET_H
