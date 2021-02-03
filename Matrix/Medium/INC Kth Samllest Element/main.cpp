#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10000

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int *arr = new int[2 * n];

    int index = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[index++] = mat[i][j];
        }
    }

    sort(arr, arr + 2 * n);

    return arr[k - 1];

    delete[] arr;
}

int main()
{
}