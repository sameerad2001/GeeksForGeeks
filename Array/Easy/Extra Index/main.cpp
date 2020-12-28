#include <iostream>

using namespace std;

int findExtra(int a[], int b[], int n)
{

    int f = 0;
    int l = n - 1;
    int mid = (f + l) / 2;

    if (a[l] != b[l])
        return l;

    if (a[f] != b[f])
        return f;

    while (f != l)
    {
        if (a[mid] != b[mid] && a[mid - 1] == b[mid - 1])
        {
            return mid;
        }

        else if (a[mid] < b[mid])
        {
            l = mid - 1;
            mid = (f + l) / 2;
        }

        else
        {
            f = mid + 1;
            mid = (f + l) / 2;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] != b[i])
    //     {
    //         return i;
    //     }
    // }

    return -1;
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

    delete[] arr;
}