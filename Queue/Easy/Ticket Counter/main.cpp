#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        deque<int> q;

        for (int i = 1; i <= n; i++)
        {
            q.push_back(i);
        }

        int count = 1;
        bool alternate = true;
        int res;
        while (!q.empty())
        {
            int temp;
            if (alternate)
            {
                temp = q.front();
                q.pop_front();
                count++;
            }
            else
            {
                temp = q.back();
                q.pop_back();
                count--;
            }

            if (count == 0)
            {
                alternate = true;
                count = 1;
            }
            if (count == k + 1)
            {
                alternate = false;
                count = k;
            }

            if (q.empty())
                res = temp;
        }

        cout << res << "\n";
    }
}