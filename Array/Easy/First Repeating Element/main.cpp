#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void *x, const void *y)
{
    return (*(int *)x) - (*(int *)y);
}

int firstRepeated(int arr[], int n)
{
    //qsort(arr, n, sizeof(int), compare);
    //sort(arr, arr + n);

    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }

    int check[maxi + 1] = {0};
    //int *check = (int *)calloc(maxi + 1, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        check[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (check[arr[i]] > 1)
        {
            return i + 1;
        }
    }

    return -1;
}


int main()
{
}