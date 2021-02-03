#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int median(vector<vector<int>> &mat, int r, int c)
{
    int maximum = INT_MIN;
    int minimum = INT_MAX;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            maximum = maximum > mat[i][j] ? maximum : mat[i][j];
            minimum = minimum < mat[i][j] ? minimum : mat[i][j];
        }
    }

    int required = (1 + r * c) / 2;

    while (maximum > minimum)
    {
        int middle = (maximum + minimum) / 2;
        int count = 0;

        // Number of Elements <= middle in each row
        for (int i = 0; i < r; i++)
        {
            // upper_bound returns iterator to first element greater than given value
            // eg 1 2 3 4 5 6 7 8 ; Search 6
            // Return 7
            // Number of Elements in between => 7 - 1 = 6
            count += upper_bound(mat[i].begin(), mat[i].end(), middle) - mat[i].begin();
        }

        if (count < required)
        {
            minimum = middle + 1;
        }
        else
        {
            maximum = middle - 1;
        }
    }

    return minimum;
}

int main()
{
}