#ifndef NAIPE_H
#define NAIPE_H

#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
//#include <QGraphicsTextItem>

class Naipe : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Naipe(int valor, QString palo, QString Url);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void setScale (float scale) ;

    int getValor() const;
    void setValor(int value);

    QString getPalo() const;
    void setPalo(const QString &value);

private:
    int valor;
    QString palo;
};

#endif // NAIPE_H
