#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T18:03:42
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app
DESTDIR = ../../bin

INCLUDEPATH += \
    ../ProcessModel \
    ../ProcessModelScene

LIBS += -L../../lib -lProcessModel -lProcessModelScene

SOURCES += main.cpp\
    BlockDialog.cpp \
    MainWindow.cpp \
    BlockPropertyDialog.cpp

HEADERS  += \
    BlockDialog.h \
    MainWindow.h \
    BlockPropertyDialog.h

FORMS    += mainwindow.ui \
    node_dialog.ui \
    blockdialog.ui \
    blockpropertydialog.ui

RESOURCES += \
    images.qrc
