#ifndef IMAGENCARTA_H
#define IMAGENCARTA_H



#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QTransform>
#include <QBrush>



class ImagenCarta : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ImagenCarta(int valor, QString palo, QString Url, int posX, int posY);
    ImagenCarta(int valor, QString palo, QString Url);

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
