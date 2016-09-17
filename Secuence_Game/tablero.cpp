#include "tablero.h"


Tablero::Tablero()
{
    cardMatrix = new CardImage ** [width];
    for (int i = 0; i < width; i++)
    {
        cardMatrix[i] = new CardImage* [height];
    }

    tokenMatrix = new Token ** [width];
    for (int i = 0; i < width; i++)
    {
        tokenMatrix[i] = new Token* [height];
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            tokenMatrix[x][y] = NULL;
        }
    }

    standardBoardOrder = new QString [width*height];
    standardBoardOrder[0] = ":/Cartas/naipes/red_joker.png";
    standardBoardOrder[1] = ":/Cartas/naipes/6_of_diamonds.png";
    standardBoardOrder[2] = ":/Cartas/naipes/7_of_diamonds.png";
    standardBoardOrder[3] = ":/Cartas/naipes/8_of_diamonds.png";
    standardBoardOrder[4] = ":/Cartas/naipes/9_of_diamonds.png";
    standardBoardOrder[5] = ":/Cartas/naipes/10_of_diamonds.png";
    standardBoardOrder[6] = ":/Cartas/naipes/queen_of_diamonds.png";
    standardBoardOrder[7] = ":/Cartas/naipes/king_of_diamonds.png";
    standardBoardOrder[8] = ":/Cartas/naipes/ace_of_diamonds.png";
    standardBoardOrder[9] = ":/Cartas/naipes/red_joker.png";

    standardBoardOrder[10] = ":/Cartas/naipes/5_of_diamonds.png";
    standardBoardOrder[11] = ":/Cartas/naipes/3_of_hearts.png";
    standardBoardOrder[12] = ":/Cartas/naipes/2_of_hearts.png";
    standardBoardOrder[13] = ":/Cartas/naipes/2_of_spades.png";
    standardBoardOrder[14] = ":/Cartas/naipes/3_of_spades.png";
    standardBoardOrder[15] = ":/Cartas/naipes/4_of_spades.png";
    standardBoardOrder[16] = ":/Cartas/naipes/5_of_spades.png";
    standardBoardOrder[17] = ":/Cartas/naipes/6_of_spades.png";
    standardBoardOrder[18] = ":/Cartas/naipes/7_of_spades.png";
    standardBoardOrder[19] = ":/Cartas/naipes/ace_of_spades.png";

    standardBoardOrder[20] = ":/Cartas/naipes/4_of_diamonds.png";
    standardBoardOrder[21] = ":/Cartas/naipes/4_of_hearts.png";
    standardBoardOrder[22] = ":/Cartas/naipes/king_of_diamonds.png";
    standardBoardOrder[23] = ":/Cartas/naipes/ace_of_diamonds.png";
    standardBoardOrder[24] = ":/Cartas/naipes/ace_of_clubs.png";
    standardBoardOrder[25] = ":/Cartas/naipes/king_of_clubs.png";
    standardBoardOrder[26] = ":/Cartas/naipes/queen_of_clubs.png";
    standardBoardOrder[27] = ":/Cartas/naipes/10_of_clubs.png";
    standardBoardOrder[28] = ":/Cartas/naipes/8_of_clubs.png";
    standardBoardOrder[29] = ":/Cartas/naipes/king_of_clubs.png";

    standardBoardOrder[30] = ":/Cartas/naipes/3_of_diamonds.png";
    standardBoardOrder[31] = ":/Cartas/naipes/5_of_hearts.png";
    standardBoardOrder[32] = ":/Cartas/naipes/queen_of_diamonds.png";
    standardBoardOrder[33] = ":/Cartas/naipes/queen_of_hearts.png";
    standardBoardOrder[34] = ":/Cartas/naipes/10_of_hearts.png";
    standardBoardOrder[35] = ":/Cartas/naipes/9_of_hearts.png";
    standardBoardOrder[36] = ":/Cartas/naipes/8_of_hearts.png";
    standardBoardOrder[37] = ":/Cartas/naipes/9_of_clubs.png";
    standardBoardOrder[38] = ":/Cartas/naipes/9_of_spades.png";
    standardBoardOrder[39] = ":/Cartas/naipes/queen_of_clubs.png";

    standardBoardOrder[40] = ":/Cartas/naipes/2_of_diamonds.png";
    standardBoardOrder[41] = ":/Cartas/naipes/6_of_hearts.png";
    standardBoardOrder[42] = ":/Cartas/naipes/10_of_diamonds.png";
    standardBoardOrder[43] = ":/Cartas/naipes/king_of_hearts.png";
    standardBoardOrder[44] = ":/Cartas/naipes/3_of_hearts.png";
    standardBoardOrder[45] = ":/Cartas/naipes/2_of_hearts.png";
    standardBoardOrder[46] = ":/Cartas/naipes/7_of_hearts.png";
    standardBoardOrder[47] = ":/Cartas/naipes/8_of_clubs.png";
    standardBoardOrder[48] = ":/Cartas/naipes/10_of_spades.png";
    standardBoardOrder[49] = ":/Cartas/naipes/10_of_clubs.png";

    standardBoardOrder[50] = ":/Cartas/naipes/ace_of_spades.png";
    standardBoardOrder[51] = ":/Cartas/naipes/7_of_hearts.png";
    standardBoardOrder[52] = ":/Cartas/naipes/9_of_diamonds.png";
    standardBoardOrder[53] = ":/Cartas/naipes/ace_of_hearts.png";
    standardBoardOrder[54] = ":/Cartas/naipes/4_of_hearts.png";
    standardBoardOrder[55] = ":/Cartas/naipes/5_of_hearts.png";
    standardBoardOrder[56] = ":/Cartas/naipes/6_of_hearts.png";
    standardBoardOrder[57] = ":/Cartas/naipes/7_of_clubs.png";
    standardBoardOrder[58] = ":/Cartas/naipes/queen_of_clubs.png";
    standardBoardOrder[59] = ":/Cartas/naipes/9_of_clubs.png";

    standardBoardOrder[60] = ":/Cartas/naipes/king_of_spades.png";
    standardBoardOrder[61] = ":/Cartas/naipes/8_of_hearts.png";
    standardBoardOrder[62] = ":/Cartas/naipes/8_of_diamonds.png";
    standardBoardOrder[63] = ":/Cartas/naipes/2_of_clubs.png";
    standardBoardOrder[64] = ":/Cartas/naipes/3_of_clubs.png";
    standardBoardOrder[65] = ":/Cartas/naipes/4_of_clubs.png";
    standardBoardOrder[66] = ":/Cartas/naipes/5_of_clubs.png";
    standardBoardOrder[67] = ":/Cartas/naipes/6_of_clubs.png";
    standardBoardOrder[68] = ":/Cartas/naipes/king_of_spades.png";
    standardBoardOrder[69] = ":/Cartas/naipes/9_of_clubs.png";

    standardBoardOrder[70] = ":/Cartas/naipes/queen_of_spades.png";
    standardBoardOrder[71] = ":/Cartas/naipes/9_of_hearts.png";
    standardBoardOrder[72] = ":/Cartas/naipes/7_of_diamonds.png";
    standardBoardOrder[73] = ":/Cartas/naipes/6_of_diamonds.png";
    standardBoardOrder[74] = ":/Cartas/naipes/5_of_diamonds.png";
    standardBoardOrder[75] = ":/Cartas/naipes/4_of_diamonds.png";
    standardBoardOrder[76] = ":/Cartas/naipes/3_of_diamonds.png";
    standardBoardOrder[77] = ":/Cartas/naipes/2_of_diamonds.png";
    standardBoardOrder[78] = ":/Cartas/naipes/ace_of_spades.png";
    standardBoardOrder[79] = ":/Cartas/naipes/7_of_clubs.png";

    standardBoardOrder[80] = ":/Cartas/naipes/10_of_spades.png";
    standardBoardOrder[81] = ":/Cartas/naipes/10_of_hearts.png";
    standardBoardOrder[82] = ":/Cartas/naipes/queen_of_hearts.png";
    standardBoardOrder[83] = ":/Cartas/naipes/king_of_hearts.png";
    standardBoardOrder[84] = ":/Cartas/naipes/ace_of_hearts.png";
    standardBoardOrder[85] = ":/Cartas/naipes/2_of_clubs.png";
    standardBoardOrder[86] = ":/Cartas/naipes/3_of_clubs.png";
    standardBoardOrder[87] = ":/Cartas/naipes/4_of_clubs.png";
    standardBoardOrder[88] = ":/Cartas/naipes/5_of_clubs.png";
    standardBoardOrder[89] = ":/Cartas/naipes/6_of_clubs.png";

    standardBoardOrder[90] = ":/Cartas/naipes/red_joker.png";
    standardBoardOrder[91] = ":/Cartas/naipes/9_of_spades.png";
    standardBoardOrder[92] = ":/Cartas/naipes/8_of_spades.png";
    standardBoardOrder[93] = ":/Cartas/naipes/7_of_spades.png";
    standardBoardOrder[94] = ":/Cartas/naipes/6_of_spades.png";
    standardBoardOrder[95] = ":/Cartas/naipes/5_of_spades.png";
    standardBoardOrder[96] = ":/Cartas/naipes/4_of_spades.png";
    standardBoardOrder[97] = ":/Cartas/naipes/3_of_spades.png";
    standardBoardOrder[98] = ":/Cartas/naipes/2_of_spades.png";
    standardBoardOrder[99] = ":/Cartas/naipes/red_joker.png";
}

