#include "Grid.h"

void Grid::updateGrid(int diceValue, Player& player, int tokenNum)
{
    Token* token = player.getToken(tokenNum);
    std::cout << token->color << "'s Token " << token->tokenNum << " Address: " << token << std::endl;
    int cellNo = token->cellNo;
    // Check if the token is inside home
    if(token->cellNo == -1 && token->xPos == -1 && token->yPos == -1)
    {
        if(diceValue == 6)
        {
            if(token->color == "Red")
            {
                token->cellNo = 8;
                Coordinates xy = this->get2DCoordinates(token->cellNo);
                token->xPos = xy.x;
                token->yPos = xy.y;
                board[token->xPos][token->yPos] = static_cast<void *>(token);
                std::cout << "Red's Token " << tokenNum << " left home!" << std::endl;
            }
            else if(token->color == "Green")
            {
                token->cellNo = 21;
                Coordinates xy = this->get2DCoordinates(token->cellNo);
                token->xPos = xy.x;
                token->yPos = xy.y;
                board[token->xPos][token->yPos] = static_cast<void *>(token);
                std::cout << "Green's Token " << tokenNum << " left home!" << std::endl;
            }
            else if(token->color == "Yellow")
            {
                token->cellNo = 34;
                Coordinates xy = this->get2DCoordinates(token->cellNo);
                token->xPos = xy.x;
                token->yPos = xy.y;
                board[token->xPos][token->yPos] = static_cast<void *>(token);
                std::cout << "Yellow's Token " << tokenNum << " left home!" << std::endl;
            }
            else if(token->color == "Blue")
            {
                token->cellNo = 47;
                Coordinates xy = this->get2DCoordinates(token->cellNo);
                token->xPos = xy.x;
                token->yPos = xy.y;
                board[token->xPos][token->yPos] = static_cast<void *>(token);
                std::cout << "Blue's Token " << tokenNum << " left home!" << std::endl;
            }
        }
        else
        {
            std::cout << token->color << "'s Token " << tokenNum << " can't leave home! Six is required to leave." << std::endl;
            return;
        }
    }
    else
    {
        int destinationCell = cellNo + diceValue;
        if(destinationCell > 51 && !isInVictoryPath(cellNo, token->color))
        {
            destinationCell = destinationCell - 51 - 1; // Adding -1 because path starts from 0
        }
        // Check if the token is about to win
        // Check for the red token
        if(destinationCell >= 57 && token->color == "Red")
        {
            if(destinationCell == 57)
            {
                // Yay the token won so remove it from the board
                board[token->xPos][token->yPos] = nullptr;
                token->won = true;
            }
            else
            {   
                std::cout << token->color << "'s Token " << tokenNum << " can't finish victory path! " << 57 - cellNo << " is required to win." << std::endl;
                return;
            }
        }
        // check for the green token
        else if(destinationCell >= 62 && token->color == "Green")
        {
            if(destinationCell == 62)
            {
                // Yay the token won so remove it from the board
                board[token->xPos][token->yPos] = nullptr;
                token->won = true;
            }
            else
            {   
                std::cout << token->color << "'s Token " << tokenNum << " can't finish victory path! " << 62 - cellNo << " is required to win." << std::endl;
                return;
            }
        }
        // check for the yellow token
        else if(destinationCell >= 67 && token->color == "Yellow")
        {
            if(destinationCell == 67)
            {
                // Yay the token won so remove it from the board
                board[token->xPos][token->yPos] = nullptr;
                token->won = true;
            }
            else
            {   
                std::cout << token->color << "'s Token " << tokenNum << " can't finish victory path! " << 67 - cellNo << " is required to win." << std::endl;
                return;
            }
        }
        // check for the blue token
        else if(destinationCell >= 72 && token->color == "Blue")
        {
            if(destinationCell == 72)
            {
                // Yay the token won so remove it from the board
                board[token->xPos][token->yPos] = nullptr;
                token->won = true;
            }
            else
            {   
                std::cout << token->color << "'s Token " << tokenNum << " can't finish victory path! " << 72 - cellNo << " is required to win." << std::endl;
                return;
            }
        }
        // Check if the token is ready to go to the victory path
        // Reds Home Run
        if(destinationCell > 6 && token->color == "Red" && cellNo <= 6 && cellNo >= 1)
        {
            if(player.getHitCount() >= 1)
            {
                int offset = destinationCell - 6;
                destinationCell = 51 + offset;
                std::cout << token->color << "'s Token " << token->tokenNum << " entered victory path!" << std::endl;
            }
            else
            {
                std::cout << token->color << "'s Token " << token->tokenNum << " not allowed to enter victory!" << std::endl;
            }
        }
        // Greens Home Run
        else if(destinationCell > 19 && token->color == "Green" && cellNo <= 19 && cellNo >= 14)
        {
            if(player.getHitCount() >= 1)
            {
                int offset = destinationCell - 19;
                destinationCell = 56 + offset;
                std::cout << token->color << "'s Token " << token->tokenNum << " entered victory path!" << std::endl;
            }
            else
            {   
                std::cout << token->color << "'s Token " << token->tokenNum << " not allowed to enter victory path!" << std::endl;
            }
        }
        // Yellows Home Run
        else if(destinationCell > 32 && token->color == "Yellow" && cellNo <= 32 && cellNo >= 27)
        {
            if(player.getHitCount() >= 1)
            {
                int offset = destinationCell - 32;
                destinationCell = 61 + offset;
                std::cout << token->color << "'s Token " << token->tokenNum << " entered victory path!" << std::endl;
            }
            else
            {
                std::cout << token->color << "'s Token " << token->tokenNum << " not allowed to enter victory path!" << std::endl;
            }
        }
        // Blues Home Run
        else if(destinationCell > 45 && token->color == "Blue" && cellNo <= 45 && cellNo >= 40)
        {
            if(player.getHitCount() >= 1)
            {
                int offset = destinationCell - 45;
                destinationCell = 66 + offset;
                std::cout << token->color << "'s Token " << token->tokenNum << " entered victory path!" << std::endl;
            }
            else
            {
                std::cout << token->color << "'s Token " << token->tokenNum << " not allowed to enter victory path!" << std::endl;
            }
        }
        // Check if token is legal to move, ie. no stacker is in way
        for(int i=cellNo; i<=destinationCell; i++)
        {
            if(!isAreaSafe(i))
            {
                Coordinates temp = get2DCoordinates(i);
                if(board[temp.x][temp.y] != nullptr)
                {
                    int stackCount = 0;
                    Token* opponent = static_cast<Token*>(board[temp.x][temp.y]);
                    std::string opponentColor = opponent->color;
                    // For teams stacking...
                    while(opponent != NULL)
                    {
                        if(opponentColor != opponent->color)
                        {
                            opponent = opponent->next;
                            continue;
                        }
                        stackCount++;
                        opponent = opponent->next;
                    }
                    if(stackCount >= 2)
                    {
                        std::cout << token->color << "'s Token " << token->tokenNum << " can't take turn! Opponent " << opponentColor << "'s stack is in way." << std::endl;
                        return;
                    }
                }
            }
        }
        // The move is legal and allowed so first delete the tokens old postion
        board[token->xPos][token->yPos] = nullptr;
        // Set new coordinates for the token
        Coordinates pos = get2DCoordinates(destinationCell);
        std::cout << "New Coordinates: [" << pos.x << ", " << pos.y << "]" << std::endl;
        token->xPos = pos.x;
        token->yPos = pos.y;
        token->cellNo = destinationCell;
        if(board[pos.x][pos.y] == nullptr)
        {
            std::cout << token->color << "'s Token " << token->tokenNum << " currently at Cell: " << destinationCell << std::endl;
            board[pos.x][pos.y] = static_cast<void *>(token);
        }
        else
        {
            Token* temp = static_cast<Token*>(board[pos.x][pos.y]);
            // Check if tokens are of same color or not
            // If tokens aren't of same color then check if they are on the safe area
            if(temp->color != token->color)
            {
                if(isAreaSafe(destinationCell))
                {
                    // Both the token have different color, however, they are in safe area hence chaining them together
                    std::cout << "Multiple tokens resting in the safe area " << cellNo << "!" << std::endl;
                    temp->next = token;
                }
                else
                {
                    player.incHitCount();
                    board[pos.x][pos.y] = static_cast<void *>(token);
                    std::cout << token->color <<"'s Token " << token->tokenNum << " Killed " << temp->color << "'s Token " << temp->tokenNum << "!" << std::endl;
                    // reset the killed token back to home
                    temp->cellNo = -1;
                    temp->xPos = -1;
                    temp->yPos = -1;
                }
            }
            else
            {
                std::cout << "Group formed at Cell: " << destinationCell << std::endl;
                // Both the token have same color, so they fall under same player hence chaining them together
                temp->next = token;
            }
        }
        std::cout << "Value in Ludo Board at [" << pos.x << "][" << pos.y << "]: " << board[pos.x][pos.y] << std::endl;
    }
}
bool Grid::isInVictoryPath(int cellNo, const std::string& color)
{
    if(color == "Red")
    {
        if(cellNo >= 52 && cellNo <= 56)
        {
            return true;
        }
    }
    else if(color == "Green")
    {
        if(cellNo >= 57 && cellNo <= 61)
        {
            return true;
        }
    }
    else if(color == "Yellow")
    {
        if(cellNo >= 62 && cellNo <= 66)
        {
            return true;
        }
    }
    else if(color == "Blue")
    {
        if(cellNo >= 67 && cellNo <= 71)
        {
            return true;
        }
    }
    return false;
}
bool Grid::isAreaSafe(int cellNo)
{
    // Safe areas in red block
    if(cellNo == 3 || cellNo == 8)
    {
        return true;
    }
    // Safe areas in green block
    else if(cellNo == 17 || cellNo == 21)
    {
        return true;
    }
    // Safe areas in yellow block
    else if(cellNo == 29 || cellNo == 34)
    {
        return true;
    }
    //safe area in blue block
    else if(cellNo == 42 || cellNo == 47)
    {
        return true;
    }
    return false;
}
Coordinates Grid::get2DCoordinates(int cellNo)
{
    // Checking the quadrant of it..
    // 1 -> Red, 2-> Blue, 3-> Yellow, 4-> Green
    int row, col;
    row = col = -1;
    // For Red Home
    if ((cellNo >= 0 && cellNo <= 12) || (cellNo >= 52 && cellNo <= 56))
    {
        if (cellNo >= 0 && cellNo <= 5)
        {
            row = 9 + cellNo;
            col = 8;
        }
        else if (cellNo >= 7 && cellNo <= 12)
        {
            row = 9 + (12 - cellNo);
            col = 6;
        }
        else if(cellNo >= 52 && cellNo <= 56)
        {
            row = 9 + (56 - cellNo);
            col = 7;
        }
        // Middle cell
        else 
        {
            row = 14;
            col = 7;
        }
    }
    // For Blue Home
    else if ((cellNo >= 13 && cellNo <= 25) || (cellNo >= 57 && cellNo <= 61))
    {
        if (cellNo >= 13 && cellNo <= 18)
        {
            row = 8;
            col = 0 + (18 - cellNo);
        }
        else if (cellNo >= 20 && cellNo <= 25)
        {
            row = 6;
            col = 0 + (cellNo - 20);
        }
        else if(cellNo >= 57 && cellNo <= 61)
        {
            row = 7;
            col = 1 + (cellNo - 57);
        }
        else // Middle cell
        {
            row = 7;
            col = 0;
        }
    }
    // For Yellow Home
    else if ((cellNo >= 26 && cellNo <= 38) || (cellNo >= 62 && cellNo <= 66))
    {
        if (cellNo >= 26 && cellNo <= 31)
        {
            row = 0 + (31 - cellNo);
            col = 6;
        }
        else if (cellNo >= 33 && cellNo <= 38)
        {
            row = 0 + (cellNo - 33);
            col = 8;
        }
        else if(cellNo >= 62 && cellNo <= 66)
        {
            row = 1 + (cellNo - 62);
            col = 7;
        }
        else // Middle Cell
        {
            row = 0;
            col = 7;
        }
    }
    // For Green Home
    else if ((cellNo >= 39 && cellNo <= 51) || (cellNo >= 67 && cellNo <= 71))
    {
        if (cellNo >= 39 && cellNo <= 44)
        {
            row = 6;
            col = 9 + (cellNo - 39);
        }
        else if (cellNo >= 46 && cellNo <= 51)
        {
            row = 8;
            col = 9 + (51 - cellNo);
        }
        else if(cellNo >= 67 && cellNo <= 71)
        {
            row = 7;
            col = 9 + (71 - cellNo);
        }
        else // Middle Cell
        {
            row = 7;
            col = 14;
        }
    }
    // std::cout << "Row: " << row << std::endl;
    // std::cout << "Col: " << col << std::endl;
    return {row, col};
}