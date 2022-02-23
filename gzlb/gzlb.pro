QT       += core gui xml sql network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algorithm/factorial.cpp \
    Algorithm/fibonacci.cpp \
    Speedo/speedo.cpp \
    Tcp/clenthandler.cpp \
    Tcp/serverhandler.cpp \
    Tcp/widget.cpp \
    cJson/cJSON.c \
    cJson/cJSON_Utils.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    serialport/console.cpp \
    serialport/serialmainwindow.cpp \
    serialport/settingsdialog.cpp \
    xml/xml.cpp

HEADERS += \
    Algorithm/factorial.h \
    Algorithm/fibonacci.h \
    Speedo/speedo.h \
    Tcp/widget.h \
    cJson/cJSON.h \
    cJson/cJSON_Utils.h \
    mainwindow.h \
    qcustomplot.h \
    serialport/console.h \
    serialport/serialmainwindow.h \
    serialport/settingsdialog.h \
    xml/xml.h

FORMS += \
    Speedo/speedo.ui \
    Tcp/widget.ui \
    mainwindow.ui \
    serialport/serialmainwindow.ui \
    serialport/settingsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    serialport/terminal.qrc \
    serialport/terminal.qrc

DISTFILES += \
    serialport/images/application-exit.png \
    serialport/images/clear.png \
    serialport/images/connect.png \
    serialport/images/disconnect.png \
    serialport/images/settings.png
