#ifndef PLAYERCIRCLELIST_H
#define PLAYERCIRCLELIST_H
#include "cardarraylist.h"
#include "jugador.h"


class playerCircleList : public CardArrayList
{
public:
    playerCircleList(int pmax);
    void append(Jugador* player);
    void next();
    void previous();
    Jugador* remove();
    Jugador* getValue();
    Jugador* getValue(int x);
    void setValue(int x, Jugador* value);
    virtual ~playerCircleList();



private:
    Jugador** elements;
};

#endif // PLAYERCIRCLELIST_H
