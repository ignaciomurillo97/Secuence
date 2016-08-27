#ifndef CONTROLL_H
#define CONTROLL_H

#include <QGraphicsScene>
#include <QGraphicsView>

class Controll : public QGraphicsView
{
public:
    Controll();
private:
    QGraphicsScene * scene;
};

#endif // CONTROLL_H
