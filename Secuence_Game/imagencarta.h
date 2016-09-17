#ifndef IMAGENCARTA_H
#define IMAGENCARTA_H



#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QTransform>
#include <QBrush>

#define stdCardSize 80
#define largeCardSize 100

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
    void setIndice(int x, int y);

    int getIndiceX() const;
    int getIndiceY() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);    

    int getPosX() const;
    int getPosY() const;

protected:
    int valor;
    bool placed;
    QString palo;    
    QString Url;

    int indiceX;
    int indiceY;

    int posX;
    int posY;
};


#endif // IMAGENCARTA_H
