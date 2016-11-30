#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T16:06:15
#
#-------------------------------------------------

QT -= gui

TARGET = ProcessModel
TEMPLATE = lib
DESTDIR = ../../lib

DEFINES += PROCESSMODEL_LIBRARY

SOURCES += \
    Block.cpp \
    Node.cpp \
    Fan.cpp \
    ProcessModel.cpp \
    PressureReservoir.cpp \
    Connector.cpp \
    Solver.cpp

HEADERS +=\
        processmodel_global.h \
    Block.h \
    Node.h \
    Fan.h \
    PressureReservoir.h \
    ProcessModel.h \
    Connector.h \
    Solver.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
