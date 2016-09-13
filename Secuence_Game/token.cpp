#include "token.h"

Token::Token(QString Url, int posX, int posY, QString owner)
{
    setPixmap(Url);

    setPos(posX, posY);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);

}

int Token::getPosX() const
{
    return posX;
}

int Token::getPosY() const
{
    return posY;
}

QString Token::getOwner() const
{
    return owner;
}

void Token::setOwner(const QString &value)
{
    owner = value;
}

