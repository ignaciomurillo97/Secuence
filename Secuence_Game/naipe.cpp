#include "naipe.h"

Naipe::Naipe(int valor, QString palo, QString Url)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;

    setPos(50, 50);
    setAcceptHoverEvents(true);
}

void Naipe::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setScale(60);
}

void Naipe::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setScale(50);
}

void Naipe::setScale(float scale)
{
    //this->setTransform(QTransform::fromScale(scale, scale), true);
    setPixmap(this->pixmap().scaledToHeight(scale));

}

int Naipe::getValor() const
{
    return valor;
}

void Naipe::setValor(int value)
{
    valor = value;
}

QString Naipe::getPalo() const
{
    return palo;
}

void Naipe::setPalo(const QString &value)
{
    palo = value;
}

