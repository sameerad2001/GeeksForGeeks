#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    // Reverse Rows
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j <= (matrix[0].size() - 1) / 2; j++)
        {
            swap(matrix[i][j], matrix[i][matrix[0].size() - 1 - j]);
        }
    }

    // Reverse Columns
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j <= (matrix[0].size() - 1) / 2; j++)
        {
            swap(matrix[j][i], matrix[matrix[0].size() - 1 - j][i]);
        }
    }
}

int main()
{
}