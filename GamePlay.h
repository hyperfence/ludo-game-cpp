#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include "Grid.h"
#include "Player.h"
#include "Token.h"
#include <cstdlib>
#include <time.h>

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
            srand(time(NULL));
        }

};

#endif