#include "imagencarta.h"

ImagenCarta::ImagenCarta(int valor, QString palo, QString Url, int posX, int posY)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;
    this->placed = true;

    setPos(posX, posY);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

int ImagenCarta::getValor() const
{
    return valor;
}


QString ImagenCarta::getPalo() const
{
    return palo;
}

void ImagenCarta::setScale(float scale)
{
    setPixmap(this->pixmap().scaledToHeight(scale));
}

