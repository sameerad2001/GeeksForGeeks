#include <iostream>
#include <vector>

using namespace std;

#define matAX 10000

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int S[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                S[i][j] = mat[i][j];
            }
            else if (mat[i][j] == 0)
            {
                S[i][j] = 0;
            }
            else
            {
                S[i][j] = min(mat[i][j - 1], mat[i - 1][j], mat[i - 1][j - 1]) + 1;
            }
        }
    }

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max < S[i][j])
            {
                max = S[i][j];
            }
        }
    }

    return max * max;
}

int main()
{
}