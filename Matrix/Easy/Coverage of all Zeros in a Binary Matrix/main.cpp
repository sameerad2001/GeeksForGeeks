#include <iostream>
#include <vector>

using namespace std;

int FindCoverage(vector<vector<int>> &matrix)
{
    int res = 0;
    bool isOne;

    for (int i = 0; i < matrix.size(); i++)
    {
        isOne = false;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                isOne = true;
            }
            else if (isOne)
            {
                res++;
            }
        }

        isOne = false;
        for (int j = matrix[0].size() - 1; j >= 0; j--)
        {
            if (matrix[i][j] == 1)
            {
                isOne = true;
            }
            else if (isOne)
            {
                res++;
            }
        }
    }

    for (int j = 0; j < matrix[0].size(); j++)
    {
        isOne = false;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][j] == 1)
            {
                isOne = true;
            }
            else if (isOne)
            {
                res++;
            }
        }

        isOne = false;
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            if (matrix[i][j] == 1)
            {
                isOne = true;
            }
            else if (isOne)
            {
                res++;
            }
        }
    }

    return res;
}

int main()
{
}