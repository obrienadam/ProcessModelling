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
LIBS += -larmadillo

SOURCES += \
    Block.cpp \
    Node.cpp \
    Fan.cpp \
    PressureReservoir.cpp \
    Connector.cpp \
    Solver.cpp \
    Equation.cpp \
    Matrix.cpp \
    TJunction.cpp

HEADERS +=\
        processmodel_global.h \
    Block.h \
    Node.h \
    Fan.h \
    PressureReservoir.h \
    Connector.h \
    Solver.h \
    Equation.h \
    Matrix.h \
    TJunction.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
