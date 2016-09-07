#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsPixmapItem>
#include "imagencarta.h"
#include "controll.h"

#define width 10
#define height 10
class Tablero
{
public:
    Tablero();
    ImagenCarta* getValue(int x, int y);
    void setValue (int x, int y, ImagenCarta* pNaipe);
    void llenarTablero();

private:
    ImagenCarta** cardMatrix;
};

#endif // TABLERO_H
