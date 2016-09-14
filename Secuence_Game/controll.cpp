#include "controll.h"

// constantes para el juego
#define screenWidth 1200
#define screenHeight 600

#define deckSize 104

#define handPositionX 1000
#define handPositionY 20

#define cardHeight 50
#define cardWidth 40

Controll::Controll()
{
    // inicializa las variables
    draggingItem = NULL;
    topDiscardPile = NULL;

    // crear el menu de inicio
    QGraphicsScene * mainMenu = new QGraphicsScene();

    // crear la escena del juego
    scene = new QGraphicsScene();
    setSceneRect(0, 0, screenWidth, screenHeight);

    // color de fondo
    //mainMenu->setBackgroundBrush(Qt::red);
    setBackgroundBrush(QBrush(QImage(":/img/MainMenu.png")));

    // quitar el scrollbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // asigna el tamano del "view"
    setFixedSize(screenWidth, screenHeight);

    // asigna la escena de el menu principal
    setScene(mainMenu);

    // crea los botones y conecta sus slots a sus respectivas funciones
    Button * startGameButton = new Button(":/img/StartGame.png", screenWidth / 3 + 100, 4 * screenHeight / 5, 0.5, 0);
    mainMenu->addItem(startGameButton);
    QObject::connect(startGameButton, SIGNAL(clicked()), this, SLOT(choosePlayerScreen()));

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

void Controll::placeCard(Naipe * newCard)
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

void Controll::fillDeck(DeckStack * deck)
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
                nombreCarta += "jack";
            else if (j == 12)
                nombreCarta += "queen";
            else if (j == 13)
                nombreCarta += "king";
            else
                nombreCarta += itoa(j, numstr, 10);

            nombreCarta += paloActual;
            Naipe * naipeActual = new Naipe(nombreCarta);
            deck->push(naipeActual);
            //qDebug() << nombreCarta;
        }
    }
}

void Controll::showTopDiscardPile(Naipe *cardToShow)
{
    removeDiscardPile();
    topDiscardPile = cardToShow;
    scene->addItem(cardToShow);
}

void Controll::choosePlayerScreen()
{
    // crea la escena para escoger la cantidad de jugadores
    QGraphicsScene * playerCountSelect = new QGraphicsScene();

    // asigna la imagen de fondo
    setBackgroundBrush(QBrush(QImage(":/img/BcakGround2.png")));
    //playerCountSelect->setBackgroundBrush(Qt::red);

    // asigna la escena del juego
    setScene(playerCountSelect);

    // agregar los botones para seleccionar la cantidad de jugadores
    Button * twoPlayerButton = new Button(":/img/2Players.png", screenWidth / 2, screenHeight / 4, 0.5, 0);
    playerCountSelect->addItem(twoPlayerButton);
    QObject::connect(twoPlayerButton, SIGNAL(clicked()), this, SLOT(setTwoPlayers()));

    Button * threePlayerButton = new Button(":/img/3Players.png", screenWidth / 2,  2 * screenHeight / 4, 0.5, 0);
    playerCountSelect->addItem(threePlayerButton);
    QObject::connect(threePlayerButton, SIGNAL(clicked()), this, SLOT(setThreePlayers()));

    Button * fourPlayerButton = new Button(":/img/4Players.png", screenWidth / 2, 3 * screenHeight / 4, 0.5, 0);
    playerCountSelect->addItem(fourPlayerButton);
    QObject::connect(fourPlayerButton, SIGNAL(clicked()), this, SLOT(setFourPlayers()));

    this->show();
}

void Controll::startGame()
{
    // asigna la imagen de fondo
    setBackgroundBrush(QBrush(QImage(":/img/Fondo.png")));

    // asigna la escena del juego
    setScene(scene);

    // crear un tablero
    gameBoard = new Tablero();
    gameBoard->fillBoard(scene, 100, 100);

    // crear maso de cartas
    deck = new DeckStack(deckSize); // fijar la cantidad maxima de elementos a la cantidad de naipes que hay en el juego
    fillDeck(deck); // agrega un maso completo de 52 cartas
    fillDeck(deck); // agrega un maso completo de 52 cartas

    // crear jugadores
    playerList = new playerCircleList(playerCount);
    for (int i = 0; i < playerCount; i++)
    {
        char numstr[2];
        QString playerName = "Player " ;
        playerName += itoa(i,numstr, 10);
        playerList->append(new Jugador(playerName, maxCardsPerPlayer));
    }

    // llenar las manos de los jugadores
    for (int i = 0; i < playerList->getSize(); i++)
    {
        playerList->getValue(i)->fillHand(this->deck);
    }

    // crear el cementerio de cartas

    discardPile = new DeckStack(deckSize);
    discardPile->setPos(1000, 300);

    // logica del juego
    int turnNumber = 0;
    //while (!checkWin())
    //{
        Jugador * currPlayer = playerList->getValue();

        // mostrar la mano del jugador actual
        showHand(currPlayer);

        turnNumber ++;
        playerList->next();
    //}

    this->show();
}

bool Controll::checkWin()
{
    // CAMBIAR!!!
    return false;
}

void Controll::showHand(Jugador *player)
{
//    CardArrayList * currHand = player->getHand();
//    qDebug() << currHand->getSize();

//    qDebug() << "mostrando hand";
    CardArrayList * currHand = player->getHand();
    for (int i = 0; i < currHand->getSize(); i++)
    {
        Naipe* currCard = currHand->getValue(i);
        scene->addItem(currCard);
        #define cardDisplacement 60
        currCard->setPos(handPositionX, handPositionY + i * cardDisplacement);
        currCard->setScale(50);
    }
}

void Controll::removeDiscardPile()
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

void Controll::setTwoPlayers()
{
    playerCount = 2;
    maxCardsPerPlayer = 7;
    startGame();
}

void Controll::setThreePlayers()
{
    playerCount = 3;
    maxCardsPerPlayer = 7;
    startGame();
}

void Controll::setFourPlayers()
{
    playerCount = 4;
    maxCardsPerPlayer = 6;
    startGame();
}
