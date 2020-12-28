#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

//********************* Only for SORTED arrays

// pivot ====== MAXIMUM
int findPivot(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[(i + 1) % n])
            return i;
    }
}

int max_sum(int arr[], int n)
{
    int maximum = 0;
    int &pivot = maximum;

    pivot = findPivot(arr, n); //pivot====largest element

    //  OR

    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i] > arr[maximum])
    //         maximum = i;
    // }

    int sum = 0;

    int diff = n - maximum - 1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i] * ((i + diff) % n);
    }
    /*
    for (int i = 0; i < n; i++)
    {
        if (i <= maximum)
        {
            sum += arr[i] * (n - maximum - 1 - i);
        }
        else
        {
            sum += arr[i] * (i - maximum - 1);
        }
    }
   */
    return sum;
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

    delete arr;
}