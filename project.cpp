#include "raylib.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include "GamePlay.cpp"
#include "Grid.cpp"
#include <string.h>

using namespace std;

Coordinates BoardCoordinates[72];
/*
    A function that initializes the grid coordinates..
*/
void initBoardCoordinates()
{
    int x = 310;
    int y = 345;
    for (int i = 0; i < 6; i++)
    {
        BoardCoordinates[i] = {x, y};
        y = y + 34;
    }
    x -= 35;
    BoardCoordinates[6] = {x, y - 34};
    x -= 35;
    BoardCoordinates[7] = {x, y - 34};
    y -= 34;
    for (int i = 8; i < 13; i++)
    {
        y -= 34;
        BoardCoordinates[i] = {x, y};
    }
    x = 206;
    y = 310;
    for (int i = 13; i < 18; i++)
    {
        BoardCoordinates[i] = {x, y};
        x -= 34;
    }
    x -= 2;
    BoardCoordinates[18] = {x, y};
    y -= 34;
    BoardCoordinates[19] = {x, y};
    y -= 36;
    BoardCoordinates[20] = {x, y};
    for (int i = 21; i < 26; i++)
    {
        x += 34;
        BoardCoordinates[i] = {x, y};
    }
    x = 240;
    y = 206;
    for (int i = 26; i < 31; i++)
    {
        BoardCoordinates[i] = {x, y};
        y -= 34;
    }
    y -= 2;
    BoardCoordinates[31] = {x, y};
    x += 35;
    BoardCoordinates[32] = {x, y};
    x += 35;
    BoardCoordinates[33] = {x, y};
    for (int i = 34; i < 39; i++)
    {
        y += 34;
        BoardCoordinates[i] = {x, y};
    }
    x = 343;
    y = 240;
    for (int i = 39; i < 44; i++)
    {
        BoardCoordinates[i] = {x, y};
        x += 35;
    }
    x -= 2;
    BoardCoordinates[44] = {x, y};
    y += 35;
    BoardCoordinates[45] = {x, y};
    y += 35;
    BoardCoordinates[46] = {x, y};
    for (int i = 47; i < 51; i++)
    {
        x -= 35;
        BoardCoordinates[i] = {x, y};
    }
    BoardCoordinates[51] = {x - 34, y};
    x = 275;
    y = 515;
    for (int i = 52; i < 57; i++)
    {
        y -= 34;
        BoardCoordinates[i] = {x, y};
    }
    x = 32;
    y = 276;
    for (int i = 57; i < 62; i++)
    {
        x += 35;
        BoardCoordinates[i] = {x, y};
    }
    x = 275;
    y = 34;
    for (int i = 62; i < 67; i++)
    {
        y += 34;
        BoardCoordinates[i] = {x, y};
    }
    x = 515;
    y = 275;
    for (int i = 67; i < 72; i++)
    {
        x -= 34;
        BoardCoordinates[i] = {x, y};
    }
}

