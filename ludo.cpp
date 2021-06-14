#include <iostream>
#include "GamePlay.cpp"
#include "Grid.cpp"

int main()
{
    Player player1(2, "Red", "Talha");
    Player player2(2, "Blue", "Hammad");
    Player player3(2, "Yellow", "Hamza");
    Player player4(2, "Green", "Abdullah");
    Grid ludoBoard;

    // Dice, player's turn, Token No.
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player3, 1);
    // ludoBoard.updateGrid(6, player3, 2);
    // ludoBoard.updateGrid(5, player3, 1);
    // ludoBoard.updateGrid(5, player3, 2);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    GamePlay game;
    for(int i = 0; i < 5; i++)
    {
        std::cout << game.rollDice() << std::endl;
    }

    return 0;
}