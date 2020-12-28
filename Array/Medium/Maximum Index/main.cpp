#include <iostream>
#include <algorithm>

using namespace std;

int maxIndexDiff(int arr[], int n)
{
    int *leftMin = new int[n];
    leftMin[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[leftMin[i - 1]] < arr[i])
        {
            leftMin[i] = leftMin[i - 1];
        }
        else
        {
            leftMin[i] = i;
        }
    }

    int *rightMax = new int[n];
    rightMax[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[rightMax[i + 1]] > arr[i])
        {
            rightMax[i] = rightMax[i + 1];
        }
        else
        {
            rightMax[i] = i;
        }
    }

    int maxi = 0;
    for (int i = 1, j = n - 1; i < n && j >= 0; i++, j--)
    {
        if (arr[leftMin[i]] < arr[rightMax[j]])
        {
            if (maxi < rightMax[i] - leftMin[i])
                maxi = rightMax[i] - leftMin[i];
        }
    }

    delete[] rightMax;
    delete[] leftMin;

    return maxi;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i, n; i++)
    {
        cin >> arr[i];
    }

    delete[] arr;
}