#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        int smallestIndex = 0;

        for (int i = 1; i < n; i++)
        {

            if (arr[i] - arr[smallestIndex] > 0)
            {
                cout << n - i << " ";
                smallestIndex = i;
            }
        }

        cout << "\n";
        delete[] arr;
    }
}