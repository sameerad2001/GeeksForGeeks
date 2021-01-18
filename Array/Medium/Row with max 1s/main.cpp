#include <iostream>
#include <vector>

using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int index = -1;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                count++;
        }

        if (count > max)
        {
            index = i;
            max = count;
        }
    }

    return index;
}

int main() {}