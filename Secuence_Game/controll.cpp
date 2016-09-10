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

    // crear la pila de naipes

    maso = new DeckStack(108); // fijar la cantidad maxima de elementos a la cantidad de naipes que hay en el juego
    llenarMaso(maso);

    // crea un naipes (PRUEBA)
    Naipe * esteNaipe = new Naipe(1, "espadas", ":/Cartas/naipes/ace_of_spades.png", 50, 50);
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
    if (draggingItem == NULL)
    {
        this->draggingItem = naipe;
        this->draggingItemPosX = naipe->pos().x();
        this->draggingItemPosY = naipe->pos().y();
    }
}

void Controll::clickTablero(ImagenCarta *cartaSeleccionada)
{
    if (draggingItem != NULL)
    {
        if (draggingItem->getUrl() == cartaSeleccionada->getUrl())
        {
            colocarCarta();
        }
        else
        {
            devolverCartaAMano();
        }
    }
}

void Controll::colocarCarta()
{
    qDebug() << "es la misma carta";
}

void Controll::devolverCartaAMano()
{
    draggingItem->setPos(draggingItemPosX, draggingItemPosY);
    draggingItem = NULL;
    qDebug() << "Nope!";
}

void Controll::llenarMaso(DeckStack * maso)
{
    for (int i = 0; i < 4; i++)
    {
        QString paloActual = "";
        switch (i)
        {
        case 0:
            paloActual = "_of_spades.png";
            break;
        case 1:
            paloActual = "_of_clubs.png";
            break;
        case 2:
            paloActual = "_of_diamonds.png";
            break;
        case 3:
            paloActual = "_of_hearts.png";
            break;
        }

        for (int j = 1; j < 14; j++)
        {          
            QString nombreCarta = ":/Cartas/naipes/";
            char numstr[2];

            if (j == 1)
                nombreCarta += "ace";
            else if (j == 11)
                nombreCarta += "jacks";
            else if (j == 12)
                nombreCarta += "queen";
            else if (j == 13)
                nombreCarta += "king";
            else
                nombreCarta += itoa(j, numstr, 10);

            nombreCarta += paloActual;
            Naipe * naipeActual = new Naipe(j, "espadas", nombreCarta);
            maso->push(naipeActual);
            //qDebug() << nombreCarta;
        }
    }
}

QGraphicsScene* Controll::getScene()
{
    return scene;
}

void Controll::mouseMoveEvent(QMouseEvent *event)
{
    if (draggingItem != NULL)
    {
        draggingItem->setPos(event->x() + 10, event->y() + 10);
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

