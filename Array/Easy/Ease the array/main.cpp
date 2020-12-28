#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void easr(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            count++;
        }

        if (arr[i] == arr[i + 1] && arr[i] != 0)
        {
            arr[i] *= 2;
            arr[i + 1] = 0;
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            arr[j] = arr[i];
            j++;
        }
    }

    for (int i = count; i < n; i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        easr(arr, n);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        delete arr;

        cout << endl;
    }
    return 0;
}