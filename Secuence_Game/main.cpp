#include <QApplication>

#include "controll.h"

#include "undopile.h"
#include "playeraction.h"
#include "naipe.h"
#include "imagencarta.h"
#include "jugador.h"

Controll * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Controll();

    return a.exec();
}
