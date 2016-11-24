#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T18:03:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

DEPENDPATH += . ../testLib
INCLUDEPATH += ../ProcessModel
LIBS += -L../ProcessModel/debug -lProcessModel

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
