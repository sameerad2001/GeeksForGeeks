#include <iostream>
#include <stack>

using namespace std;

// Reverse source stack by
// picking the top value and pushing the rest
// of the values into the dest stack
// put the top val back into the source stack and bring
// all vals from the dest to the source
void clonestack(stack<int> &st, stack<int> &cloned)
{
    int count = 0;

    while (count != st.size())
    {
        int top_val = st.top();
        st.pop();

        while (st.size() != count)
        {
            cloned.push(st.top());
            st.pop();
        }

        st.push(top_val);

        while (!cloned.empty())
        {
            st.push(cloned.top());
            cloned.pop();
        }

        count++;
    }

    while (!st.empty())
    {
        cloned.push(st.top());
        st.pop();
    }
}

int main()
{
    stack<int> st, cloned;

    for (int i = 1; i < 3; i++)
    {
        st.push(i);
    }

    clonestack(st, cloned);

    while (!cloned.empty())
    {
        cout << cloned.top() << " ";
        cloned.pop();
    }
}