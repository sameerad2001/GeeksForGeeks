#include <iostream>

using namespace std;

bool isValid(int board[9][9], int x, int y, int possibleOption)
{
    int subGrid_i = 3 * (x / 3);
    int subGrid_j = 3 * (y / 3);

    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == possibleOption)
            return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == possibleOption)
            return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (possibleOption == board[subGrid_i + 1][subGrid_j + j])
            {
                return false;
            }
        }
    }

    return true;
}

bool finished(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }

    return true;
}

int sudokuSolver(int board[9][9], int i, int j)
{

    // if (i == 9 && finished(board))
    // {
    //     return 1;
    // }
    // else if (i == 9)
    // {
    //     return 0;
    // }

    int next_i, next_j;
    if (j < 8)
    {
        next_i = i;
        next_j = j + 1;
    }
    else
    {
        next_i = i + 1;
        next_j = 0;
    }

    if (board[i][j] != 0)
    {
        sudokuSolver(board, next_i, next_j);
    }

    else
    {
        for (int possibleOptions = 1; possibleOptions <= 9; possibleOptions++)
        {
            board[i][j] = possibleOptions;
            if (isValid(board, i, j, possibleOptions))
            {
                sudokuSolver(board, next_i, next_j);
            }
            board[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int board[9][9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> board[i][j];
            }

            cout << sudokuSolver(board, 0, 0) << endl;
        }
    }
}