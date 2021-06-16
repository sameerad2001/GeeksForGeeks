#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int maxAbsolute(int arr[], int n)
{
    int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // a[i] + i
        max1 = max(max1, arr[i] + i);
        min1 = min(min1, arr[i] + i);

        // a[i] - i
        max2 = max(max2, arr[i] - i);
        min2 = min(min2, arr[i] - i);
    }

    int ans = max(max1 - min1, max2 - min2);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

        cout << maxAbsolute(arr, n) << endl;

        delete[] arr;
    }
}