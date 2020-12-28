#include <iostream>
#include <stdio.h>
#include <algorithm>

//WHY NOT WORK :-( ????
// #define max(a, b) a >= b ? a : b
// #define min(a, b) a <= b ? a : b

using namespace std;

int calculateWater(int arr[], int n)
{
    //*************Left
    int *left = new int[n];
    left[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }

    //*************Right
    int *right = new int[n];
    right[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }

    //**********************count*****************************
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += min(left[i], right[i]) - arr[i];
    }

    return count;
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

        int count = calculateWater(arr, n);

        cout << count << endl;
    }
}