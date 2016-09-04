#ifndef OBJNAPE_H
#define OBJNAPE_H


#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QMouseEvent>

class objNape : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    objNape(int valor, QString palo, QString Url, int posX, int posY);
private:
    int valor;
    //bool placed;
    QString palo;
};

#endif // OBJNAPE_H
