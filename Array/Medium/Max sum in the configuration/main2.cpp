#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int max_sum(int arr[], int n)
{
    int sumElement = 0;

    for (int i = 0; i < n; i++)
    {
        sumElement += arr[i];
    }

    int currentSum = 0;
    for (int i = 0; i < n; i++)
        currentSum += (arr[i] * i);

    int nextSum = 0;
    int maximum = currentSum;

    for (int j = 1; j < n; j++)
    {
        nextSum = currentSum - (sumElement - arr[j - 1]) + arr[j - 1] * (n - 1);

        maximum = max(maximum, nextSum);

        currentSum = nextSum;
    }

    return maximum;
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