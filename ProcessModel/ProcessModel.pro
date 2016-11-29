#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T16:06:15
#
#-------------------------------------------------

#QT       -= core gui
QT -= gui

TARGET = ProcessModel
TEMPLATE = lib
DESTDIR = ../bin

DEFINES += PROCESSMODEL_LIBRARY

SOURCES += processmodel.cpp \
    node.cpp \
    pressurereservoir.cpp \
    fan.cpp \
    connector.cpp \
    Block.cpp

HEADERS += processmodel.h\
        processmodel_global.h \
    node.h \
    pressurereservoir.h \
    fan.h \
    connector.h \
    Block.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
