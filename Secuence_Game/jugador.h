#ifndef JUGADOR_H
#define JUGADOR_H
#include "cardarraylist.h"
#include "deckstack.h"

class Jugador
{
public:
    Jugador(QString nombre, int cardCount);
    //virtual ~Jugador();
    void fillHand(DeckStack* deck);
    void placeCard(Naipe* card);
    void switchDeadCard(Naipe* card);

    CardArrayList *getHand() const;

private:
    QString name;
    CardArrayList* hand;
    //IMG token


};

#endif // JUGADOR_H
