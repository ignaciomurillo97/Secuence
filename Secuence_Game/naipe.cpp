#include "naipe.h"
#include "controll.h"
extern Controll* game;

Naipe::Naipe(int valor, QString palo, QString Url, int posX, int posY)
 : ImagenCarta(valor, palo, Url, posX, posY)
{
}

void Naipe::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setScale(60);   
}

void Naipe::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setScale(50);
}

void Naipe::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   
    if (event->button() == Qt::LeftButton)
    {
        if (placed)
        {
            game->pickupCard(this);
            placed = false;
        }
    }
}




