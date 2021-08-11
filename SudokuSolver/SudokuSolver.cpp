#include <iostream>
#include <cmath>
using namespace std;

bool sudokucheck(int board[9][9], int row, int col, int number, int size)
{
    //checks whether number already exist or not in row & col
    for (int i = 0; i < size; i++)
    {
        if (board[i][col] == number || board[row][col] == number)
        {
            return false;
        }
    }

    size = sqrt(size); // finding the smallest sudoku matrix size eg. size is 9 => sqrt(9) => 3, small matrix is of 3x3
    int srow = (row / size) * size; // starting row of smallest matrix
    int scol = (col / size) * size; // starting col of smallest matrix

    // checking whether number exist in small matrix or not
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
    //return true as number doesn't exist in board at particular row & col
    return true;
}

bool sudoku(int board[9][9], int row, int col, int size)
{
    //Base Case
    if (row == size)// if in case row is equal to size of matrix means all the values filled out recursion will end now and print solved board
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
    if (col == size)// if col end in first row recursion call to next row
    {
        return sudoku(board, row + 1, 0, size);
    }
    if (board[row][col] != 0)// if board row & col already have non-zero value call recursion to next col
    {
        return sudoku(board, row, col + 1, size);
    }

    for (int number = 1; number <= size; number++)// it will check place 1 to 9 to each col of row
    {
        if (sudokucheck(board, row, col, number, size) == true)// it will return whether we can place number to col or not
        {
            board[row][col] = number;
            bool next = sudoku(board, row, col + 1, size);// call recursion to next col
            if (next == true)
            {
                return true;
            }
            board[row][col] = 0;// backtracking in case number allready exist
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
