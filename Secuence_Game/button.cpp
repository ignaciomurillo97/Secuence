#include "button.h"

Button::Button(QString Url, int posX, int posY, float scale, float rotation)
{
    this->setPixmap(Url);
    this->setPos(posX, posY);
    this->setScale(scale);
    this->setRotation(rotation);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

