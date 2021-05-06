#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    queue<int> res;
    while (!st.empty())
    {
        res.push(st.top());
        st.pop();
    }

    while (!q.empty())
    {
        res.push(q.front());
        q.pop();
    }

    return res;
}

int main()
{
}