CardImage *Tablero::getValue(int x, int y)
{
    return cardMatrix[x][y];
}

Token *Tablero::getToken(int x, int y)
{
    return tokenMatrix[x][y];
}

void Tablero::setValue(int x, int y, CardImage *pNaipe)
{
    cardMatrix[x][y] = pNaipe;
}

void Tablero::fillBoard(QGraphicsScene * scene, int offsetX, int offsetY)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            CardImage * cartaActual =
                    new CardImage(":/Cartas/naipes/ace_of_spades.png", x * 55 + offsetX, y * 40 + offsetY, 55, 90);
            setValue (x, y, cartaActual);
            scene->addItem(cartaActual);
        }
    }
}

#define cardRotation 90
#define cardOffsetX 100
#define cardOffsetY 60
#define cardScale 80
#define boardOffsetX 100
#define boardOffsetY 20
void Tablero::standardFill(QGraphicsScene *scene)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            CardImage * cartaActual =
                    new CardImage(standardBoardOrder[y * width + x], x * cardOffsetX + boardOffsetX, y * cardOffsetY + boardOffsetY, cardScale, cardRotation);
            cartaActual->setIndice(x, y);
            setValue (x, y, cartaActual);
            scene->addItem(cartaActual);
        }
    }
}

void Tablero::addToken(int x, int y, QString owner, QString Url)
{
    tokenMatrix[x][y] = new Token(Url, x, y, owner);
}

