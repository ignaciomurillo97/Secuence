#include "undopile.h"

UndoPile::UndoPile()
{
    PlayerAction * firstAction = new PlayerAction();
    this->firstAction = firstAction;
    this->lastAction = firstAction;
    size = 0;
}

/*
UndoPile::UndoPile()
{
    firstAction = NULL;
    lastAction = NULL;
    size = 0;
}
*/

PlayerAction *UndoPile::pop()
{
    if (lastAction != firstAction){
        PlayerAction * tmp = lastAction;

        PlayerAction * tmpSecondLast = firstAction;
        while (tmpSecondLast->getNext() != lastAction)
        {
            tmpSecondLast = tmpSecondLast->getNext();
        }
        tmpSecondLast->setNext(NULL);
        lastAction = tmpSecondLast;
        size --;
        return tmp;
    }
    return NULL;
}

/*
PlayerAction *UndoPile::pop()
{
    if (lastAction != NULL)
    {
        PlayerAction* tmp = lastAction;
        secondLastAction->setNext(NULL);
        lastAction = secondLastAction;
        updateSecondLast();
        return tmp;
        size --;
    }
}
*/
void UndoPile::updateSecondLast()
{
    secondLastAction = firstAction;
    while (secondLastAction->getNext() != lastAction)
    {
        secondLastAction = secondLastAction->getNext();
    }
}

void UndoPile::push(PlayerAction *action)
{
    lastAction->setNext(action);
    lastAction = action;
    size ++;
}
/*
void UndoPile::push(PlayerAction *action)
{
    if (firstAction == NULL)
    {
        firstAction = action;
        lastAction = action;
        size ++;
    }
    else
    {
        lastAction->setNext(action);
        secondLastAction = lastAction;
        lastAction = action;
        size ++;
    }
}
*/
