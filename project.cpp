#include "raylib.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include "GamePlay.cpp"
#include "Grid.cpp"
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

Grid ludoBoard;
Coordinates BoardCoordinates[72];
int selectedDice = -1;
int selectedToken = -1;
bool turnCompleted = false;
int diceValues[3] = {0};
sem_t playersTurn_sem;
int mainTurn;
bool canStartScreen = true;
Player player1(4, "Red", "Talha");
Player player2(4, "Green", "Hammad");
Player player3(4, "Yellow", "Hamza");
Player player4(4, "Blue", "Abdullah");
/*
        A function that initializes the grid coordinates..
    */

void selectDice(int dice1, int dice2, int dice3)
{
    if (GetMouseX() >= 584 && GetMouseX() <= 632 && IsMouseButtonPressed(0) && dice1 != 0)
    {
        if (GetMouseY() >= 366 && GetMouseY() <= 415 && IsMouseButtonPressed(0))
        {
            std::cout << "Dice Selected" << std::endl;
            selectedDice = 0;
        }
    }
    else if (GetMouseX() >= 642 && GetMouseX() <= 690 && IsMouseButtonPressed(0) && dice2 != 0)
    {
        if (GetMouseY() >= 366 && GetMouseY() <= 415 && IsMouseButtonPressed(0))
        {
            std::cout << "Dice Selected" << std::endl;
            selectedDice = 1;
        }
    }
    else if (GetMouseX() >= 700 && GetMouseX() <= 748 && IsMouseButtonPressed(0) && dice3 != 0)
    {
        if (GetMouseY() >= 366 && GetMouseY() <= 415 && IsMouseButtonPressed(0))
        {
            std::cout << "Dice Selected" << std::endl;
            selectedDice = 2;
        }
    }

    if (selectedDice == 0)
    {
        Rectangle rec = {580, 363, 53, 53};
        DrawRectangleLinesEx(rec, 4, RED);
    }
    else if (selectedDice == 1)
    {
        Rectangle rec = {638, 363, 53, 53};
        DrawRectangleLinesEx(rec, 4, RED);
    }
    else if (selectedDice == 2)
    {
        Rectangle rec = {696, 363, 53, 53};
        DrawRectangleLinesEx(rec, 4, RED);
    }
}
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

