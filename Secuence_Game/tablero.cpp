#include "tablero.h"


Tablero::Tablero()
{
    cardMatrix = new CardImage ** [width];
    for (int i = 0; i < width; i++)
    {
        cardMatrix[i] = new CardImage* [height];
    }

    tokenMatrix = new Token ** [width];
    for (int i = 0; i < width; i++)
    {
        tokenMatrix[i] = new Token* [height];
    }
}

CardImage *Tablero::getValue(int x, int y)
{
    return cardMatrix[x][y];
}

void Tablero::setValue(int x, int y, CardImage *pNaipe)
{
    cardMatrix[x][y] = pNaipe;
}

void Tablero::fillBoard(QGraphicsScene * scene, int offsetX, int offsetY)
{

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            CardImage * cartaActual =
                    new CardImage(":/Cartas/naipes/ace_of_spades.png", x * 55 + offsetX, y * 40 + offsetY, 55, 90);
            setValue (x, y, cartaActual);
            scene->addItem(cartaActual);
        }
    }
}

void Tablero::addToken(int x, int y, QString owner, QString Url)
{
    tokenMatrix[x][y] = new Token(Url, x, y, owner);
}


