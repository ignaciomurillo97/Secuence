#ifndef IMAGENCARTA_H
#define IMAGENCARTA_H



#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QTransform>
#include <QBrush>



class CardImage : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CardImage(QString Url, int posX, int posY, int scale, float rotation);
    CardImage(QString Url, int posX, int posY);
    CardImage(QString Url);

    int getValor() const;
    QString getPalo() const;
    QString getUrl();
    void setScale (float scale);
    void setPlaced (bool value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected:
    int valor;
    bool placed;
    QString palo;
    QString Url;
};


#endif // IMAGENCARTA_H
