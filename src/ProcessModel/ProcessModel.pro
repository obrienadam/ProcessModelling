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

LIBS += -L../../lib -llapack -lblas

SOURCES += \
    Block.cpp \
    Node.cpp \
    Fan.cpp \
    PressureReservoir.cpp \
    Connector.cpp \
    Solver.cpp \
    FanOptimizer.cpp \
    Equation.cpp \
    Matrix.cpp \
    Property.cpp \
    Solution.cpp \
    Tee.cpp \
    YConnector.cpp \
    Model.cpp \
    PGModel.cpp \
    Diffuser.cpp \
    Nozzle.cpp \
    Valve.cpp \
    RestrictorValve.cpp \
    MassFlowReservoir.cpp \
    Unit.cpp \
    SimpleLinearModel.cpp \
    ConstFlowFan.cpp

HEADERS +=\
        processmodel_global.h \
    Block.h \
    Node.h \
    Fan.h \
    PressureReservoir.h \
    Connector.h \
    Solver.h \
    FanOptimizer.h \
    Equation.h \
    Matrix.h \
    Property.h \
    Solution.h \
    Tee.h \
    YConnector.h \
    Model.h \
    PGModel.h \
    Diffuser.h \
    Nozzle.h \
    Valve.h \
    RestrictorValve.h \
    MassFlowReservoir.h \
    Unit.h \
    SimpleLinearModel.h \
    ConstFlowFan.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
