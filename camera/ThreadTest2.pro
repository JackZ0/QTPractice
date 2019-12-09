#-------------------------------------------------
#
# Project created by QtCreator 2013-03-31T11:44:46
#
#-------------------------------------------------

QT       += core

TARGET = ThreadTest2
TEMPLATE = app


SOURCES += widget.cpp

INCLUDEPATH += $$PWD/OpenCV/include \
               $$PWD/OpenCV/include/opencv2

LIBS += -L$$PWD/OpenCV/bin -llibopencv_highgui410 \
        -L$$PWD/OpenCV/bin -llibopencv_core410 \
        -L$$PWD/OpenCV/bin -llibopencv_imgproc410 \
        -L$$PWD/OpenCV/bin -llibopencv_imgcodecs410 \
        -L$$PWD/OpenCV/bin -llibopencv_videoio410 \
        -L$$PWD/OpenCV/bin -llibopencv_core410 \
        -L$$PWD/OpenCV/bin -llibopencv_objdetect410 \
        -L$$PWD/OpenCV/bin -lopencv_ffmpeg410 \
        -L$$PWD/OpenCV/bin -llibopencv_core410 \
        -L$$PWD/OpenCV/bin -llibopencv_imgproc410 \
        -L$$PWD/OpenCV/bin -llibopencv_imgcodecs410 \
        -L$$PWD/OpenCV/bin -llibopencv_videoio410 \
        -L$$PWD/OpenCV/bin -llibopencv_core410 \
        -L$$PWD/OpenCV/bin -llibopencv_objdetect410 \
        -L$$PWD/OpenCV/bin -lopencv_ffmpeg410 \
        -L$$PWD/OpenCV/bin -llibopencv_objdetect410 \


