#ifndef DECKSTACK_H
#define DECKSTACK_H

#include <QObject>

#include "naipe.h"

#define MAX_ELEMENTS 54

class DeckStack : public QObject
{
    Q_OBJECT
public:
    DeckStack(int max = MAX_ELEMENTS);

    void push (Card * naipe);
    Card * pop ();
    Card * topValue();

    int getSize() const;
    int getPosX() const;
    int getPosY() const;

    void setPos(int x, int y);
    void shuffle();    

private:
    Card** cardArray;

    int size;
    int topCard;
    int showingCard;

    int posX;
    int posY;
    int max;
};

#endif // DECKSTACK_H
