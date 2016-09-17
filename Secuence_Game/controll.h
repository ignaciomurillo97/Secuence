#ifndef CONTROLL_H
#define CONTROLL_H

// clases de Qt
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>


// clases del juego
#include "playeraction.h"
#include "naipe.h"
#include "button.h"
#include "tablero.h"
#include "jugador.h"
#include "undopile.h"
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
    void placeCardOnDiscardPile (Naipe * newCard);
    void returnCardToHand ();
    void fillDeck(DeckStack * deck);    
    void removeDiscardPile();
    void showTopDiscardPile(Naipe * cartaAMostrar);
    void startGame();
    void removeCardFromHand(Naipe * selectedCard);
    void placeCard(CardImage *selectedCard);
    void placeCard(CardImage *selectedCard, QString owner);
    void removeToken(CardImage *selectedCard);
    void checkWin(CardImage * selectedCard);
    void showHand(Jugador* player);
    void removeHand(Jugador*  player);    
    void showCurrPlayerName();
    void showWinScreen();
    void mouseMoveEvent(QMouseEvent *event);


public slots:
    void setTwoPlayers();
    void setThreePlayers();
    void setFourPlayers();
    void choosePlayerScreen();
    void nextPlayer();
    void previousPlayer();
    void undoLastAction ();
    void redoLastAction ();

private:
    QGraphicsScene * scene;

    int playerCount;
    playerCircleList* playerList;
    Jugador* currPlayer;
    QGraphicsTextItem * currPlayerNameItem;
    int maxCardsPerPlayer;

    Naipe * draggingItem;
    int draggingItemPosX;
    int draggingItemPosY;

    Tablero * gameBoard;

    DeckStack * deck;
    DeckStack * discardPile;
    Naipe * topDiscardPile;
    CardArrayList * mano;

    UndoPile * undoPile;
    UndoPile * redoPile;
};

#endif // CONTROLL_H
