#include <iostream>
#include <cmath>
using namespace std;

bool sudokucheck(int board[9][9], int row, int col, int number, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (board[i][col] == number || board[row][col] == number)
        {
            return false;
        }
    }

    size = sqrt(size);
    int srow = (row / size) * size;
    int scol = (col / size) * size;

    for (int i = srow; i < srow + size; i++)
    {
        for (int j = scol; j < scol + size; j++)
        {
            if (board[i][j] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int board[9][9], int row, int col, int size)
{
    //Base Case
    if (row == size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    //Recursive Case
    if (col == size)
    {
        return sudoku(board, row + 1, 0, size);
    }
    if (board[row][col] != 0)
    {
        return sudoku(board, row, col + 1, size);
    }

    for (int number = 1; number <= size; number++)
    {
        if (sudokucheck(board, row, col, number, size) == true)
        {
            board[row][col] = number;
            bool next = sudoku(board, row, col + 1, size);
            if (next == true)
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    int board[9][9] = {
        {5, 3, 4, 0, 7, 0, 0, 0, 0}, //0 denotes empty
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    sudoku(board, 0, 0, 9);
    return 0;
}
