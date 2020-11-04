#-------------------------------------------------
#
# Project created by QtCreator 2019-10-04T18:07:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandelbrot_3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintscene.cpp \
    rect.cpp \
    pict.cpp

HEADERS  += mainwindow.h \
    paintscene.h \
    rect.h \
    pict.h

FORMS    += mainwindow.ui
