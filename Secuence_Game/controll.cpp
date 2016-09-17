#include "controll.h"

// constantes para el juego
#define screenWidth 1380
#define screenHeight 720

#define deckSize 104

#define handPositionX 1100
#define handPositionY 80

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

    currPlayerNameItem = NULL;

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

void Controll::clickTablero(CardImage *selectedCard)
{
    if (draggingItem != NULL)
    {                
        // Remover Fichas
        if ((draggingItem->getUrl() == ":/Cartas/naipes/jack_of_spades.png"
                 || draggingItem->getUrl() == ":/Cartas/naipes/jack_of_hearts.png")
                 && selectedCard->getUrl()!=":/Cartas/naipes/red_joker.png"
                 && gameBoard->getToken(selectedCard->getIndiceX(), selectedCard->getIndiceY())!=NULL
                 && currPlayer->getName() != gameBoard->getToken(selectedCard->getIndiceX(), selectedCard->getIndiceY())->getOwner())

        {            
            // pedir carta al maso
            Naipe * recievedCard = deck->pop();
            currPlayer->getHand()->append(recievedCard);

            // agregar accion a la pila          
            undoPile->push(new PlayerAction(draggingItem, recievedCard, selectedCard, gameBoard->getToken(selectedCard->getIndiceX(), selectedCard->getIndiceY())->getOwner(), currPlayer, selectedCard->getIndiceX(), selectedCard->getIndiceY()));
            //PlayerAction(Naipe *playedCard, Naipe *recievedCard, CardImage *removedCard,QString removedCardOwner, Jugador *player, int posX, int posY);

            // pasar el turno al siguiente jugador
            removeToken(selectedCard);
            placeCardOnDiscardPile(draggingItem);
            nextPlayer();
            draggingItem = NULL;
        }
        // Poner carta
        else if (draggingItem->getUrl() == selectedCard->getUrl()
                && gameBoard->getToken(selectedCard->getIndiceX(), selectedCard->getIndiceY()) == NULL)
        {
            removeCardFromHand(draggingItem);
            // agregar la accion a la pila de undo
            // undoPile->push(new PlayerAction(draggingItem, currPlayer, selectedCard->getIndiceX(), selectedCard->getIndiceY()));

            // agregar el elemento al discard pile
            placeCardOnDiscardPile(draggingItem);

            placeCard(selectedCard);
            // pedir carta al maso
            Naipe * recievedCard = deck->pop();
            currPlayer->getHand()->append(recievedCard);

            undoPile->push(new PlayerAction(draggingItem, recievedCard, selectedCard, gameBoard->getToken(selectedCard->getIndiceX(), selectedCard->getIndiceY())->getOwner(), currPlayer, selectedCard->getIndiceX(), selectedCard->getIndiceY()));
            // revizar el gane
            checkWin(selectedCard);
            // pasar el turno al siguiente jugador
            draggingItem = NULL;
            nextPlayer();
        }
        // Comodines
        else if ((draggingItem->getUrl() == ":/Cartas/naipes/jack_of_diamonds.png"
                 || draggingItem->getUrl() == ":/Cartas/naipes/jack_of_clubs.png")
                 && selectedCard->getUrl()!=":/Cartas/naipes/red_joker.png")
        {
            removeCardFromHand(draggingItem);                        

            // agregar el elemento al discard pile
            placeCardOnDiscardPile(draggingItem);

            placeCard(selectedCard);
            // pedir carta al maso
            Naipe * recievedCard = deck->pop();
            currPlayer->getHand()->append(recievedCard);

            undoPile->push(new PlayerAction(draggingItem, recievedCard, selectedCard, gameBoard->getToken(selectedCard->getIndiceX(), selectedCard->getIndiceY())->getOwner(), currPlayer, selectedCard->getIndiceX(), selectedCard->getIndiceY()));
            // checkWin
            checkWin(selectedCard);
            // pasar el turno al siguiente jugador
            draggingItem = NULL;
            nextPlayer();
        }
        // Ninguna de las anteriores
        else
        {
            returnCardToHand();
        }

        // revizar si el maso esta vacio para pasar las cartas de el discard pile al maso
        if (deck->isEmpty()){
            deck->refillDeck(discardPile);
        }        
    }
}

