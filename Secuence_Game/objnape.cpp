#include "objnape.h"

objNape::objNape(int valor, QString palo, QString Url, int posX, int posY)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;
    //this->placed = true;

    setPos(posX, posY);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
}
