#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T12:05:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CloudSys_Qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    filehandler.cpp \
    global.cpp \
    iconprovider.cpp \
    iconsdisplaywidget.cpp \
    icondisplayerwidget.cpp

HEADERS  += mainwindow.h \
    login.h \
    filehandler.h \
    global.h \
    iconprovider.h \
    iconsdisplaywidget.h \
    icondisplayerwidget.h

FORMS    += mainwindow.ui \
    login.ui \
    icondisplayerwidget.ui