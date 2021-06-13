#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include "Grid.h"
#include "Player.h"
#include "Token.h"

class GamePlay
{
    private:
        int diceValue;
        int playersCount;
        int tokenPerPlayer;
        Player* players;
        Grid ludoBoard;

    public:
        GamePlay()
        {

        }

};

#endif