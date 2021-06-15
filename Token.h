/*
    Group Member1: Malik Talha Saeed    - 19I-0413(D)
    Group Member2: Hammad Ahmed         - 19I-0582(D)
*/
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