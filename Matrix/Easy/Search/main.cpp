#include <iostream>
#include <vector>

using namespace std;

bool search(vector<vector<int>> mat, int n, int m, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == x)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
}