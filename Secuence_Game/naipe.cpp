#include "naipe.h"
#include "controll.h"
extern Controll* game;

Naipe::Naipe(int valor, QString palo, QString Url)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;
    this->placed = true;

    setPos(50, 50);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
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

void Naipe::setScale(float scale)
{
    setPixmap(this->pixmap().scaledToHeight(scale));
}

int Naipe::getValor() const
{
    return valor;
}


QString Naipe::getPalo() const
{
    return palo;
}


