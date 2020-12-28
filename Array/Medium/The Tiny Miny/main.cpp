#include <iostream>
#include <math.h>

using namespace std;

int compare(const void *x, const void *y)
{
    return (*(int *)x) - (*(int *)y);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, n;
        cin >> a >> n;

        int *arr = new int[n];

        int digitCount = 0;

        for (int i = 0; i < n; i++)
        {
            arr[i] = pow(a, i + 1);

            int temp = arr[i];
            while (temp != 0)
            {
                if (temp % 10 != 0)
                    digitCount++;

                temp /= 10;
            }
        }

        int *tiny = new int[digitCount];
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = arr[i];
            while (temp != 0)
            {
                if (temp % 10 != 0)
                {
                    tiny[k] = temp % 10;
                    k++;
                }
                temp /= 10;
            }
        }

        qsort(tiny, digitCount, sizeof(int), compare);

        for (int i = 0; i < digitCount; i++)
        {
            cout << tiny[i];
        }

        cout << endl;
        delete[] tiny;
        delete[] arr;
    }
}