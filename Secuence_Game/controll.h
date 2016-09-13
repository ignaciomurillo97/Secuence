#ifndef CONTROLL_H
#define CONTROLL_H

// clases de Qt
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>


// clases del juego
#include "naipe.h"
#include "tablero.h"
#include "deckstack.h"
#include "imagencarta.h"

class Controll : public QGraphicsView
{
public:
    Controll();
    QGraphicsScene* getScene();

    void pickupCard (Card * naipe);
    void clickTablero(CardImage * cartaSeleccionada);
    void placeCard (Card * newCard);
    void returnCardToHand ();
    void fillDeck(DeckStack * deck);    
    void removeDiscardPile();
    void showTopDiscardPile(Card * cartaAMostrar);

    void mouseMoveEvent(QMouseEvent *event);

private:
    QGraphicsScene * scene;
    Card * draggingItem;
    int draggingItemPosX;
    int draggingItemPosY;
    Tablero * gameBoard;
    DeckStack * deck;
    DeckStack * discardPile;
    Card * topDiscardPile;
};

#endif // CONTROLL_H
