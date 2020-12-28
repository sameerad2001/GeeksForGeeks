#include <iostream>
#include <stdio.h>

using namespace std;

int transitionPoint(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            return i;
    }

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

    int transition = transitionPoint(arr, n);

    cout << transition << endl;

    free(arr);
}