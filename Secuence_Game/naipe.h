#ifndef NAIPE_H
#define NAIPE_H

#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsPixmapItem>
//#include <QGraphicsTextItem>

class Naipe : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Naipe(int valor, QString palo, QString Url);

    int getValor() const;
    void setValor(int value);

    QString getPalo() const;
    void setPalo(const QString &value);

private:
    int valor;
    QString palo;
};

#endif // NAIPE_H
