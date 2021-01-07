#include <iostream>

using namespace std;

string equilibrium(int arr[], int n)
{
    int left[n] = {0};
    int right[n] = {0};

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] + arr[i];
    }

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (right[i] - arr[i] == left[i] - arr[i])
        {
            return "YES";
        }
    }

    return "NO";
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

    delete[] arr;
}