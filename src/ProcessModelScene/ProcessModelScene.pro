#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T19:25:25
#
#-------------------------------------------------

QT += core gui widgets

TARGET = ProcessModelScene
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = ../../lib

INCLUDEPATH += \
    ../ProcessModel \
    ../app

LIBS += -L../../lib -lProcessModel

SOURCES += \
    BlockGraphicsItem.cpp \
    ConnectorGraphicsPathItem.cpp \
    NodeGraphicsItem.cpp \
    ProcessModelScene.cpp

HEADERS += \
    BlockGraphicsItem.h \
    ConnectorGraphicsPathItem.h \
    NodeGraphicsItem.h \
    ProcessModelScene.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
