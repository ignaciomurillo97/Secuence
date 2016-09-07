#include <QApplication>

#include "controll.h"

Controll * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Controll();

    return a.exec();
}
