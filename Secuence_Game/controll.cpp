#include "controll.h"

Controll::Controll()
{
    // crear una nueva escena
    scene = new QGraphicsScene();
    setSceneRect(0, 0, 1200, 600);

    // imagen de fondo
    setBackgroundBrush(QBrush(QImage(":/img/Fondo.png")));
    //scene->setBackgroundBrush(Qt::red);

    // quitar el scrollbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(1200, 600); // asigna el tamano del "view"
    setScene(scene); // asigna la escena

    // crear un tablero
    tableroJuego = new Tablero();
    tableroJuego->llenarTablero(scene, 100, 100);

    // crea un naipes (PRUEBA)
    Naipe * esteNaipe = new Naipe(2, "espadas", ":/Cartas/naipes/2_of_spades.png", 50, 50);
    esteNaipe->setScale(50);
    scene->addItem(esteNaipe);

    Naipe * esteOtroNaipe = new Naipe(2, "espadas", ":/Cartas/naipes/5_of_spades.png", 100, 50);
    esteOtroNaipe->setScale(50);
    scene->addItem(esteOtroNaipe);    

    // inicializa el draggableItem como vacio
    draggingItem = NULL;

    this->show(); // Muestra la escena actual
}

void Controll::pickupCard(Naipe *naipe)
{
    if (draggingItem == NULL) this->draggingItem = naipe;
    // qDebug() << "el naipe es un" << draggingItem->getValor();
}

QGraphicsScene* Controll::getScene()
{
    return scene;
}

void Controll::mouseMoveEvent(QMouseEvent *event)
{
    if (draggingItem != NULL)
    {
        draggingItem->setPos(event->x(), event->y());
    }

    QGraphicsView::mouseMoveEvent(event);
}


/*
    Mover con el mouse:
    si se hace click a una carta se seleccioneara como movible
    si se hace click en una posicion valida se coloca la carta
    si no se hace click en una posicion valida no devuelve a su posicion original
    si se hace click derecho se devuelve a donde estaba
*/


/*
TO DO!

- drag and drop
- crear un tablero

*/

