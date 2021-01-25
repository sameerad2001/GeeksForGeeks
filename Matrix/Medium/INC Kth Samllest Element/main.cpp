#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int i, j, count;
    i = j = count = 0;
    while (i < n && j < n)
    {
        count++;
        if (count == k)
        {
            return mat[i][j];
        }
        else if (mat[i + 1][j] < mat[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    while (i < n)
    {
        count++;
        if (count == k)
        {
            return mat[i][j];
        }
        i++;
    }

    while (j < n)
    {
        count++;
        if (count == k)
        {
            return mat[i][j];
        }
        j++;
    }

    return -1;
}

int main()
{
}