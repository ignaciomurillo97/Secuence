#include "tablero.h"

//extern Controll * game;

Tablero::Tablero()
{
    cardMatrix = new ImagenCarta ** [width];
    for (int i = 0; i < width; i++)
    {
        cardMatrix[i] = new ImagenCarta* [height];
    }
}

ImagenCarta *Tablero::getValue(int x, int y)
{
    return cardMatrix[x][y];
}

void Tablero::setValue(int x, int y, ImagenCarta *pNaipe)
{
    cardMatrix[x][y] = pNaipe;
}

void Tablero::llenarTablero(QGraphicsScene * scene, int offsetX, int offsetY)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            ImagenCarta * cartaActual =
                    new ImagenCarta(1, "espadas", ":/Cartas/naipes/ace_of_spades.png", x * 55 + offsetX, y * 40 + offsetY);
            cartaActual->setScale(55);
            cartaActual->setRotation(90);
            setValue (x, y, cartaActual);
            scene->addItem(cartaActual);
        }
    }
}


