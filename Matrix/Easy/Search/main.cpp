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

// Row Column Sorted matrix
// Efficient
bool search(vector<vector<int>> mat, int n, int m, int x)
{
    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {
        if (mat[i][j] == x)
        {
            return true;
        }
        else if (x > mat[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return false;
}

int main()
{
}