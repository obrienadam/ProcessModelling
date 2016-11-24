#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T16:06:15
#
#-------------------------------------------------

#QT       -= core gui
QT -= gui

TARGET = ProcessModel
TEMPLATE = lib

DEFINES += PROCESSMODEL_LIBRARY

SOURCES += processmodel.cpp \
    node.cpp \
    sink.cpp \
    pressurereservoir.cpp \
    component.cpp \
    fan.cpp \
    connector.cpp

HEADERS += processmodel.h\
        processmodel_global.h \
    node.h \
    sink.h \
    pressurereservoir.h \
    component.h \
    fan.h \
    connector.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
