#include <iostream>

using namespace std;

int median(int arr[], int n, int x)
{
    int equal, greater, lower;
    equal = greater = lower = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            equal++;

        else if (arr[i] > x)
            greater++;

        else
            lower++;
    }

    if (greater > lower)
    {
        return (greater - lower) - equal;
    }

    else if (lower > greater)
    {
        return lower - greater + 1 - equal;
    }

    else
    {
        return 1 - equal;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << median(arr, n, x) << endl;

        delete[] arr;
    }
}