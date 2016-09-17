#ifndef PLAYERACTION_H
#define PLAYERACTION_H

#include "naipe.h"
#include "jugador.h"
#include "tablero.h"

class PlayerAction
{
public:
    PlayerAction(Naipe * playedCard, Naipe *recievedCard, Jugador * player, int posX, int posY);
    PlayerAction(Naipe *playedCard, Naipe *recievedCard, CardImage *removedCard,QString removedCardOwner, Jugador *player, int posX, int posY);
    PlayerAction();
    // virtual ~PlayerAction();
    Naipe *getPlayedCard() const;
    CardImage *getRemovedCard() const;
    Jugador *getPlayer() const;
    int getPosX() const;
    int getPosY() const;

    PlayerAction *getNext() const;
    void setNext(PlayerAction *value);

    Naipe *getDeckPulledCard() const;
    QString getRemovedCardOwner() const;

private:
    PlayerAction * nextAction;
    CardImage * removedCard;
    Naipe * playedCard;
    Naipe * deckPulledCard;
    QString removedCardOwner;
    Jugador * player;
    int posX;
    int posY;
};

#endif // PLAYERACTION_H
