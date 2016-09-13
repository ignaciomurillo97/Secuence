#include "controll.h"

Controll::Controll()
{
    // inicializa las variables
    draggingItem = NULL;
    topDiscardPile = NULL;

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
    gameBoard = new Tablero();
    gameBoard->fillBoard(scene, 100, 100);

    // crear maso de cartas

    deck = new DeckStack(104); // fijar la cantidad maxima de elementos a la cantidad de naipes que hay en el juego
    fillDeck(deck);

    // crear el cementerio de cartas

    discardPile = new DeckStack(104);
    discardPile->setPos(1000, 300);

    // crea un naipes (PRUEBA)
    Card * esteNaipe = new Card(":/Cartas/naipes/ace_of_spades.png", 50, 50);
    esteNaipe->setScale(50);
    scene->addItem(esteNaipe);

    Card * esteOtroNaipe = new Card(":/Cartas/naipes/5_of_spades.png", 100, 50);
    esteOtroNaipe->setScale(50);
    scene->addItem(esteOtroNaipe);       

    this->show(); // Muestra la escena actual
}

void Controll::pickupCard(Card *naipe)
{
    if (draggingItem == NULL)
    {
        this->draggingItem = naipe;
        this->draggingItemPosX = naipe->pos().x();
        this->draggingItemPosY = naipe->pos().y();
    }
}

void Controll::clickTablero(CardImage *cartaSeleccionada)
{
    if (draggingItem != NULL)
    {
        if (draggingItem->getUrl() == cartaSeleccionada->getUrl())
        {
            placeCard(draggingItem);
        }
        else
        {
            returnCardToHand();
        }
    }
}

void Controll::placeCard(Card * newCard)
{    
    if (topDiscardPile != NULL)
    {
        //qDebug() << "La carta no existe." ;
        scene->removeItem(topDiscardPile);
    }

    scene->addItem(newCard);
    newCard->setPos(discardPile->getPosX(), discardPile->getPosY());
    qDebug() << discardPile->getPosX() <<", "<< discardPile->getPosY();
    draggingItem->setPlaced(true);
    draggingItem = NULL;
}

void Controll::returnCardToHand()
{
    draggingItem->setPos(draggingItemPosX, draggingItemPosY);
    draggingItem = NULL;
    qDebug() << "Nope!";
}

void Controll::fillDeck(DeckStack * maso)
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
            Card * naipeActual = new Card(nombreCarta);
            maso->push(naipeActual);
            //qDebug() << nombreCarta;
        }
    }
}

void Controll::showTopDiscardPile(Card *cardToShow) // useless
{
    removeDiscardPile();
    topDiscardPile = cardToShow;
    scene->addItem(cardToShow);
}

void Controll::removeDiscardPile() // useless
{
    if (topDiscardPile != NULL)
    {
        scene->removeItem(topDiscardPile);
        topDiscardPile = NULL;
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


