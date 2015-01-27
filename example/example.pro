QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui



# Link against qmacsystemtrayicon
INCLUDEPATH += ../qmacsystemtrayiconimpl
LIBS += -L../qmacsystemtrayiconimpl -lqmacsystemtrayiconimpl
include(../qmacsystemtrayiconimpl/qmacsystemtrayiconimpl.pri)

RESOURCES += \
    resources.qrc
