#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include "Token.h"
#include "Player.cpp"

struct Coordinates
{
    int x;
    int y;
};

class Grid
{
    private:
        void*** board;
        int xDimension;
        int yDimension;

    public:
        Grid()
        {
            this->xDimension = 15;
            this->yDimension = 15;
            board = new void**[this->yDimension];
            for(int i=0; i<15; i++)
            {
                board[i] = new void*[this->xDimension];
            }
            for(int i=0; i<15; i++)
            {
                for(int j=0; j<15; j++)
                {
                    board[i][j] = nullptr;
                }
            }
        }
        void updateGrid(int diceValue, Player& player, int tokenNum, int& errorStatus);
        bool isAreaSafe(int cellNo);
        bool isInVictoryPath(int cellNo, const std::string& color);
        Coordinates get2DCoordinates(int cellNo);
};

#endif