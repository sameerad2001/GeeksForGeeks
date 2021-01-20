#include <iostream>
#include <vector>

using namespace std;

int FindCoverage(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int res = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < m - 1)
            {
                if (!matrix[i][j] && matrix[i + 1][j])
                    res++;
            }

            if (j < n - 1)
            {
                if (!matrix[i][j] && matrix[i][j + 1])
                    res++;
            }

            if (i > 0)
            {
                if (!matrix[i][j] && matrix[i - 1][j])
                    res++;
            }

            if (j > 0)
            {
                if (!matrix[i][j] && matrix[i][j - 1])
                    res++;
            }
        }
    }

    return res;
}

int main()
{
}