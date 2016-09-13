#include "naipe.h"
#include "controll.h"
extern Controll* game;

Card::Card(QString Url, int posX, int posY)
 : CardImage(Url, posX, posY)
{}

Card::Card(QString Url)
 : CardImage(Url)
{}

void Card::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setScale(60);   
}

void Card::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setScale(50);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
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




