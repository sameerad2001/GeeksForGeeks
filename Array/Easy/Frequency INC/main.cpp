#include <iostream>
#include <stdio.h>
#include <vector>

#define pb push_back

using namespace std;

void frequencycount(vector<int> &arr, int n)
{
    int *arrcount = (int *)calloc(n + 1, sizeof(int)); //initialize array elements to zero for counting

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != NULL)
            arrcount[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[i] = arrcount[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr[n];
    int a;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[i].pb(a);
    }

    // frequencycount( arr, n);

    // for (int i = arr.begin(); i != arr.end(); ++i)
    // {
    //     //cout << arr[i];
    // }
}