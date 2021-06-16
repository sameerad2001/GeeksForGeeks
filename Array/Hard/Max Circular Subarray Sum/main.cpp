#include <iostream>
#include <algorithm>

using namespace std;

// ___________________Check Second File for a neater implementation____________________

int kadane(int arr[], int n)
{
    int temp, maximum;
    temp = maximum = 0;

    int i = 0;
    //int resetPos = n - 1;

    while (i < n)
    {
        temp += arr[i];

        if (maximum < temp)
        {
            maximum = temp;
        }

        if (temp < 0)
        {
            temp = 0;
        }

        i++;
    }

    return maximum;
}

int circularSubarraySum(int arr[], int n)
{
    int maxKadane, maxWrap;
    int negCount = 0;

    maxKadane = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            break;

        if (maxKadane < arr[i])
        {
            maxKadane = arr[i];
        }

        negCount++;
    }

    if (negCount == n)
    {
        return maxKadane;
    }

    //int maxKadane, maxWrap;

    maxKadane = kadane(arr, n);

    int totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];

        arr[i] *= -1; //Find the Sum of non contributing
    }

    maxWrap = totalSum + kadane(arr, n);

    return max(maxKadane, maxWrap);
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

    cout << "Max Sum is: " << circularSubarraySum(arr, n) << endl;

    delete[] arr;
}