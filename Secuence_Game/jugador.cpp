#include "jugador.h"
#include <QDebug>

Jugador::Jugador(QString name, int cardCount)
{
    this->name = name;
    this->hand = new CardArrayList(cardCount);
}

void Jugador::fillHand(DeckStack *deck)
{
    for (int i = 0; i < hand->getMax(); i++)
    {
        hand->append(deck->pop());
    }
}

CardArrayList *Jugador::getHand() const
{
    return hand;
}

