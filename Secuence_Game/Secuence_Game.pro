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
    imagencarta.cpp \
    token.cpp \
    jugador.cpp \
    playercirclelist.cpp \
    cardarraylist.cpp \
    button.cpp \
    undopile.cpp \
    playeraction.cpp

HEADERS  += \
    controll.h \
    naipe.h \
    tablero.h \
    deckstack.h \
    imagencarta.h \
    token.h \
    jugador.h \
    playercirclelist.h \
    cardarraylist.h \
    button.h \
    undopile.h \
    playeraction.h

FORMS    +=

RESOURCES += \
    res.qrc
