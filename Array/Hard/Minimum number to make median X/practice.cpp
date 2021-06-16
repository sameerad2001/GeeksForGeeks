#include <iostream>
#include <algorithm>

using namespace std;

int median(int arr[], int n, int x)
{
    sort(arr, arr + n);

    int i;
    for (i = 0; arr[(n - 1) / 2] != x; i++)
    {
        arr[n++] = x;
        sort(arr, arr + n);
    }

    return i;
}

int main()
{

    int n, x;
    n = 3;
    x = 4;
    int arr[100] = {1, 2, 3};

    cout << median(arr, n, x) << endl;
}