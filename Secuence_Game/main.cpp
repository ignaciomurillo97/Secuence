#include <QApplication>

#include "controll.h"

#include "tablero.h"

Controll * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tablero * miTablero = new Tablero();

    game = new Controll();

    return a.exec();
}
