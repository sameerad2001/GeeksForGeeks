#include <iostream>
#include <queue>

using namespace std;

void push_back_pb(deque<int> &dq, int x)
{
    dq.push_back(x);
}

void pop_back_ppb(deque<int> &dq)
{
    if (!dq.empty())
        dq.pop_back();

    else
        return;
}

int front_dq(deque<int> &dq)
{
    if (!dq.empty())
        return dq.front();
    else
        return -1;
}

void push_front_pf(deque<int> &dq, int x)
{
    dq.push_front(x);
}

int main()
{
}
