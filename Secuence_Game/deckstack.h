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

private:
    Naipe** arrayNaipes;
    int size;
    int max;
};

#endif // DECKSTACK_H
