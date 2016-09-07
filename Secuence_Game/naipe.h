#ifndef NAIPE_H
#define NAIPE_H

#include "imagencarta.h"

#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QMouseEvent>
//#include <QGraphicsTextItem>

class Naipe : public ImagenCarta
{
    Q_OBJECT
public:
    Naipe(int valor, QString palo, QString Url, int posX, int posY);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setScale (float scale) ;


private:

};

#endif // NAIPE_H
