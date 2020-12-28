#include <iostream>
#include <queue>

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

        deque<int> dQ;
        int i = 0;
        for (; i < k; i++)
        {
            if (arr[i] < 0)
            {
                dQ.push_back(i);
            }
        }

        for (i = k; i < n; i++)
        {
            if (!dQ.empty())
            {
                cout << arr[dQ.front()] << " ";
            }
            else
            {
                cout << 0 << " ";
            }

            while (!dQ.empty() && dQ.front() < i - k + 1)
            {
                dQ.pop_front();
            }

            if (arr[i] < 0)
            {
                dQ.push_back(i);
            }
        }

        if (!dQ.empty())
        {
            cout << arr[dQ.front()];
        }
        else
        {
            cout << 0;
        }

        cout << "\n";

        delete[] arr;
    }
}