void Tablero::addToken(int x, int y, Token *token)
{    
    tokenMatrix[x][y] = token;
    //qDebug () << "posiciones: " << x << y;
}

void Tablero::removeTokenfromBoard(int x, int y, QString owner, QGraphicsScene * scene)
{
    scene->removeItem(tokenMatrix[x][y]);
    tokenMatrix[x][y] = NULL;
}

bool Tablero::checkWin(QString currPlayer, int posX, int posY, int cardAmount)
{
    // diagonal creciente
    if (countSecuenceInDirection(posX, posY, 1, 1, 1, currPlayer) + countSecuenceInDirection(posX, posY, -1, -1, 1, currPlayer) >= cardAmount)
    {
        return true;
    }
    // vertical
    if (countSecuenceInDirection(posX, posY, 0, 1, 1, currPlayer) + countSecuenceInDirection(posX, posY, 0, -1, 1, currPlayer) >= cardAmount)
    {
        return true;
    }
    // diagonal decreciente
    if (countSecuenceInDirection(posX, posY, -1, 1, 1, currPlayer) + countSecuenceInDirection(posX, posY, 1, -1, 1, currPlayer) >= cardAmount)
    {
        return true;
    }
    // horizontal
    if (countSecuenceInDirection(posX, posY, 1, 0, 1, currPlayer) + countSecuenceInDirection(posX, posY, -1, 0, 1, currPlayer) >= cardAmount)
    {
        return true;
    }

    return false;
}

int Tablero::countSecuenceInDirection(int posX, int posY, int dirX, int dirY, int currRecursion, QString owner)
{
    //qDebug() << "recurcion: " << currRecursion;
    posX += dirX;
    posY += dirY;


    if (posX < 0 || posX > width-1)
    {
        //qDebug() << "WIN ERROR: out of bounds X";
        return currRecursion;
    }
    if (posY < 0 || posY > height-1)
    {
        //qDebug() << "WIN ERROR: out of bounds Y";
        return currRecursion;
    }
    if (tokenMatrix[posX][posY] == NULL || (posX == 0 && posY == 0) && (posX == 9 && posY == 0) && (posX == 0 && posY == 9) && (posX == 9 && posY == 9))
    {
        //qDebug() << "WIN ERROR: no Token at pos"<<posX<<posY;
        return currRecursion;
    }
    if (tokenMatrix[posX][posY]->getOwner() != owner || (posX == 0 && posY == 0) && (posX == 9 && posY == 0) && (posX == 0 && posY == 9) && (posX == 9 && posY == 9))
    {
        //qDebug() << "WIN ERROR: not the same owner";
        return currRecursion;
    }
    //qDebug() << "there is a Next Token";
    return countSecuenceInDirection(posX, posY, dirX, dirY, currRecursion + 1, owner);
}



