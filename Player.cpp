/*
    Group Member1: Malik Talha Saeed    - 19I-0413(D)
    Group Member2: Hammad Ahmed         - 19I-0582(D)
*/
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