#include <iostream>
#include <stdio.h>

#define maximum(a, b) a > b ? a : b

using namespace std;

int longestSubarray(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        while (arr[i] >= 0 && i < n)
        {
            temp++;
            i++;
        }
        count = maximum(count, temp);
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

        //int max = longestSubarray(arr, n);

        cout << longestSubarray(arr, n) << endl;

        free(arr);
    }
}