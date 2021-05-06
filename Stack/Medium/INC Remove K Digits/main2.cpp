#include <iostream>
#include <string>
#include <stack>

using namespace std;

// https://www.youtube.com/watch?v=3QJzHqNAEXs

string removeKdigits(string S, int k)
{
    stack<char> st;
    int i = 0;

    for (i = 0; i < S.size(); i++)
    {
        while (k-- && !st.empty() && st.top() > S[i])
        {
            st.pop();
        }

        st.push(S[i]);
    }

    string partial_Res = "";
    while (!st.empty())
    {
        partial_Res += st.top();
        st.pop();
    }

    string res = "";
    i = partial_Res.size() - 1;
    for (i; i >= 0; i--) // Remove 0's from the front
    {
        if (partial_Res[i] != '0')
            break;
    }

    for (i; i >= 0; i--)
    {
        res += partial_Res[i];
    }

    if (res.size() == 0)
        return "0";

    return res;
}

int main()
{
}