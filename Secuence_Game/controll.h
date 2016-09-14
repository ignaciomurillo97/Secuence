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
#include "button.h"
#include "tablero.h"
#include "jugador.h"
#include "deckstack.h"
#include "imagencarta.h"
#include "cardarraylist.h"
#include "playercirclelist.h"

class Controll : public QGraphicsView
{        
    Q_OBJECT
public:
    Controll();
    QGraphicsScene* getScene();

    void pickupCard (Naipe * naipe);
    void clickTablero(CardImage * cartaSeleccionada);
    void placeCard (Naipe * newCard);
    void returnCardToHand ();
    void fillDeck(DeckStack * deck);    
    void removeDiscardPile();
    void showTopDiscardPile(Naipe * cartaAMostrar);
    void startGame();
    bool checkWin();
    void showHand(Jugador* player);

    void mouseMoveEvent(QMouseEvent *event);


public slots:
    void setTwoPlayers();
    void setThreePlayers();
    void setFourPlayers();
    void choosePlayerScreen();

private:
    QGraphicsScene * scene;

    int playerCount;
    playerCircleList* playerList;
    int maxCardsPerPlayer;

    Naipe * draggingItem;
    int draggingItemPosX;
    int draggingItemPosY;

    Tablero * gameBoard;

    DeckStack * deck;
    DeckStack * discardPile;
    Naipe * topDiscardPile;
    CardArrayList * mano;
};

#endif // CONTROLL_H
