#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int minimumSwap(int arr[], int n, int k)
{
    int minimum = NULL, bad = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            count++;
    }

    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
            bad++;
    }
    minimum = bad;

    int i = 0, j = count;

    while (j < n)
    {
        if (arr[i] > k)
            bad--;

        if (arr[j] > k)
            bad++;

        minimum = min(bad, minimum);
        i++;
        j++;
    }

    return minimum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cin >> k;

        int minimum = minimumSwap(arr, n, k);

        cout << minimum << endl;

        delete arr;
    }
    return 0;
}