#-------------------------------------------------
#
# Project created by QtCreator 2014-09-16T18:31:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleDiagram
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vidata.cpp \
    squarediagram.cpp

HEADERS  += mainwindow.h \
    vidata.h \
    squarediagram.h

FORMS    += mainwindow.ui \
    squarediagram.ui
