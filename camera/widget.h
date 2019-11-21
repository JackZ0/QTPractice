#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QList>
#include <QLabel>
#include <QPixmap>
#include "ImageThread.h"

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

    CvCapture * cap;
    QList<CvCapture *> m_CapList;
    QList<IplImage *> m_ImgList;
    QList<QLabel *> m_LabelList;

    IplImage * img;
    QPixmap pixmap;
};

#endif // WIDGET_H
