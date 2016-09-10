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

    void pickupCard (Naipe * naipe);
    void clickTablero(ImagenCarta * cartaSeleccionada);
    void colocarCarta ();
    void devolverCartaAMano ();
    void llenarMaso(DeckStack * maso);

    void mouseMoveEvent(QMouseEvent *event);   
private:
    QGraphicsScene * scene;
    Naipe * draggingItem;
    int draggingItemPosX;
    int draggingItemPosY;
    Tablero * tableroJuego;
    DeckStack * maso;
};

#endif // CONTROLL_H
