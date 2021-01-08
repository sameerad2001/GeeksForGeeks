#include <iostream>
#include <algorithm>

using namespace std;

// Not Working

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

        bool flag = true;

        int j = 0;
        while (flag)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] -= arr[j];
            }
            j++;

            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > 0)
                {
                    count++;
                }
            }

            if (count == 0)
            {
                flag = false;
                break;
            }

            cout << count << " ";
        }

        cout << "\n";
        delete[] arr;
    }
}