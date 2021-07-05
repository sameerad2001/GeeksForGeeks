#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> rotation(int n)
{
    deque<int> dq;
    vector<int> v;

    dq.push_front(n);

    for (int i = 1; i < n; i++)
    {
        dq.push_front(n - i);

        for (int j = 0; j < n - i; j++)
        {
            int back = dq.back();
            dq.pop_back();
            dq.push_front(back);
        }
    }

    while (!dq.empty())
    {
        v.push_back(dq.front());
        dq.pop_front();
    }

    return v;
}

int main()
{
    vector<int> res = rotation(5);

    for (int i = 0; i < res.size(); i++)
        cout << res[i];
}