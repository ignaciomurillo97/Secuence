#ifndef IMAGENCARTA_H
#define IMAGENCARTA_H


#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QMouseEvent>

class ImagenCarta : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ImagenCarta(int valor, QString palo, QString Url, int posX, int posY);

    int getValor() const;
    QString getPalo() const;
    void setScale (float scale) ;

protected:
    int valor;
    bool placed;
    QString palo;
};


#endif // IMAGENCARTA_H
