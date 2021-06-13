#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

class Token
{
    public:
        int cellNo;
        int xPos;
        int yPos;
        std::string color;
        int tokenNum;
        Token* next;
        bool won;
};

#endif