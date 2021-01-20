#include <iostream>
#include <vector>

using namespace std;

int FindCoverage(vector<vector<int>> &matrix)
{
    int ans = 0;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
                continue;
            if (i - 1 >= 0 and matrix[i - 1][j])
                ans++;
            if (i + 1 < n and matrix[i + 1][j])
                ans++;
            if (j - 1 >= 0 and matrix[i][j - 1])
                ans++;
            if (j + 1 < m and matrix[i][j + 1])
                ans++;
        }
    }

    return ans;
}

int main() {}