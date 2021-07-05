#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> rotation(int n)
{
    vector<int> res;
    deque<int> dq;

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

    for (int i = 0; i < n; i++)
    {
        res.push_back(dq.front());
        dq.pop_front();
    }

    return res;
}

int main()
{
}