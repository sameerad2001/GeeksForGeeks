#include <iostream>
#include <stdio.h>

using namespace std;

int compare(const void *x, const void *y)
{
    return *((int *)x) - *((int *)y);
}

int smallestPositive(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);

    int smallest = 1;
    for (int i = 0; i < n; i++)
    {
        if (smallest == arr[i])
            smallest++;
    }
    return smallest;
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

        int smallest = smallestPositive(arr, n);
        cout << smallest << endl;
    }
}