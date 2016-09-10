#include "imagencarta.h"

#include "controll.h"
extern Controll* game;

ImagenCarta::ImagenCarta(int valor, QString palo, QString Url, int posX, int posY)
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

ImagenCarta::ImagenCarta(int valor, QString palo, QString Url)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;
    this->placed = true;
    this->Url = Url;

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

QString ImagenCarta::getUrl()
{
    return Url;
}

void ImagenCarta::setScale(float scale)
{
    setPixmap(this->pixmap().scaledToHeight(scale));
}

void ImagenCarta::setPlaced(bool value)
{
    this->placed = value;
}

void ImagenCarta::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->clickTablero(this);
    qDebug() << "click tablero !!";
}

