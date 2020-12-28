#include <iostream>
#include <stdio.h>

using namespace std;

int countZeroes(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            return (n - i);
        }
        i++;
    }
    return 0;
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
    int count = countZeroes(arr, n);

    cout << count << endl;

    free(arr);
}