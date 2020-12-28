#include <iostream>
#include <stdio.h>

#define maximum(a, b) a > b ? a : b

using namespace std;

int findMaximum(int arr[], int n);

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = findMaximum(arr, n);

    cout << max;

    free(arr);
}

int findMaximum(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            break;
        max = maximum(max, arr[i]);
    }

    return max;
}
