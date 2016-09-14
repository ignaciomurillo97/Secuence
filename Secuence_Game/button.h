#ifndef BUTTON_H
#define BUTTON_H

#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

class Button : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button(QString Url, int posX, int posY, float scale, float rotation);
/*
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
*/
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


signals:
    void clicked();

};

#endif // BUTTON_H
