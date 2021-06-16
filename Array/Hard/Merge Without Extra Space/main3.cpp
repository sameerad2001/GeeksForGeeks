// PRACTICE
#include <iostream>
#include <algorithm>

#define combine(operand, suffix) operand##suffix

using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int pointer1 = n - 1, pointer2 = 0;

    while (pointer1 >= 0 && pointer2 < m)
    {
        if (arr1[pointer1] <= arr2[pointer2])
            break;

        swap(arr1[pointer1], arr2[pointer2]);
        pointer1--;
        pointer2++;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{

    int arr1[4] = {1, 3, 7, 8};
    int arr2[4] = {2, 4, 5, 6};

    merge(arr1, arr2, 4, 4);

    for (int i = 0; i < 4; i++)
        cout << combine(arr, 1)[i] << " ";

    for (int i = 0; i < 4; i++)
        cout << combine(arr, 2)[i] << " ";
}