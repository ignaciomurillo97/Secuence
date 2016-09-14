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

    void push (Naipe * naipe);
    Naipe * pop ();
    Naipe * topValue();

    int getSize() const;
    int getPosX() const;
    int getPosY() const;

    void setPos(int x, int y);
    void shuffle();    

private:
    Naipe** cardArray;

    int size;
    int topCard;
    int showingCard;

    int posX;
    int posY;
    int max;
};

#endif // DECKSTACK_H
