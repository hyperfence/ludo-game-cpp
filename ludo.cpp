#include <iostream>
using namespace std;

// Ludo Grid
int Grid[15][15] = {0};

// Path arrays
int red[72] = {0};  
int blue[72] = {0};
int yellow[72] = {0};
int green[72] = {0};


// --------------------------------------------------------------------------
// Token's attributes
class Token{
private:
    int cellNo;
    int xPos;
    int yPos;
    string color;
    int tokenNum;
public:
    // To initialize a token
    void initToken(string color, int tokenNo){
        this->color = color;
        this->tokenNum = tokenNo; 
    }
};

// Player class..
class Player{
private:
    string name;
    string color;
    Token *tokens; 
    bool canEnterHome;
    int hitCount;
public:
    Player(int totalTokens)
    {
        name = "";
        color = "";
        canEnterHome = false;
        hitCount = 0;
        tokens = new Token[totalTokens];
    }
};


class Grid{

};


// ----------------------------------------------------------------------
// To display the path
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
        if (i % 12 == 0)
            cout << endl;
    }
}

// To get the 2D coordinates of the token
void get2DCoordinates(int cellNo)
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
    cout << "Row: " << row << endl
         << "Col: " << col << endl;
}
int main()
{
    int cell;
    for(int i = 0; i < 72; i++)
    {
        cout << "Cell NO: " << i << endl;
        get2DCoordinates(i);
        cout << endl;
    }
    // while(1){
    //     cout << "Enter Cell No: ";
    //     cin >> cell;
    //     get2DCoordinates(cell);
    // }

    return 0;
}