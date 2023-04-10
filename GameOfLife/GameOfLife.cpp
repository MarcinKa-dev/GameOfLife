#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

//Display board
void printBoard(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 1) {
                cout << "* ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

//Update board
int updateBoard(vector<vector<int>>& board) {
    int output = 0;
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> newBoard(rows, vector<int>(cols, 0));

    // Iterate for every element
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;

            // Check Neighbors count
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int row = i + x;
                    int col = j + y;
                    if (row >= 0 && row < rows && col >= 0 && col < cols && !(x == 0 && y == 0)) {
                        neighbors += board[row][col];
                    }
                }
            }

            // Game of life rules
            if ((board[i][j] == 1 && neighbors < 2) 
                || (board[i][j] == 1 && neighbors > 3)) {
                board[i][j] = 0;
            }
            else if ((board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) 
                || (board[i][j] == 0 && neighbors == 3)) {
                board[i][j] = 1;
            }
            if(board[i][j]==1)
                output++;
        }
    }
    return output;
}

int main() 
{
    srand(time(NULL));
    int rows = 20;
    int cols = 20;

    vector<vector<int>> board(rows, vector<int>(cols, 0));

    for(int i=0; i<rows; i++)
        for (int j = 0; j < cols; j++)
        {
            bool a = false;
            if (rand()%1000 < 200)
                a = true;
            if (a)
                board[i][j] = 1;
        }

    cout << "Initial board:" << endl;
    printBoard(board);

    int ou;
    for (int i = 0; i < 50; i++) {
        system("cls");
        ou = updateBoard(board);
        cout << "Board after round " << i + 1 << ":" << endl;
        printBoard(board);

        if (ou == 0)
        {
            cout << endl << "Game Over!";
            return 0;
        }
        else
            cout << "There is "<< ou << " particles of life!" << endl;
        Sleep(1000);
    }

    return 0;
}