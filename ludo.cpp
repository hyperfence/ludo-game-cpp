#include <iostream>
#include "GamePlay.cpp"
#include "Grid.cpp"

// Path arrays
int red[72] = {0};  
int blue[72] = {0};
int yellow[72] = {0};
int green[72] = {0};


int main()
{
    Player player1(2, "Red", "Talha");
    Player player2(2, "Blue", "Hammad");
    Player player3(2, "Yellow", "Hamza");
    Player player4(2, "Green", "Abdullah");
    Grid ludoBoard;

    ludoBoard.updateGrid(6, player2, 1);
    ludoBoard.updateGrid(6, player3, 1);
    ludoBoard.updateGrid(6, player3, 2);
    ludoBoard.updateGrid(5, player3, 1);
    ludoBoard.updateGrid(5, player3, 2);
    ludoBoard.updateGrid(6, player2, 1);
    ludoBoard.updateGrid(6, player2, 1);
    ludoBoard.updateGrid(6, player2, 1);
    return 0;
}