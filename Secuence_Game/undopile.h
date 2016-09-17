#ifndef UNDOPILE_H
#define UNDOPILE_H

#include "playeraction.h"

class UndoPile
{
public:
    UndoPile();
    //virtual ~UndoPile();
    PlayerAction * pop();
    PlayerAction * topValue();
    void push(PlayerAction * action);

    void updateSecondLast();
private:
    PlayerAction * firstAction;
    PlayerAction * lastAction;
    PlayerAction * secondLastAction;
    int size;
};

#endif // UNDOPILE_H
