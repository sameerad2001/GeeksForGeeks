#include <iostream>
#include <stack>
#include <string>

using namespace std;

int pres(char operator_)
{
    int res;

    switch (operator_)
    {
    case '+':
    case '-':
        res = 1;
        break;

    case '*':
    case '/':
        res = 2;
        break;

    case '^':
        res = 3;
        break;

    case '(':
        res = 4;
        break;
    }

    return res;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && pres(st.top()) >= pres(s[i]))
            {
                res += st.top();
                st.pop();
            }
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
    cout << infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
}