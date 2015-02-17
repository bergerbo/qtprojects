#-------------------------------------------------
#
# Project created by QtCreator 2015-02-03T10:53:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawing_space.cpp

HEADERS  += mainwindow.h \
    drawing_space.h \
    Transitions.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/icons.qrc
