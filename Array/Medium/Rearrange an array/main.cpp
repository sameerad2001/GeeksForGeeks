#include <iostream>
#include <stdio.h>

using namespace std;

#define ll long long

void arrange(long long arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] += (arr[arr[i]] % n) * n;

        //numbers bw 0 to n-1 => remainder
        //Store OLD value(remainder) + new value(divisible by n)
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= n;
    }
}

int main()
{
    int n;
    cin >> n;

    ll *arr = new ll[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    arrange(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    free(arr);
}