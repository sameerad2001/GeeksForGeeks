#include <iostream>
#include <stdio.h>

using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int max;
    int temp;
    max = temp = 0;

    for (int i = 0; i < n; i++)
    {
        temp += arr[i];

        if (max < temp) // (....|| max <= 0)
            max = temp;

        if (temp < 0)
            temp = 0;
    }

    return max;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int max = maxSubarraySum(arr, n);

        cout << max << endl;

        free(arr);
    }
}