#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int peakElement(int arr[], int n)
{
    int first = 0, last = n;
    int mid = (first + last) / 2;

    while (first != last)
    {
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[mid - 1])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }
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

    return 0;
}