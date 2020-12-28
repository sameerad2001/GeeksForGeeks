#include <iostream>
#include <stdio.h>

using namespace std;

void sort012(int a[], int n)
{
    int count[3] = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        switch (a[i])
        {
        case 0:
            count[0]++;
            break;

        case 1:
            count[1]++;
            break;

        case 2:
            count[2]++;
            break;

        default:
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        while (count[0]--)
        {
            a[i] = 0;
            i++;
        }
        while (count[1]--)
        {
            a[i] = 1;
            i++;
        }
        while (count[2]--)
        {
            a[i] = 2;
            i++;
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

    sort012(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    free(arr);
}