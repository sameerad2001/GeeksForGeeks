#include <iostream>
#include <string>
#include <stack>

using namespace std;

int findMaxLen(string s)
{
    stack<int> st;
    st.push(-1);

    int res = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            st.pop();

            if (!st.empty())
            {
                int len = i - st.top();
                res = res > len ? res : len;
            }
            else
            {
                st.push(i);
            }
        }
    }

    return res;
}

int main()
{
}