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