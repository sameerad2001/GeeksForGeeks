
#include <iostream>
#include <stdio.h>

using namespace std;

int sumElement(int arr[], int n);

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = sumElement(arr, n);

    cout << sum << endl;

    free(arr);
}

int sumElement(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}