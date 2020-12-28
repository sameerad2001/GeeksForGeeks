#include <iostream>
#include <algorithm>

using namespace std;

int maxIndexDiff(int arr[], int n)
{

    int *leftMin = new int[n];
    leftMin[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMin[i] = min(leftMin[i - 1], arr[i]);
    }

    int *rightMax = new int[n];
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    int i = 0, j = 0, maxi = -1;

    while (i < n && j < n)
    {
        if (leftMin[i] < rightMax[j])
        {
            maxi = max(maxi, j - i);
            j++;
        }
        else
        {
            i--;
        }
    }

    delete[] leftMin;
    delete[] rightMax;

    return maxi;
}