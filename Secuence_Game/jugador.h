#ifndef JUGADOR_H
#define JUGADOR_H
#include "cardarraylist.h"

class Jugador
{
public:
    Jugador();
    virtual ~Jugador();
    void placeCard(Naipe* card);
    void switchDeadCard(Naipe* card);

private:
    QString name;
    CardArrayList** hand;
    //IMG token


};

#endif // JUGADOR_H
