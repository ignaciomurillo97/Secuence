#ifndef NAIPE_H
#define NAIPE_H

#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QMouseEvent>
//#include <QGraphicsTextItem>

class Naipe : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Naipe(int valor, QString palo, QString Url, int posX, int posY);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setScale (float scale) ;

    int getValor() const;    

    QString getPalo() const;   

private:
    int valor;
    bool placed;
    QString palo;
};

#endif // NAIPE_H
