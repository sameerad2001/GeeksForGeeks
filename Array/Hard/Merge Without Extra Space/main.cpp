// Stupid Approach that does not work

#include <iostream>
#include <algorithm>

using namespace std;

//#define largest 1000000 //10^6

void merge(int arr1[], int arr2[], int n, int m)
{

    long largest = 1000000;
    //bool flag = true;
    bool f1 = true;
    int index = 0;
    int i = 0, j = 0;

    if (f1)
    {
        while (i < n && j < m && f1)
        {
            if (arr1[i] % largest < arr2[j] % largest)
            {
                arr1[index] += arr1[i] * largest;
                i++;
                index++;
            }

            else
            {
                arr1[index] += arr2[j] * largest;
                j++;
                index++;
            }

            if (index == n)
            {
                f1 = false;
                index = 0;
            }
        }

        if (index == n)
        {
            f1 = false;
            index = 0;
        }

        while (i < n && f1)
        {
            arr1[index] += arr1[i] * largest;
            i++;
            index++;
        }

        if (index == n)
        {
            f1 = false;
            index = 0;
        }

        while (j < m && f1)
        {

            arr1[index] += arr2[j] * largest;
            j++;
            index++;
        }

        if (index == n)
        {
            f1 = false;
            index = 0;
        }
    }

    if (!f1)
    {
        while (i < n && j < m)
        {
            if (arr1[i] % largest < arr2[j] % largest)
            {
                arr2[index] += arr1[i] * largest;
                i++;
                index++;
            }

            else
            {
                arr2[index] += arr2[j] * largest;
                j++;
                index++;
            }
        }

        while (i < n)
        {
            arr2[index] += arr1[i] * largest;
            i++;
            index++;
        }

        while (j < m)
        {

            arr2[index] += arr2[j] * largest;
            j++;
            index++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr1[i] /= largest;
    }

    for (int i = 0; i < m; i++)
    {
        arr2[i] /= largest;
    }
}

int compare(const void *x, const void *y)
{
    return (*(int *)x) - (*(int *)y);
}

// int main()
// {
//     int n, m;
//     // cin >> n >> m;
//     n = m = 3;

//     int *arr1 = new int[n];
//     int *arr2 = new int[m];

//     arr1[0] = 10;
//     arr1[1] = 6;
//     arr1[2] = 9;
//     arr2[0] = 7;
//     arr2[1] = 5;
//     arr2[2] = 3;

//     // for (int i = 0; i < n; i++)
//     // {
//     //     cin >> arr1[i];
//     // }

//     // for (int i = 0; i < m; i++)
//     // {
//     //     cin >> arr2[i];
//     // }

//     qsort(arr1, n, sizeof(int), compare);
//     qsort(arr2, m, sizeof(int), compare);

//     merge(arr1, arr2, n, m);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr1[i] << " ";
//     }

//     cout << endl;
//     for (int i = 0; i < m; i++)
//     {
//         cout << arr2[i] << " ";
//     }
// }