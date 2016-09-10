#-------------------------------------------------
#
# Project created by QtCreator 2016-08-27T14:18:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Secuence_Game
TEMPLATE = app


SOURCES += main.cpp \
    controll.cpp \
    naipe.cpp \
    tablero.cpp \
    deckstack.cpp \
    imagencarta.cpp

HEADERS  += \
    controll.h \
    naipe.h \
    tablero.h \
    deckstack.h \
    imagencarta.h

FORMS    +=

RESOURCES += \
    res.qrc
