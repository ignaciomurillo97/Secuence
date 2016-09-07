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

class Controll : public QGraphicsView
{
public:
    Controll();

    void pickupCard (Naipe * naipe);
    //void mousePressEvent(QMouseEvent * event);

    void mouseMoveEvent(QMouseEvent *event);
private:
    QGraphicsScene * scene;
    Naipe * draggingItem;
};

#endif // CONTROLL_H
