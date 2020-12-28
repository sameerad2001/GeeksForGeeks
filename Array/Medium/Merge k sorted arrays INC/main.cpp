#include <iostream>
#include <stdio.h>

using namespace std;

int mergeKArrays(int arr[][101], int k)
{
    for (int i = 0; i < k*k; i++)
    {
            
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[101][101];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }

    mergeKArrays(arr, 4);

    delete arr;
}