void Controll::placeCardOnDiscardPile(Naipe * newCard)
{    
    if (topDiscardPile != NULL)
    {
        //qDebug() << "La carta no existe." ;
        scene->removeItem(topDiscardPile);
    }

    scene->addItem(newCard);
    newCard->setPos(discardPile->getPosX(), discardPile->getPosY());
    discardPile->push(newCard);
    //qDebug() << discardPile->getPosX() <<", "<< discardPile->getPosY();
    //draggingItem->setPlaced(true);    
}

void Controll::returnCardToHand()
{
    draggingItem->setPos(draggingItemPosX, draggingItemPosY);
    draggingItem->setPlaced(true);
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
    setBackgroundBrush(QBrush(QImage(":/img/casino_card_background_wallpaper_hd_1920x1080_by_giozaga-d7intx0-1.jpg")));

    // asigna la escena del juego
    setScene(scene);

    // crear un tablero
    gameBoard = new Tablero();
    gameBoard->standardFill(scene);

    // crear la pila de acciones
    undoPile = new UndoPile();
    redoPile = new UndoPile();

    // crear maso de cartas
    deck = new DeckStack(deckSize); // fijar la cantidad maxima de elementos a la cantidad de naipes que hay en el juego
    fillDeck(deck); // agrega un maso completo de 52 cartas
    fillDeck(deck); // agrega un maso completo de 52 cartas
    deck->shuffle();
    // crear jugadores
    playerList = new playerCircleList(playerCount);
    for (int i = 1; i < playerCount + 1; i++)
    {
        char numstr[2];
        QString playerName = "Player ";
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
    currPlayer = playerList->getValue();

    // mostrar la mano y el nombre del jugador actual
    showCurrPlayerName();
    showHand(currPlayer);

    Button * next = new Button(":/img/Recurcion_1.png", 1200, 550, 0.05, 0);
    scene->addItem(next);
    connect (next, SIGNAL(clicked()), this, SLOT(nextPlayer()));

    Button * prev = new Button(":/img/Recurcion_1.png", 1200, 450, 0.05, 0);
    scene->addItem(prev);
    connect (prev, SIGNAL(clicked()), this, SLOT(previousPlayer()));

    Button * undo = new Button(":/img/Recurcion_1.png", 1200, 350, 0.05, 0);
    scene->addItem(undo);
    connect (undo, SIGNAL(clicked()), this, SLOT(undoLastAction()));

    Button * redo = new Button(":/img/Recurcion_1.png", 1200, 250, 0.05, 0);
    scene->addItem(redo);
    connect (redo, SIGNAL(clicked()), this, SLOT(redoLastAction()));

    // NAIPES PARA DEBUG
    Naipe * j1 = new Naipe(":/Cartas/naipes/jack_of_hearts.png", 1200, 20);
    Naipe * j2 = new Naipe(":/Cartas/naipes/jack_of_hearts.png", 1200, 50);
    Naipe * j3 = new Naipe(":/Cartas/naipes/jack_of_hearts.png", 1200, 80);

    scene->addItem(j1);
    scene->addItem(j2);
    scene->addItem(j3);
    this->show();
}

void Controll::removeCardFromHand(Naipe * selectedCard)
{
    // eliminar elemento de la mano
    int clickedItemIndex = currPlayer->getHand()->findElement(selectedCard);
    if (clickedItemIndex != -1)
    {
        currPlayer->getHand()->remove(clickedItemIndex);
    }
    else
    {
        qDebug() << "La carta no fue encontrada";
    }
}

#define tokenDisplacementX 58.5
#define tokenDisplacementY 4.5
void Controll::placeCard(CardImage * selectedCard)
{       
    if (selectedCard == NULL)
    {
        qDebug() << "la carta que se paso es nula";
        return;
    }

    // agregar ficha al tablero
    //qDebug()<<selectedCard->pos().x() <<selectedCard->pos().y();

    //
    Token * currToken;
    if (playerList->getPos() == 0)
        currToken =
            new Token(":/img/Token1.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, currPlayer->getName());
    if (playerList->getPos() == 1)
        currToken =
            new Token(":/img/Token2.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, currPlayer->getName());
    if (playerList->getPos() == 2)
        currToken =
            new Token(":/img/Token3.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, currPlayer->getName());
    if (playerList->getPos() == 3)
        currToken =
            new Token(":/img/Token4.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, currPlayer->getName());

    qDebug() << "El token ha sido creado";
    currToken->setScale(0.5);
    scene->addItem(currToken);    
    gameBoard->addToken(selectedCard->getIndiceX(), selectedCard->getIndiceY(), currToken);
}

void Controll::placeCard(CardImage *selectedCard, QString owner)
{
    if (selectedCard == NULL)
    {
        qDebug() << "la carta que se paso es nula";
        return;
    }

    Token * currToken;
    if (owner == "Player 1")
        currToken =
            new Token(":/img/Token1.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, owner);
    if (owner == "Player 2")
        currToken =
            new Token(":/img/Token2.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, owner);
    if (owner == "Player 3")
        currToken =
            new Token(":/img/Token3.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, owner);
    if (owner == "Player 4")
        currToken =
            new Token(":/img/Token4.png", selectedCard->pos().x() - tokenDisplacementX, selectedCard->pos().y() + tokenDisplacementY, owner);

    qDebug() << "El token ha sido creado";
    currToken->setScale(0.5);
    scene->addItem(currToken);
    qDebug() << "ke jesto: " << selectedCard->getIndiceX();
    gameBoard->addToken(selectedCard->getIndiceX(), selectedCard->getIndiceY(), currToken);
}

void Controll::removeToken(CardImage *selectedCard)
{
    // eliminar elemento de la mano
    int clickedItemIndex = currPlayer->getHand()->findElement(draggingItem);
    if (clickedItemIndex != -1)
    {
        currPlayer->getHand()->remove(clickedItemIndex);
    }
    else
    {
        qDebug() << "La carta no fue encontrada";
    }
    // agregar el elemento al discard pile    
    //Quitar ficha
    gameBoard->removeTokenfromBoard(selectedCard->getIndiceX(),selectedCard->getIndiceY(),currPlayer->getName(),scene);    

}

void Controll::checkWin(CardImage * selectedCard)
{
    // revizar el gane
    //qDebug() << "Game Won:" <<gameBoard->checkWin(currPlayer->getName(), selectedCard->getIndiceX(), selectedCard->getIndiceY(), 3);
    if (gameBoard->checkWin(currPlayer->getName(), selectedCard->getIndiceX(), selectedCard->getIndiceY(), 3))
    {
        showWinScreen();
    }
}

#define cardDisplacement 90
#define cardSize 80
void Controll::showHand(Jugador *player)
{
    CardArrayList * currHand = player->getHand();
    for (int i = 0; i < currHand->getSize(); i++)
    {
        Naipe* currCard = currHand->getValue(i);
        scene->addItem(currCard);
        currCard->setScale(cardSize);
        currCard->setPos(handPositionX, handPositionY + i * cardDisplacement);

    }
}

void Controll::removeHand(Jugador *player)
{
    CardArrayList * currHand = player->getHand();
    for (int i = 0; i < currHand->getSize(); i++)
    {
        Naipe* currCard = currHand->getValue(i);
        scene->removeItem(currCard);
    }
}

void Controll::showCurrPlayerName()
{
    if (currPlayerNameItem != NULL)
    {
        scene->removeItem(currPlayerNameItem);
    }

    currPlayerNameItem = new QGraphicsTextItem(currPlayer->getName());
    currPlayerNameItem->setPos(1100, 40);
    scene->addItem(currPlayerNameItem);
}

void Controll::showWinScreen()
{
    QGraphicsScene * winScene = new QGraphicsScene();
    this->setScene(winScene);
    setBackgroundBrush(QBrush(QImage(":/img/win-backgrounds.png")));

    QGraphicsTextItem * winText = new QGraphicsTextItem(currPlayer->getName() + " WINS!");
    QFont winFont( "Arial", 10, QFont::Bold);
    winText->setFont(winFont);
    winText->setPos(screenWidth / 2, screenHeight / 2);
    scene->addItem(winText);

}

void Controll::undoLastAction()
{
    PlayerAction* tmpAction = undoPile->pop();
    if (tmpAction != NULL)
    {
        //if (tmpAction->getPlayedCard() != NULL) qDebug() << "undo: carta no nula";
        if (tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_spades.png"
                || tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_hearts.png")
        {         
            // pasar al turno anterior
            previousPlayer();

            // quitar la carta que recibio el jugador
            removeHand(currPlayer);
            removeCardFromHand(tmpAction->getDeckPulledCard());

            // devolver la carta que recibio el jugador al deck
            deck->push(tmpAction->getDeckPulledCard());

            // devolver la carta que se jugo a la mano del jugador
            Naipe * tmpCard = discardPile->pop();
            qDebug() << tmpCard->getUrl();
            if (tmpCard != NULL)currPlayer->getHand()->append(tmpCard);
            tmpCard->setPlaced(true);
            showHand(currPlayer);

            // volver a colocar el token en el tablero
            placeCard(tmpAction->getRemovedCard(), tmpAction->getRemovedCardOwner());

            // pasar la accion al redo pile
        }

        //if (tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_diamonds.png"
        //        || tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_clubs.png")
        else
        {
            // pasar al turno anterior
            previousPlayer();

            // quitar la carta que recibio el jugador
            removeHand(currPlayer);
            removeCardFromHand(tmpAction->getDeckPulledCard());

            // devolver la carta que recibio el jugador al deck
            deck->push(tmpAction->getDeckPulledCard());

            // devolver la carta que se jugo a la mano del jugador
            Naipe * tmpCard = discardPile->pop();
            qDebug() << tmpCard->getUrl();
            if (tmpCard != NULL)currPlayer->getHand()->append(tmpCard);
            tmpCard->setPlaced(true);
            showHand(currPlayer);

            // quitar el token de la carta que se jugo
            removeToken(gameBoard->getValue(tmpAction->getPosX(), tmpAction->getPosY()));
        }
        redoPile->push(tmpAction);
    }
}

void Controll::redoLastAction()
{
    PlayerAction* tmpAction = redoPile->pop();
    if (tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_spades.png"
            || tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_hearts.png")
    {
        // pedir carta al maso
        Naipe * recievedCard = deck->pop();
        currPlayer->getHand()->append(recievedCard);

        // agregar accion a la pila
        //undoPile->push(new PlayerAction(draggingItem, recievedCard, selectedCard, gameBoard->getToken(selectedCard->getIndiceX(), selectedCard->getIndiceY())->getOwner(), currPlayer, selectedCard->getIndiceX(), selectedCard->getIndiceY()));
        //PlayerAction(Naipe *playedCard, Naipe *recievedCard, CardImage *removedCard,QString removedCardOwner, Jugador *player, int posX, int posY);

        // pasar el turno al siguiente jugador
        removeToken(tmpAction->getRemovedCard());
        placeCardOnDiscardPile(tmpAction->getPlayedCard());
        nextPlayer();
    }

    if (tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_diamonds.png"
            || tmpAction->getPlayedCard()->getUrl() == ":/Cartas/naipes/jack_of_clubs.png")
    {

    }
    else
    {

    }
    undoPile->push(tmpAction);
}

void Controll::nextPlayer()
{
    Jugador* previousPlayer = playerList->getValue();
    qDebug() << "quitando mano del sigiente jugador";
    if (previousPlayer == NULL) qDebug() << "el jugador previo es nulo";
    removeHand(previousPlayer);
    qDebug() << "mostrando la mano del jugador acutal";
    playerList->next();
    currPlayer = playerList->getValue();    
    showHand(currPlayer);
    showCurrPlayerName();
}

void Controll::previousPlayer()
{
    Jugador* previousPlayer = playerList->getValue();
    removeHand(previousPlayer);
    playerList->previous();
    currPlayer = playerList->getValue();
    showHand(currPlayer);
    showCurrPlayerName();
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
