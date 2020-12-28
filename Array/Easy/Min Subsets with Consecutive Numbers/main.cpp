#include <iostream>
#include <stdio.h>

using namespace std;

int compare(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int numofsubset(int *arr, int n)
{
    int min = 0;

    for (int i = 0; i < n; i++) // Sorted array [1,2,3][6][90,91][9,10,11,12][30][60] Min = 6
    {
        if (arr[i] + 1 != arr[i + 1]) //Not in the same set => differnt set
            min++;
    }

    return min;
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

        qsort(arr, n, sizeof(int), compare);

        int min = numofsubset(arr, n);

        cout << min << endl;

        free(arr);
    }
}