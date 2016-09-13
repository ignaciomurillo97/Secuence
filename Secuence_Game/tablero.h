#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "imagencarta.h"
#include "token.h"

#define width 10
#define height 10
class Tablero
{
public:
    Tablero();
    CardImage* getValue(int x, int y);
    void setValue (int x, int y, CardImage* pNaipe);
    void fillBoard(QGraphicsScene * scene, int offsetX, int offsetY);

    void addToken (int x, int y, QString owner, QString Url);
    void removeToken (int x, int y);
private:
    CardImage*** cardMatrix;
    Token*** tokenMatrix;
};

#endif // TABLERO_H
