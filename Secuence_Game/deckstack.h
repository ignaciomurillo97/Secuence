#ifndef DECKSTACK_H
#define DECKSTACK_H

#include "naipe.h"

#define MAX_ELEMENTS 1024

class DeckStack
{
public:
    DeckStack(int max = MAX_ELEMEMTS);

private:
    Naipe** arrayNaipes;
    int size;
    int max;
};

#endif // DECKSTACK_H
