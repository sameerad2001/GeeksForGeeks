#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &mat)
{

    // Tarnspose
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = i; j < mat[0].size(); j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse Columns
    for (int i = 0; i < mat[0].size(); i++)
    {
        for (int j = 0; j <= (mat[0].size() - 1) / 2; j++)
        {
            swap(mat[j][i], mat[mat[0].size() - 1 - j][i]);
        }
    }
}

int main()
{
}