void initHomeTokens(Player &pl1, Player &pl2, Player &pl3, Player &pl4)
{
    // Making Safe houses on each home...
    DrawRectangle(293, 431, 33, 33, RED);
    DrawRectangle(86, 293, 33, 33, GREEN);
    DrawRectangle(224, 86, 33, 33, YELLOW);
    DrawRectangle(431, 224, 33, 33, BLUE);

    for (int i = 1; i <= pl1.getTotalTokens(); i++)
    {
        Token *token = pl1.getToken(i);
        if (token->cellNo != -1 && token->won == false)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, RED);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 1 && token->won == false)
        {
            DrawCircle(120, 395, 15, BLACK);
            DrawCircle(120, 395, 13, RED);
            DrawCircle(120, 395, 15 / 2 + 1, BLACK);
            DrawText("1", 120 - 2, 395 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 2 && token->won == false)
        {
            DrawCircle(155, 430, 15, BLACK);
            DrawCircle(155, 430, 13, RED);
            DrawCircle(155, 430, 15 / 2 + 1, BLACK);
            DrawText("2", 155 - 2, 430 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 3 && token->won == false)
        {
            DrawCircle(120, 465, 15, BLACK);
            DrawCircle(120, 465, 13, RED);
            DrawCircle(120, 465, 15 / 2 + 1, BLACK);
            DrawText("3", 120 - 2, 465 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 4 && token->won == false)
        {
            DrawCircle(85, 432, 15, BLACK);
            DrawCircle(85, 432, 13, RED);
            DrawCircle(85, 432, 15 / 2 + 1, BLACK);
            DrawText("4", 85 - 2, 432 - 5, 13, WHITE);
        }
    }

    for (int i = 1; i <= pl2.getTotalTokens(); i++)
    {
        Token *token = pl2.getToken(i);
        if (token->cellNo != -1 && token->won == false)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, GREEN);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 1 && token->won == false)
        {
            DrawCircle(120, 85, 15, BLACK);
            DrawCircle(120, 85, 13, GREEN);
            DrawCircle(120, 85, 15 / 2 + 1, BLACK);
            DrawText("1", 120 - 2, 85 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 2 && token->won == false)
        {
            DrawCircle(155, 120, 15, BLACK);
            DrawCircle(155, 120, 13, GREEN);
            DrawCircle(155, 120, 15 / 2 + 1, BLACK);
            DrawText("2", 155 - 2, 120 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 3 && token->won == false)
        {
            DrawCircle(120, 155, 15, BLACK);
            DrawCircle(120, 155, 13, GREEN);
            DrawCircle(120, 155, 15 / 2 + 1, BLACK);
            DrawText("3", 120 - 2, 155 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 4 && token->won == false)
        {
            DrawCircle(86, 120, 15, BLACK);
            DrawCircle(86, 120, 13, GREEN);
            DrawCircle(86, 120, 15 / 2 + 1, BLACK);
            DrawText("4", 86 - 2, 120 - 5, 13, WHITE);
        }
    }

    for (int i = 1; i <= pl3.getTotalTokens(); i++)
    {
        Token *token = pl3.getToken(i);
        if (token->cellNo != -1 && token->won == false)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, YELLOW);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 1 && token->won == false)
        {
            DrawCircle(430, 85, 15, BLACK);
            DrawCircle(430, 85, 13, YELLOW);
            DrawCircle(430, 85, 15 / 2 + 1, BLACK);
            DrawText("1", 430 - 2, 85 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 2 && token->won == false)
        {
            DrawCircle(465, 120, 15, BLACK);
            DrawCircle(465, 120, 13, YELLOW);
            DrawCircle(465, 120, 15 / 2 + 1, BLACK);
            DrawText("2", 465 - 2, 120 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 3 && token->won == false)
        {
            DrawCircle(430, 155, 15, BLACK);
            DrawCircle(430, 155, 13, YELLOW);
            DrawCircle(430, 155, 15 / 2 + 1, BLACK);
            DrawText("3", 430 - 2, 155 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 4 && token->won == false)
        {
            DrawCircle(393, 120, 15, BLACK);
            DrawCircle(393, 120, 13, YELLOW);
            DrawCircle(393, 120, 15 / 2 + 1, BLACK);
            DrawText("4", 393 - 2, 120 - 5, 13, WHITE);
        }
    }

    for (int i = 1; i <= pl4.getTotalTokens(); i++)
    {
        Token *token = pl4.getToken(i);
        if (token->cellNo != -1 && token->won == false)
        {
            Coordinates drawCoord = BoardCoordinates[token->cellNo];
            DrawCircle(drawCoord.x, drawCoord.y, 15, BLACK);
            DrawCircle(drawCoord.x, drawCoord.y, 13, BLUE);
            DrawCircle(drawCoord.x, drawCoord.y, 15 / 2 + 1, BLACK);
            DrawText(to_string(token->tokenNum).c_str(), drawCoord.x - 2, drawCoord.y - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 1 && token->won == false)
        {
            DrawCircle(430, 396, 15, BLACK);
            DrawCircle(430, 396, 13, BLUE);
            DrawCircle(430, 396, 15 / 2 + 1, BLACK);
            DrawText("1", 430 - 2, 396 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 2 && token->won == false)
        {
            DrawCircle(465, 430, 15, BLACK);
            DrawCircle(465, 430, 13, BLUE);
            DrawCircle(465, 430, 15 / 2 + 1, BLACK);
            DrawText("2", 465 - 2, 430 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 3 && token->won == false)
        {
            DrawCircle(430, 465, 15, BLACK);
            DrawCircle(430, 465, 13, BLUE);
            DrawCircle(430, 465, 15 / 2 + 1, BLACK);
            DrawText("3", 430 - 2, 465 - 5, 13, WHITE);
        }
        else if (token->cellNo == -1 && i == 4 && token->won == false)
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

    if (mainTurn == 0)
    {
        std::string show = "RED's Turn";
        DrawText(show.c_str(), 582, 508, 20, RED);
    }
    else if (mainTurn == 1)
    {
        std::string show = "GREEN's Turn";
        DrawText(show.c_str(), 582, 508, 20, GREEN);
    }
    else if (mainTurn == 2)
    {
        std::string show = "YELLOW's Turn";
        DrawText(show.c_str(), 582, 508, 20, YELLOW);
    }
    else if (mainTurn == 3)
    {
        std::string show = "BLUE's Turn";
        DrawText(show.c_str(), 582, 508, 20, BLUE);
    }
}

void gameStats(Player &pl1, Player &pl2, Player &pl3, Player &pl4)
{
    DrawText("Ludo", 587, 39, 70, WHITE);
    Rectangle rec = {581, 33, 173, 80};
    DrawRectangleLinesEx(rec, 4, RED);
    DrawText("Player 1: ", 563, 148, 17, WHITE);
    DrawText("Player 2: ", 563, 188, 17, WHITE);
    DrawText("Player 3: ", 563, 228, 17, WHITE);
    DrawText("Player 4: ", 563, 268, 17, WHITE);
    DrawLine(752,147,752,286,WHITE);

    // Red
    int x = 650;
    int y = 156;
    for (int i = 0; i < pl1.getTotalTokens(); i++)
    {
        Token *token = pl1.getToken(i + 1);
        if (token->won)
        {
            DrawCircle(x, y, 15, BLACK);
            DrawCircle(x, y, 13, RED);
            DrawCircle(x, y, 15 / 2 + 1, BLACK);
            DrawText(to_string(i + 1).c_str(), x - 2, y - 5, 13, WHITE);
        }
        x += 30;
    }

    // Green
    x = 650;
    y = 156 + 40;
    for (int i = 0; i < pl2.getTotalTokens(); i++)
    {
        Token *token = pl2.getToken(i + 1);
        if (token->won)
        {
            DrawCircle(x, y, 15, BLACK);
            DrawCircle(x, y, 13, GREEN);
            DrawCircle(x, y, 15 / 2 + 1, BLACK);
            DrawText(to_string(i + 1).c_str(), x - 2, y - 5, 13, WHITE);
        }
        x += 30;
    }

    // Yellow
    x = 650;
    y = 156 + 40 + 40;
    for (int i = 0; i < pl3.getTotalTokens(); i++)
    {
        Token *token = pl3.getToken(i + 1);
        if (token->won)
        {
            DrawCircle(x, y, 15, BLACK);
            DrawCircle(x, y, 13, YELLOW);
            DrawCircle(x, y, 15 / 2 + 1, BLACK);
            DrawText(to_string(i + 1).c_str(), x - 2, y - 5, 13, WHITE);
        }
        x += 30;
    }

    // BLUE
    x = 650;
    y = 156 + 40 + 40 + 40;
    for (int i = 0; i < pl4.getTotalTokens(); i++)
    {
        Token *token = pl4.getToken(i + 1);
        if (token->won)
        {
            DrawCircle(x, y, 15, BLACK);
            DrawCircle(x, y, 13, BLUE);
            DrawCircle(x, y, 15 / 2 + 1, BLACK);
            DrawText(to_string(i + 1).c_str(), x - 2, y - 5, 13, WHITE);
        }
        x += 30;
    }
}
Player *getPlayer(int ID)
{
    if (ID == 0)
    {
        return &player1;
    }
    else if (ID == 1)
    {
        return &player2;
    }
    else if (ID == 2)
    {
        return &player3;
    }
    else if (ID == 3)
    {
        return &player4;
    }
    return NULL;
}
void *playerTurn(void *args)
{
    sem_wait(&playersTurn_sem);
    mainTurn = *(int *)args;

    Player *currPlayer;
    currPlayer = getPlayer(mainTurn);
    currPlayer->rollDice(0);
    int *diceVals = currPlayer->getDiceValues();
    if (diceVals[0] == 6)
    {
        currPlayer->rollDice(1);
        if (diceVals[1] == 6)
        {
            currPlayer->rollDice(2);
            if (diceVals[2] == 6)
            {
                currPlayer->resetDiceValues();
            }
        }
    }
    diceValues[0] = diceVals[0];
    diceValues[1] = diceVals[1];
    diceValues[2] = diceVals[2];
    turnCompleted = false;
    currPlayer->resetDiceValues();
    while (turnCompleted == false)
    {
        while (selectedDice == -1)
        {
            usleep(1000);
        }
        std::cout << "Reached" << std::endl;
        while (selectedToken == -1)
        {
            usleep(1000);
        }
        int errorStatus = -1;
        ludoBoard.updateGrid(diceValues[selectedDice], *currPlayer, selectedToken, errorStatus);
        diceValues[selectedDice] = 0;
        turnCompleted = true;
        selectedDice = -1;
        selectedToken = -1;
        for (int i = 0; i < 3; i++)
        {
            if (diceValues[i] != 0)
            {
                turnCompleted = false;
            }
        }
    }
    sem_post(&playersTurn_sem);
    return NULL;
}
void *masterThread(void *args)
{
    pthread_t th[4];
    while (true)
    {
        for (int i = 0; i < 4; i++)
        {
            int *value = new int;
            *value = i;
            pthread_create(&th[i], NULL, &playerTurn, value);
        }
        for (int i = 0; i < 4; i++)
        {
            pthread_join(th[i], NULL);
        }
    }
    return NULL;
}

void DrawButton()
{
    if (mainTurn == 0)
    {
        DrawCircle(666, 455, 30, BLACK);
        DrawCircle(666, 455, 30, RED);
        DrawCircle(666, 455, 30 / 2 + 1, WHITE);
    }
    else if (mainTurn == 1)
    {
        DrawCircle(666, 455, 30, BLACK);
        DrawCircle(666, 455, 30, GREEN);
        DrawCircle(666, 455, 30 / 2 + 1, PURPLE);
    }
    else if (mainTurn == 2)
    {
        DrawCircle(666, 455, 30, BLACK);
        DrawCircle(666, 455, 30, YELLOW);
        DrawCircle(666, 455, 30 / 2 + 1, PURPLE);
    }
    else if (mainTurn == 3)
    {
        DrawCircle(666, 455, 30, BLACK);
        DrawCircle(666, 455, 30, BLUE);
        DrawCircle(666, 455, 30 / 2 + 1, PURPLE);
    }
}

bool isButtonPressed()
{
    if (GetMouseX() >= 638 && GetMouseX() <= 693)
        if (GetMouseY() >= 428 && GetMouseY() <= 483)
            return true;
    return false;
}

bool isStartScreenButton()
{
    if (GetMouseX() >= 624 && GetMouseX() <= 703)
        if (GetMouseY() >= 224 && GetMouseY() <= 301)
            return true;
    return false;
}
void startScreen(Texture2D Screen)
{
    DrawText("Ludo", 587, 39, 70, WHITE);
    DrawText("Play Game", 563, 310, 40, GREEN);
    Rectangle rec = {581, 33, 173, 80};
    DrawRectangleLinesEx(rec, 4, RED);
    DrawTexture(Screen, 0, 0, WHITE);
    DrawCircle(663, 261, 40, SKYBLUE);
    Vector2 v1 = {648, 239};
    Vector2 v2 = {648, 278};
    Vector2 v3 = {693, 262};

    DrawTriangle(v1, v2, v3, GRAY);
    if (isStartScreenButton() == true && (IsMouseButtonPressed(0)))
    {
        canStartScreen = false;
    }
}
int main()
{
    // Players & Board
    sem_init(&playersTurn_sem, 0, 1);

    // Dice, player's turn, Token No.
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(1, player3, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(6, player2, 1);
    // ludoBoard.updateGrid(3, player2, 1);

    pthread_t th;
    pthread_create(&th, NULL, &masterThread, NULL);

    // 1000 -> Width, Board(800X800)
    const int window_width = 830;
    const int window_height = 550;
    srand(time(NULL));

    initBoardCoordinates();
    InitWindow(window_width, window_height, "Ludo");

    Texture2D Board = LoadTexture("./Images/Board.png");
    Texture2D Screen = LoadTexture("./Images/StartScreen.png");

    bool canRoll = false;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        if (!canStartScreen)
        {
            DrawTexture(Board, 0, 0, WHITE);

            initHomeTokens(player1, player2, player3, player4);
            DrawButton();

            if (canRoll)
            {
                canRoll = false;
            }
            DrawDice(diceValues[0], diceValues[1], diceValues[2]);
            selectDice(diceValues[0], diceValues[1], diceValues[2]);
            gameStats(player1, player2, player3, player4);
            int key = GetCharPressed();
            if (key)
            {
                if (key == '1' && turnCompleted == false)
                {
                    selectedToken = 1;
                    std::cout << "Pressed 1" << std::endl;
                }
                else if (key == '2' && turnCompleted == false)
                {
                    selectedToken = 2;
                    std::cout << "Pressed 2" << std::endl;
                }
                else if (key == '3' && turnCompleted == false)
                {
                    selectedToken = 3;
                    std::cout << "Pressed 2" << std::endl;
                }
                else if (key == '4' && turnCompleted == false)
                {
                    selectedToken = 4;
                    std::cout << "Pressed 2" << std::endl;
                }
                // offset += player1.rollDice();
                //DrawToken(BLUE, offset);
            }
            // 0 -> Left click, 1 -> Right click
            if (IsMouseButtonPressed(0))
            {
                cout << GetMouseX() << " " << GetMouseY() << endl;
                canRoll = isButtonPressed();
            }
        }
        else
        {
            startScreen(Screen);
        }

        EndDrawing();
    }

    sem_destroy(&playersTurn_sem);

    // Unloading from RAM
    UnloadTexture(Board);
    UnloadTexture(Screen);
    CloseWindow();
}
