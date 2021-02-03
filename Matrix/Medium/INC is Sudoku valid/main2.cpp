#include <iostream>

using namespace std;

#define UNASSIGNED 0
#define N 9

bool isValid(int board[N][N], int x, int y, int value)
{
    int subGrid_i = 3 * (x / 3);
    int subGrid_j = 3 * (y / 3);

    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == value)
            return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == value)
            return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (value == board[subGrid_i + 1][subGrid_j + j])
            {
                return false;
            }
        }
    }

    return true;
}

bool isSudokuValid(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 0)
            {
                if (!isValid(board, i, j, board[i][j]))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int board[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> board[i][j];
            }
        }

        if (isSudokuValid)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}