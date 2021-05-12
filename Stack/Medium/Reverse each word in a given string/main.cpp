#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseWords(string s)
{
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }

            res += '.';
        }
        else
        {
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
}