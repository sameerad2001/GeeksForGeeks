#include <iostream>
#include <algorithm>

using namespace std;

int median(int arr[], int n, int x)
{
    sort(arr, arr + n);

    int i;
    for (i = 0; arr[(n - 1) / 2 != x]; i++)
    {
        arr[n++] = x;
        sort(arr, arr + n);
    }

    return i;
}

int main()
{
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        int n, x;
        n = 6;
        x = 30;
        //cin >> n >> x;

        // int *arr = new int[n * 2];

        int arr[12] = {10, 20, 30, 100, 150, 200};
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> arr[n];
        // }

        cout << median(arr, n, x) << endl;

        delete[] arr;
    }
}