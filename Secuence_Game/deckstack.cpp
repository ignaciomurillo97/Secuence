#include "deckstack.h"

#include "controll.h"
extern Controll * game;

DeckStack::DeckStack(int max)
{
    arrayNaipes = new Naipe*[max];
    showingCard = -1;
    topCard = -1;
    size = 0;
}

void DeckStack::push(Naipe *naipe)
{
    arrayNaipes[size] = naipe;
    topCard = size;
    size ++;
}

Naipe *DeckStack::pop()
{
    Naipe *tmp = arrayNaipes[size - 1];
    arrayNaipes[size - 1] = NULL;
    size --;
    return tmp;
}

Naipe *DeckStack::topValue()
{
    return arrayNaipes[topCard];
}

int DeckStack::getSize() const
{
    return size;
}

