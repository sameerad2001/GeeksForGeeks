#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// https://www.youtube.com/watch?v=3QJzHqNAEXs
string removeKdigits(string s, int k)
{
    int n = s.size();
    stack<int> st;

    if (k == 0)
    {
        return s;
    }

    for (int i = 0; i < n; i++)
    {
        int number = s[i] - '0';
        while (!st.empty() && st.top() > number && k > 0)
        {
            st.pop();
            k--;
        }

        if (st.empty() && number == 0)
            continue;

        st.push(number);
    }

    while (!st.empty() && k--)
    {
        st.pop();
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top() + '0';
        st.pop();
    }

    if (res.empty())
        res += '0';

    reverse(res.begin(), res.end());
    return res;
}

int main() {}