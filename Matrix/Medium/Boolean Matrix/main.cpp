#include <iostream >
#include <vector>

using namespace std;

// Question is wrong?????????

void booleanMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int table_x[m] = {0};
    int table_y[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                table_x[i] = 1;
                table_y[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (table_x[j] || table_y[i])
            {
                matrix[i][j] = 1;
            }
        }
    }
}

void booleanMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool rowFlag, colmFlag;
    rowFlag = colmFlag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][0] = 1;
                matrix[0][j] = 1;

                if (i == 0)
                    rowFlag = true;

                if (j == 0)
                    colmFlag = true;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 1 || matrix[0][j] == 1)
                matrix[i][j] = 1;
        }
    }

    if (rowFlag)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 1;
        }
    }
    if (colmFlag)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 1;
        }
    }
}

int main()
{
}