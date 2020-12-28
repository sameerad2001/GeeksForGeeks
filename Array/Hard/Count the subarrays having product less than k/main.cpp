#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        long long product = 1;

        int count = 0;

        cin >> n >> k;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int length;

        for (int start = 0, end = 0; end < n; end++)
        {
            product *= arr[end];

            while (product > k && start <= end)
            {
                product /= arr[start];
                start++;
            }

            if (product < k)
            {
                length = end - start + 1;
                count += length;
            }
        }

        cout << count << endl;

        delete[] arr;
        count = 0;
        k = 0;
    }
}