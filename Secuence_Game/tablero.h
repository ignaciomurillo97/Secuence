#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "imagencarta.h"
#include "token.h"
#include "jugador.h"

#define width 10
#define height 10
class Tablero
{
public:
    Tablero();
    CardImage* getValue(int x, int y);
    Token * getToken(int x, int y);
    void setValue (int x, int y, CardImage* pNaipe);
    void fillBoard(QGraphicsScene * scene, int offsetX, int offsetY);
    void standardFill(QGraphicsScene * scene);

    void addToken (int x, int y, QString owner, QString Url);
    void addToken (int x, int y, Token* token);
    void removeTokenfromBoard (int x, int y, QString owner, QGraphicsScene *scene);

    bool checkWin(QString currPlayer, int posX, int posY, int cardAmount);
private:
    CardImage*** cardMatrix;
    Token*** tokenMatrix;
    QString* standardBoardOrder;

    int countSecuenceInDirection(int posX, int posY, int dirX, int dirY, int currRecursion, QString owner);
};

#endif // TABLERO_H
