#include <iostream>
#include <stack>

using namespace std;

// Submitted but not the correct solution because it uses extra space
void clonestack(stack<int> &st, stack<int> &cloned)
{
    if (st.empty())
        return;

    int item = st.top();
    st.pop();

    clonestack(st, cloned);

    cloned.push(item);
}

int main()
{
    stack<int> st, cloned;

    for (int i = 1; i < 6; i++)
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