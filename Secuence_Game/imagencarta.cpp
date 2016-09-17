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

    this->posX = posX;
    this->posY = posY;

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

    this->posX = posX;
    this->posY = posY;

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
    setPixmap(this->pixmap().scaled(scale * 0.6, scale, Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void CardImage::setPlaced(bool value)
{
    this->placed = value;
}

void CardImage::setIndice(int x, int y)
{
    this->indiceX = x;
    this->indiceY = y;
}

void CardImage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->clickTablero(this);    
}

int CardImage::getPosX() const
{
    return posX;
}

int CardImage::getPosY() const
{
    return posY;
}

int CardImage::getIndiceX() const
{
    return indiceX;
}

int CardImage::getIndiceY() const
{
    return indiceY;
}

