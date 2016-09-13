#include "imagencarta.h"

#include "controll.h"
extern Controll* game;

CardImage::CardImage(QString Url, int posX, int posY, int scale, float rotation)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;
    this->placed = true;
    this->Url = Url;

    this->setScale(scale);
    this->setRotation(rotation);

    setPos(posX, posY);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

CardImage::CardImage(QString Url, int posX, int posY)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;
    this->placed = true;
    this->Url = Url;

    setPos(posX, posY);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

CardImage::CardImage(QString Url)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;
    this->placed = true;
    this->Url = Url;

    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

int CardImage::getValor() const
{
    return valor;
}


QString CardImage::getPalo() const
{
    return palo;
}

QString CardImage::getUrl()
{
    return Url;
}

void CardImage::setScale(float scale)
{
    setPixmap(this->pixmap().scaledToHeight(scale));
}

void CardImage::setPlaced(bool value)
{
    this->placed = value;
}

void CardImage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->clickTablero(this);
    qDebug() << "click tablero !!";
}

