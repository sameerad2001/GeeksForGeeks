#include <iostream>
#include <stdio.h>

using namespace std;

void convertToWave(int *arr, int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            arr[i] = arr[i] + arr[i + 1];
            arr[i + 1] = arr[i] - arr[i + 1];
            arr[i] = arr[i] - arr[i + 1];
        }
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
    convertToWave(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }

    free(arr);
}