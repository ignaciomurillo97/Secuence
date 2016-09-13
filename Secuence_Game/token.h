#ifndef TOKEN_H
#define TOKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Token : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Token(QString Url, int posX, int posY, QString owner);

    int getPosX() const;

    int getPosY() const;

    QString getOwner() const;
    void setOwner(const QString &value);

private:
    int posX;
    int posY;
    QString owner;
};

#endif // TOKEN_H
