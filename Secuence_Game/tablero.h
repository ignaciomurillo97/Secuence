#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsPixmapItem>

#include "naipe.h"

class Tablero
{
public:
    Tablero();
private:
    Naipe ** cardMatrix;
    const int width = 10;
    const int height = 10;

};

#endif // TABLERO_H
