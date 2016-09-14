#include "naipe.h"
#include "controll.h"
extern Controll* game;

Naipe::Naipe(QString Url, int posX, int posY)
 : CardImage(Url, posX, posY)
{}

Naipe::Naipe(QString Url)
 : CardImage(Url)
{}

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




