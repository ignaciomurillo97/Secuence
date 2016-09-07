#include "deckstack.h"

DeckStack::DeckStack(int max)
{
    arrayNaipes = new Naipe*[max];
    //arrayNaipes[0] = new Naipe(10, "Espadas", "Esta", 0, 0) ;
    size = 0;
}

void DeckStack::push(Naipe *naipe)
{
    arrayNaipes[size] = naipe;
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
    return arrayNaipes[size - 1];
}

