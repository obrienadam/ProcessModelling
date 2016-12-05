TEMPLATE = subdirs

SUBDIRS += \
    src/ProcessModel \
    src/ProcessModelScene \
    src/app

app.depends = ProcessModel ProcessModelScene

CONFIG += ordered
