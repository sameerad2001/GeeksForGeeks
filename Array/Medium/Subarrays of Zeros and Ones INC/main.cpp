#include <iostream>
#include <stdio.h>

using namespace std;

#define lld long long int

lld countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    lld zero, one, count;
    zero = one = count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
        else
            one++;

        if (one == zero)
            count++;
    }
    count += zero - one;
    return count;
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