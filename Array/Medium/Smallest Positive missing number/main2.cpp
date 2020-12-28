#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int seperate(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
    return j;
}

int missingPositiveNumber(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i]) - 1 <= n && arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i]) - 1] = (-1) * arr[abs(arr[i]) - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            return i + 1;
        }
    }
    return n + 1;
}

int missingNumber(int arr[], int n)
{
    int shift = seperate(arr, n);

    return (missingPositiveNumber(arr + shift, n - shift));
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

    cout<<"The missing positive number is :"<<missingNumber(arr,n)<<endl;

    delete arr;
}