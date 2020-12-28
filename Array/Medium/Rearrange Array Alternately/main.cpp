#include <iostream>

using namespace std;

void rearrange(long long *arr, int n)
{
    int mini = 0, maxi = n - 1;
    int maxElem = arr[n - 1] + 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i] + (arr[maxi] % maxElem) * maxElem;
            maxi--;
        }

        else
        {
            arr[i] = arr[i] - (arr[mini] % maxElem) * maxElem;
            mini--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / n;
    }
}

int main()
{
    int n;
    cin >> n;

    long long *arr = new long long[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    delete arr;
}