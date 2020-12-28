#include <iostream>
#include <stdio.h>

using namespace std;

void swapElements(int arr[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    swapElements(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    free(arr);
}