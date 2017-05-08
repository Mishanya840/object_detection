#-------------------------------------------------
#
# Project created by QtCreator 2016-10-12T18:17:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Counter2016
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += mainwindow.cpp \
    main.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += "C:/opencv/build/include"

LIBS += -LC:/opencv/build/bin/ \
    -lopencv_core320.dll \
    -lopencv_video320.dll\
    -lopencv_videoio320.dll\
    -lopencv_highgui320.dll\
    -lopencv_imgcodecs320.dll\
    -lopencv_imgproc320.dll\
    -lopencv_objdetect320.dll\
    -lopencv_features2d320.dll\
    -lopencv_calib3d320.dll

LIBS += -LC:/opencv/build/lib/ \
    -lopencv_core320.dll \
    -lopencv_video320.dll\
    -lopencv_videoio320.dll\
    -lopencv_highgui320.dll\
    -lopencv_imgcodecs320.dll\
    -lopencv_imgproc320.dll\
    -lopencv_objdetect320.dll\
    -lopencv_features2d320.dll\
    -lopencv_calib3d320.dll

DISTFILES += \
    image.jpg
