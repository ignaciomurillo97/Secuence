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
#include "imagencarta.h"

class Controll : public QGraphicsView
{
public:
    Controll();

    void pickupCard (Naipe * naipe);
    QGraphicsScene* getScene();

    void mouseMoveEvent(QMouseEvent *event);
private:
    QGraphicsScene * scene;
    Naipe * draggingItem;
    Tablero * tableroJuego;
};

#endif // CONTROLL_H
