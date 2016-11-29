TEMPLATE = subdirs

SUBDIRS += \
    src/ProcessModel \
    src/ProcessModelViewer \
    src/app

app.depends = ProcessModel ProcessModelViewer

CONFIG += ordered
