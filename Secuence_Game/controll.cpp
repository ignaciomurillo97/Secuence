#include "controll.h"
#include "naipe.h"

Controll::Controll()
{
    scene = new QGraphicsScene();
    setSceneRect(0, 0, 1200, 600);

    setBackgroundBrush(QBrush(QImage(":/img/Recurcion_1.png")));
    //scene->setBackgroundBrush(Qt::red);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(1200, 600);
    setScene(scene);

    Naipe * esteNaipe = new Naipe(2, "espadas", ":/Cartas/naipes/2_of_spades.png");
    scene->addItem(esteNaipe);

    this->show();
}
