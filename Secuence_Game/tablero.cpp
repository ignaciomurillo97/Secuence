#include "tablero.h"

extern Controll * game;

Tablero::Tablero()
{
    cardMatrix = new ImagenCarta * [width * height];
}

ImagenCarta *Tablero::getValue(int x, int y)
{
    return cardMatrix[y * width + x];
}

void Tablero::setValue(int x, int y, ImagenCarta *pNaipe)
{
    cardMatrix[y * width + x] = pNaipe;
}

void Tablero::llenarTablero()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            setValue (x, y, new ImagenCarta(1, "espadas", ":/Cartas/naipes/ace_of_spades.png", x * 50, y * 50));
        }
    }
}
