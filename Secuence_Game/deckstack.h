#ifndef DECKSTACK_H
#define DECKSTACK_H

#include "naipe.h"

#define MAX_ELEMENTS 54

class DeckStack
{
public:
    DeckStack(int max = MAX_ELEMENTS);

    void push (Naipe * naipe);
    Naipe * pop ();
    Naipe * topValue();
    int getSize() const;

    void mostrarCartaSuperior ();
    void shuffle();

private:
    Naipe** arrayNaipes;

    int size;
    int topCard;
    int showingCard;

    const int posX = 1000;
    const int posY = 500;
    int max;
};

#endif // DECKSTACK_H
