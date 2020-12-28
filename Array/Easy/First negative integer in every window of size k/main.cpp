#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

        int k;
        cin >> k;

        bool flag;

        for (int i = 0; i < (n - k + 1); i++)
        {
            flag = false;

            for (int j = 0; j < k; j++)
            {
                if (arr[i + j] < 0)
                {
                    cout << arr[i + j] << " ";
                    flag = true;
                    break;
                }
            }

            if (!flag)
                cout << "0"
                     << " ";
        }

        cout << "\n";

        delete[] arr;
    }
}