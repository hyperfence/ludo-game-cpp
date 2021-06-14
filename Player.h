#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Token.h"

class Player
{
private:
    std::string name;
    std::string color;
    Token *tokens;
    int totalTokens;
    int hitCount;
    int diceValue[3];

public:
    Player(int totalTokens, const std::string &color, const std::string name)
    {
        this->totalTokens = totalTokens;
        this->name = name;
        this->color = color;
        this->hitCount = 0;
        this->tokens = new Token[totalTokens];
        for (int i = 0; i < totalTokens; i++)
        {
            this->tokens[i].color = color;
            this->tokens[i].tokenNum = i + 1;
            this->tokens[i].won = false;
            // -1 indicates the token is still in the home
            this->tokens[i].cellNo = -1;
            this->tokens[i].xPos = -1;
            this->tokens[i].yPos = -1;
            this->tokens[i].next = NULL;
        }
        for(int i = 0; i < 3; i++)
            diceValue[i] = 0;
    }
    Token *getToken(int tokenNum);
    void incHitCount();
    int getHitCount() const;
    int getTotalTokens() const;
    void rollDice();
    void resetDiceValues();
    int* getDiceValues();
};

#endif