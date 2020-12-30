#include <iostream>
#include <algorithm>

using namespace std;

long long findSmallest(long long arr[], int n)
{
    //sort(arr, arr + n);

    if (arr[0] > 1)
    {
        return 1;
    }

    long long min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > min + 1)
            break;

        min += arr[i];
    }

    return min + 1;
}

int main()
{
    int n;
    cin >> n;
    long long *arr = new long long[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int min = findSmallest(arr, n);

    cout << min << "/n";

    delete[] arr;
}