#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T19:29:22
#
#-------------------------------------------------

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProcessModelViewer
TEMPLATE = lib
DESTDIR = ../../lib

INCLUDEPATH += ../ProcessModel
LIBS += -L../../lib -lProcessModel

DEFINES += PROCESSMODELVIEWER_LIBRARY

SOURCES += \
    ProcessModelViewer.cpp \
    BlockGraphicsObject.cpp \
    NodeGraphicsObject.cpp \
    ConnectorGraphicsPathObject.cpp

HEADERS +=\
        processmodelviewer_global.h \
    ProcessModelViewer.h \
    BlockGraphicsObject.h \
    NodeGraphicsObject.h \
    ConnectorGraphicsPathObject.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
