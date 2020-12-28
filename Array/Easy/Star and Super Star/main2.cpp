#include <iostream>
#include <stack>

using namespace std;

// Not Workin
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        stack<int> s;
        int n;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1 || arr[i] > s.top())
            {
                s.push(arr[i]);
            }
        }

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;

        int max = -1;
        bool same = false;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                same = false;
            }

            else if (arr[i] == max)
                same = true;
        }

        if (same)
        {
            cout << -1;
        }
        else
        {
            cout << max;
        }

        cout << endl;
        delete[] arr;
    }
}