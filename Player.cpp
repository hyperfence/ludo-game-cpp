#include "Player.h"

Token* Player::getToken(int tokenNum)
{
    if(tokenNum <= this->totalTokens)
    {
        return &this->tokens[tokenNum - 1];
    }
    std::cout << "Invalid Token Number!" << std::endl;
    return NULL;
}
void Player::incHitCount()
{
    this->hitCount++;
}
int Player::getHitCount()const
{
    return this->hitCount;
}
int Player::getTotalTokens()const
{
    return this->totalTokens;
}
void Player::rollDice(int index)
{
    diceValue[index] = (rand()%6 + 1);
}
void Player::resetDiceValues()
{
    for(int i = 0; i < 3; i++)
        diceValue[i] = 0;
}
int* Player::getDiceValues()
{
    return this->diceValue;
}