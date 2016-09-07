#ifndef IMAGENCARTA_H
#define IMAGENCARTA_H


#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QMouseEvent>
//#include <QGraphicsTextItem>

class ImagenCarta : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ImagenCarta(int valor, QString palo, QString Url, int posX, int posY);

    int getValor() const;

    QString getPalo() const;

protected:
    int valor;
    bool placed;
    QString palo;
};


#endif // IMAGENCARTA_H
