TEMPLATE = app

QT += qml quick xmlpatterns
CONFIG += c++11

SOURCES += main.cpp \
    qml2ctranslator.cpp \
    xmlmodule.cpp \
    listview.cpp \
    xmlasutpdata.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    qml2ctranslator.h \
    xmlmodule.h \
    listview.h \
    xmlasutpdata.h
