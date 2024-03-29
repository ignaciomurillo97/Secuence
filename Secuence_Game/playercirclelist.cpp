#include "playercirclelist.h"

playerCircleList::playerCircleList(int pmax)
{
    elements=new Jugador*[pmax];
    size = 0;
    max = pmax;
    pos = 0;
}

playerCircleList::playerCircleList()
{

}

void playerCircleList::append(Jugador* player)
{
    elements[size]=player;
    size++;
}

void playerCircleList::next()
{
    pos = (pos + 1) % size;    
}

void playerCircleList::previous()
{
    if (pos == 0)
        pos = size - 1;
    else
        pos --;
}

Jugador* playerCircleList::remove()
{
    Jugador* deletedElement=elements[pos];
        for (int i=pos; i<size; i++){
            elements[i]=elements[i+1];
        }
        size--;
        return (deletedElement);
}

Jugador* playerCircleList::getValue()
{
    return elements[pos];
}

Jugador* playerCircleList::getValue(int x)
{
    return elements[x];
}

void playerCircleList::setValue(int x, Jugador* value)
{
    elements[x] = value;
}


playerCircleList::~playerCircleList()
{
    size=0;
    pos=0;
    delete[]elements;
}

