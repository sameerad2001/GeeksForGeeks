#include <iostream>

using namespace std;

#define N 9
#define UNASSIGNED 0

bool isValid(int board[N][N], int x, int y, int value)
{
    int subGrid_i = 3 * (x / 3);
    int subGrid_j = 3 * (y / 3);

    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == value)
            return false;

        if (board[i][y] == value)
            return false;
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     if (board[i][y] == value)
    //         return false;
    // }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (value == board[subGrid_i + i][subGrid_j + j])
            {
                return false;
            }
        }
    }

    return true;
}

// bool isSudokuValid(int board[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             if (board[i][j] != 0)
//             {
//                 if (!isValid(board, i, j, board[i][j]))
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

int sudokuSolver(int board[N][N], int i, int j)
{

    if (i == N && j == 8)
    {
        return 1;
    }

    // if (i == N)
    // {
    //     return 1;
    // }

    int nexti, nextj;
    if (j < 8)
    {
        nexti = i;
        nextj = j + 1;
    }

    else
    {
        nexti = i + 1;
        nextj = 0;
    }

    if (board[i][j] != 0)
    {
        if (sudokuSolver(board, nexti, nextj))
        {
            return 1;
        }
    }

    else
    {
        for (int possibleOption = 1; possibleOption <= 9; possibleOption++)
        {
            if (isValid(board, i, j, possibleOption))
            {
                board[i][j] = possibleOption;

                // sudokuSolver(board, nexti, nextj);

                if (sudokuSolver(board, nexti, nextj))
                {
                    return 1;
                }

                board[i][j] = 0;
            }
        }

        return 0;
    }

    // return 0;
}

bool SolveSudoku(int board[N][N])
{
    if (sudokuSolver(board, 0, 0))
        return true;

    else
        return false;
}

void printGrid(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        // cout << "\n";
    }
}

// int main()
// {
// }