void initHomeTokens(Player& pl1, Player& pl2, Player& pl3, Player& pl4)
{
    for(int i=1; i<=pl1.getTotalTokens(); i++)
    {
        Token* token = pl1.getToken(i);
        if(token->cellNo != -1)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, RED);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 1)
        {
            DrawCircle(120, 395, 15, BLACK);
            DrawCircle(120, 395, 13, RED);
            DrawCircle(120, 395, 15 / 2 + 1, BLACK);
            DrawText("1", 120 - 2, 395 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 2)
        {
            DrawCircle(155, 430, 15, BLACK);
            DrawCircle(155, 430, 13, RED);
            DrawCircle(155, 430, 15 / 2 + 1, BLACK);
            DrawText("2", 155 - 2, 430 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 3)
        {
            DrawCircle(120, 465, 15, BLACK);
            DrawCircle(120, 465, 13, RED);
            DrawCircle(120, 465, 15 / 2 + 1, BLACK);
            DrawText("3", 120 - 2, 465 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 4)
        {
            DrawCircle(85, 432, 15, BLACK);
            DrawCircle(85, 432, 13, RED);
            DrawCircle(85, 432, 15 / 2 + 1, BLACK);
            DrawText("4", 85 - 2, 432 - 5, 13, WHITE);
        }
    }

    for(int i=1; i<=pl2.getTotalTokens(); i++)
    {
        Token* token = pl2.getToken(i);
        if(token->cellNo != -1)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, GREEN);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 1)
        {
            DrawCircle(120, 85, 15, BLACK);
            DrawCircle(120, 85, 13, GREEN);
            DrawCircle(120, 85, 15 / 2 + 1, BLACK);
            DrawText("1", 120 - 2, 85 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 2)
        {
            DrawCircle(155, 120, 15, BLACK);
            DrawCircle(155, 120, 13, GREEN);
            DrawCircle(155, 120, 15 / 2 + 1, BLACK);
            DrawText("2", 155 - 2, 120 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 3)
        {
            DrawCircle(120, 155, 15, BLACK);
            DrawCircle(120, 155, 13, GREEN);
            DrawCircle(120, 155, 15 / 2 + 1, BLACK);
            DrawText("3", 120 - 2, 155 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 4)
        {
            DrawCircle(86, 120, 15, BLACK);
            DrawCircle(86, 120, 13, GREEN);
            DrawCircle(86, 120, 15 / 2 + 1, BLACK);
            DrawText("4", 86 - 2, 120 - 5, 13, WHITE);
        }
    }

    for(int i=1; i<=pl3.getTotalTokens(); i++)
    {
        Token* token = pl3.getToken(i);
        if(token->cellNo != -1)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, YELLOW);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 1)
        {
            DrawCircle(430, 85, 15, BLACK);
            DrawCircle(430, 85, 13, YELLOW);
            DrawCircle(430, 85, 15 / 2 + 1, BLACK);
            DrawText("1", 430 - 2, 85 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 2)
        {
            DrawCircle(465, 120, 15, BLACK);
            DrawCircle(465, 120, 13, YELLOW);
            DrawCircle(465, 120, 15 / 2 + 1, BLACK);
            DrawText("2", 465 - 2, 120 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 3)
        {
            DrawCircle(430, 155, 15, BLACK);
            DrawCircle(430, 155, 13, YELLOW);
            DrawCircle(430, 155, 15 / 2 + 1, BLACK);
            DrawText("3", 430 - 2, 155 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 4)
        {
            DrawCircle(393, 120, 15, BLACK);
            DrawCircle(393, 120, 13, YELLOW);
            DrawCircle(393, 120, 15 / 2 + 1, BLACK);
            DrawText("4", 393 - 2, 120 - 5, 13, WHITE);
        }
    }

    for(int i=1; i<=pl4.getTotalTokens(); i++)
    {
        Token* token = pl4.getToken(i);
        if(token->cellNo != -1)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, BLUE);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 1)
        {
            DrawCircle(430, 396, 15, BLACK);
            DrawCircle(430, 396, 13, BLUE);
            DrawCircle(430, 396, 15 / 2 + 1, BLACK);
            DrawText("1", 430 - 2, 396 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 2)
        {
            DrawCircle(465, 430, 15, BLACK);
            DrawCircle(465, 430, 13, BLUE);
            DrawCircle(465, 430, 15 / 2 + 1, BLACK);
            DrawText("2", 465 - 2, 430 - 5, 13, WHITE);

        }
        else if(token->cellNo == -1 && i == 3)
        {
            DrawCircle(430, 465, 15, BLACK);
            DrawCircle(430, 465, 13, BLUE);
            DrawCircle(430, 465, 15 / 2 + 1, BLACK);
            DrawText("3", 430 - 2, 465 - 5, 13, WHITE);
        }
        else if(token->cellNo == -1 && i == 4)
        {
            DrawCircle(396, 430, 15, BLACK);
            DrawCircle(396, 430, 13, BLUE);
            DrawCircle(396, 430, 15 / 2 + 1, BLACK);
            DrawText("4", 396 - 2, 430 - 5, 13, WHITE);
        }
    }
}

void DrawDice(int dice1, int dice2, int dice3)
{
    DrawRectangle(582, 365, 50, 50, WHITE);
    DrawText(to_string(dice1).c_str(), 582 + 18, 365 + 16, 20, BLACK);

    DrawRectangle(640, 365, 50, 50, WHITE);
    DrawText(to_string(dice2).c_str(), 640 + 18, 365 + 16, 20, BLACK);

    DrawRectangle(698, 365, 50, 50, WHITE);
    DrawText(to_string(dice3).c_str(), 698 + 18, 365 + 16, 20, BLACK);
}

void DrawButton()
{
    DrawCircle(666, 455, 30, BLACK);
    DrawCircle(666, 455, 30, RED);
    DrawCircle(666, 455, 30 / 2 + 1, PURPLE);
}

bool isButtonPressed()
{
    if (GetMouseX() >= 638 && GetMouseX() <= 693)
        if (GetMouseY() >= 428 && GetMouseY() <= 483)
            return true;
    return false;
}

int main()
{
    // Players & Board
    Player player1(4, "Red", "Talha");
    Player player2(4, "Green", "Hammad");
    Player player3(4, "Yellow", "Hamza");
    Player player4(4, "Blue", "Abdullah");
    Grid ludoBoard;

    // Dice, player's turn, Token No.
    ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player3, 1);
    // ludoBoard.updateGrid(6, player3, 2);
    // ludoBoard.updateGrid(5, player3, 1);
    ludoBoard.updateGrid(5, player2, 2);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);

    int offset = 0;
    int dice1 = 0, dice2 = 0, dice3 = 0;
    GamePlay game;
    // 1000 -> Width, Board(800X800)
    const int window_width = 780;
    const int window_height = 550;
    srand(time(NULL));

    initBoardCoordinates();
    InitWindow(window_width, window_height, "Ludo");

    Texture2D Board = LoadTexture("./Images/Board.png");

    bool canRoll = false;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(Board, 0, 0, WHITE);
        initHomeTokens(player1, player2, player3, player4);
        DrawButton();

        if (canRoll)
        {
            dice1 = game.rollDice();
            dice2 = game.rollDice();
            dice3 = game.rollDice();
            canRoll = false;
        }
        DrawDice(dice1, dice2, dice3);

        //DrawToken(BLUE);

        int key = GetCharPressed();
        if (key)
        {
            offset += game.rollDice();
            //DrawToken(BLUE, offset);
        }
        // 0 -> Left click, 1 -> Right click
        if (IsMouseButtonPressed(0))
        {
            cout << GetMouseX() << " " << GetMouseY() << endl;
            canRoll = isButtonPressed();
        }
        EndDrawing();
    }

    // Unloading from RAM
    UnloadTexture(Board);
    CloseWindow();
}
