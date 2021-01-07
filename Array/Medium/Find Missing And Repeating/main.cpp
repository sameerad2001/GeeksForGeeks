#include <iostream>
#include <algorithm>

using namespace std;

int *findTwoElement(int arr[], int n)
{
    int *res = new int[2];
    sort(arr, arr + n);

    int sum, offset = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        sum = i + offset;

        if (arr[i] != sum + 1 && arr[i] != arr[i - 1])
        {
            res[1] = sum + 1;
            flag = true;
            break;
        }
        else if (arr[i] == arr[i - 1])
        {
            offset -= 1;
        }
    }

    if (!flag)
    {
        res[1] = n;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            res[0] = arr[i];
            break;
        }
    }

    return res;
}

int main()
{
    int n;
    n = 14;

    int arr[100] = {12, 7, 5, 1, 13, 1, 10, 8, 11, 9, 2, 4, 3, 6};

    int *res = findTwoElement(arr, n);

    cout << res[0] << " " << res[1];
}