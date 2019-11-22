#-------------------------------------------------
#
# Project created by QtCreator 2013-03-31T11:44:46
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadTest2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ImageThread.cpp \
    MatToQImage.cpp

HEADERS  += widget.h \
    ImageThread.h \
    MatToQImage.h

FORMS    += widget.ui

INCLUDEPATH += $$PWD/OpenCV/include \
               $$PWD/OpenCV/include/opencv2

LIBS += -L$$PWD/OpenCV/bin -llibopencv_highgui410 \
        -L$$PWD/OpenCV/bin -llibopencv_core410 \
        -L$$PWD/OpenCV/bin -llibopencv_imgproc410 \
        -L$$PWD/OpenCV/bin -llibopencv_imgcodecs410 \
        -L$$PWD/OpenCV/bin -llibopencv_videoio410 \
        -L$$PWD/OpenCV/bin -llibopencv_core410 \
