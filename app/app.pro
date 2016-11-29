#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T18:03:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

DESTDIR = ../bin

DEPENDPATH += ../ProcessModel
DEPENDPATH += ../ProcessModelViewer

INCLUDEPATH += ../ProcessModel
INCLUDEPATH += ../ProcessModelViewer

LIBS += -L../bin -lProcessModel
LIBS += -L../bin -lProcessModelViewer

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
