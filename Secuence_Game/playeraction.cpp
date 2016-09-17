#include "playeraction.h"

PlayerAction::PlayerAction(Naipe *playedCard, Naipe *recievedCard, Jugador *player, int posX, int posY)
{
    if (playedCard != NULL)
        this->playedCard = playedCard;
    else
        qDebug() << "PlayerAction: PlayedCard == NULL";
    this->removedCard = NULL;
    if (player != NULL)
        this->player = player;
    else
        qDebug () << "PlayerAction: el jugador es null";
    if (recievedCard != NULL)
        this->deckPulledCard = recievedCard;
    else
        qDebug() << "DeckPulledCard == NULL";
    this->posX = posX;
    this->posY = posY;
    this->setNext(NULL);    
}

PlayerAction::PlayerAction(Naipe *playedCard, Naipe *recievedCard, CardImage *removedCard, QString removedCardOwner, Jugador *player, int posX, int posY)
{
    if (playedCard != NULL)
        this->playedCard = playedCard;
    else
        qDebug() << "PlayerAction: PlayedCard == NULL";
    if (playedCard != NULL)
        this->removedCard = removedCard;
    else
        qDebug() << "PlayerAction: removedCard == NULL";
    if (player != NULL)
        this->player = player;
    else
        qDebug () << "PlayerAction: el jugador es null";
    if (recievedCard != NULL)
        this->deckPulledCard = recievedCard;
    else
        qDebug() << "DeckPulledCard == NULL";
    if (removedCardOwner != NULL)
        this->removedCardOwner = removedCardOwner;
    else
        qDebug() << "removedCardOwner == NULL";
    this->posX = posX;
    this->posY = posY;
    this->setNext(NULL);
    qDebug() << "el segundo constructor se llama";
}

PlayerAction::PlayerAction()
{
    this->playedCard = NULL;
    this->player = NULL;
    this->posX = 0;
    this->posY = 0;
    this->setNext(NULL);
}

Naipe *PlayerAction::getPlayedCard() const
{
    return playedCard;
}

Jugador *PlayerAction::getPlayer() const
{
    return player;
}

int PlayerAction::getPosX() const
{
    return posX;
}

int PlayerAction::getPosY() const
{
    return posY;
}

PlayerAction *PlayerAction::getNext() const
{
    return nextAction;
}

void PlayerAction::setNext(PlayerAction *value)
{
    nextAction = value;
}

Naipe *PlayerAction::getDeckPulledCard() const
{
    return deckPulledCard;
}

QString PlayerAction::getRemovedCardOwner() const
{
    return removedCardOwner;
}

CardImage *PlayerAction::getRemovedCard() const
{
    return removedCard;
}
