#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "imagencarta.h"

#define width 10
#define height 10
class Tablero
{
public:
    Tablero();
    ImagenCarta* getValue(int x, int y);
    void setValue (int x, int y, ImagenCarta* pNaipe);
    void llenarTablero(QGraphicsScene * scene, int offsetX, int offsetY);

private:
    ImagenCarta*** cardMatrix;
};

#endif // TABLERO_H
