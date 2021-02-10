#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

vector<int> matrixDiagonally(int mat[MAX][MAX], int n)
{
    bool up = true;
    int i = 0, j = 0;

    vector<int> res;

    for (int k = 0; k < n * n;)
    {
        if (up)
        {
            for (; i >= 0 && j < n; i--, j++)
            {
                res.push_back(mat[i][j]);
                k++;
            }

            if (j == n)
                i += 2, j--;

            if (i <= 0 && j <= n - 1)
                i = 0;
        }
        else
        {
            for (; i < n && j >= 0; j--, i++)
            {
                res.push_back(mat[i][j]);
                k++;
            }

            if (i == n)
            {
                j += 2, i--;
            }
            if (j <= 0 && i <= n - 1)
            {
                j = 0;
            }
        }
        up = !up;
    }

    return res;
}

int main()
{
}
