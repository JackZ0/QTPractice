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

INCLUDEPATH += F:\Qtpractice\double_camera\OpenCV\include
               F:\Qtpractice\double_camera\OpenCV\include\opencv2


LIBS += F:\Qtpractice\double_camera\OpenCV\lib\libopencv_*.a
