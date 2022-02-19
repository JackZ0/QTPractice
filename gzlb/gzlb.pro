QT       += core gui xml sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algorithm/factorial.cpp \
    Algorithm/fibonacci.cpp \
    Tcp/clenthandler.cpp \
    Tcp/serverhandler.cpp \
    Tcp/widget.cpp \
    cJson/cJSON.c \
    cJson/cJSON_Utils.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    xml/xml.cpp

HEADERS += \
    Algorithm/factorial.h \
    Algorithm/fibonacci.h \
    Tcp/widget.h \
    cJson/cJSON.h \
    cJson/cJSON_Utils.h \
    mainwindow.h \
    qcustomplot.h \
    xml/xml.h

FORMS += \
    Tcp/widget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
