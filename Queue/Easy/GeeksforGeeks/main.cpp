#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            int number;
            // cin >> number;
            number = i + 1;
            q.push(number);
        }

        while (q.size() != 1)
        {
            int temp = q.front();
            q.pop();
            q.pop();
            q.push(temp);
        }

        cout << q.front() << "\n";
    }
}